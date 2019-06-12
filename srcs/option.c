#include "ft_printf.h"

static int		checkoptionerror(t_env *env)
{
	if (INDIC)
	{
		if ((ft_strsearch(INDIC, '+') == 1 && ft_strsearch(INDIC, ' ') == 1 && TYPE != 'd') ||
			(ft_strsearch(INDIC, '-') == 1 && ft_strsearch(INDIC, '0') == 1 && TYPE != 'd'))
		{
			ft_putstr(env->str);
			exit(0);
		}
		return (1);
	}
	else
		return (0);
}

static int		applydoubleoption(t_env *env)
{
	if (ft_strsearch(INDIC, '+') == 1 && ft_strsearch(INDIC, '-') == 1)
	{
		oposineg(env, WIDTH);
		return (1);
	}
	if (ft_strsearch(INDIC, '+') == 1 && ft_strsearch(INDIC, '0') == 1)
	{
		oposizero(env, WIDTH);
		return (1);
	}
	if (ft_strsearch(INDIC, '-') == 1 && ft_strsearch(INDIC, ' ') == 1)
	{
		onegspace(env, WIDTH);
		return (1);
	}
	if (ft_strsearch(INDIC, '0') == 1 && ft_strsearch(INDIC, ' ') == 1)
	{
		ozerospace(env, WIDTH);
		return (1);
	}
	return (0);
}

static void		applyoption(t_env *env)
{
	if (ft_strsearch(INDIC, '+') == 1)
	{
		if (RESULT[0] != '-')
			oposi(env, WIDTH);
	}
	else if (ft_strsearch(INDIC, '#') == 1)
	{
		if (RESULT[0] != '0' && RESULT[1])
			ohash(env, WIDTH);
	}
	else if (ft_strsearch(INDIC, '0') == 1)
		olzero(env, WIDTH);
	else if (ft_strsearch(INDIC, ' ') == 1)
	{
		if (RESULT[0] != '-')
			ospace(env, WIDTH);
	}
	else if (ft_strsearch(INDIC, '-') == 1)
		olalign(env, WIDTH);
}

void			option(t_env *env)
{
	while (env->form)
	{
		if (TYPE != 'c' && TYPE != 's' && TYPE != '%' && TYPE != 'p')
		{
			if (checkoptionerror(env) == 1 && PRECI <= (int)ft_strlen(RESULT))
			{
				if (applydoubleoption(env) == 0)
					applyoption(env);
			}
		}
		if (!NEXT)
			break ;
		env->form = NEXT;
	}
}
