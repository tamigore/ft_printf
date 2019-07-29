#include "ft_printf.h"

static int		checkoptionerror(t_env *env)
{
	if (INDIC[0] == '\0' || !INDIC)
		return (0);
	return (1);
}

static void		applyoption_str(t_env *env, int x)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (RESULT)
	{
		if (ft_strsearch(INDIC, '-') == 1 && x == 1)
		{
			while (RESULT[i] == ' ')
				i++;
			if (RESULT[i] != '\0')
			{
				while(RESULT[i])
					ft_swap(&RESULT[i++],&RESULT[j++]);
			}
		}
		if (ft_strsearch(INDIC, '0') == 1 && x == 2)
		{
			while (RESULT[i] == ' ')
				RESULT[i++] = '0';
		}
	}
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
	if (ft_strsearch(INDIC, '+') == 1 && TYPE != 'u')
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
	else if (ft_strsearch(INDIC, ' ') == 1 && TYPE != 'u')
	{
		if (RESULT[0] != '-')
			ospace(env, WIDTH);
	}
	else if (ft_strsearch(INDIC, '-') == 1)
		olalign(env, WIDTH);
}

void			option(t_env *env, int x)
{
	while (env->form)
	{
		if (ft_strsearch("csp%", TYPE) == 0 && x == 1)
		{
			if (checkoptionerror(env) == 1 && PRECI <= (int)ft_strlen(RESULT))
			{
				if (applydoubleoption(env) == 0)
					applyoption(env);
			}
		}
		if (ft_strsearch("csp%", TYPE) == 1 && x == 2)
		{
			if (checkoptionerror(env) == 1 && PRECI <= (int)ft_strlen(RESULT))
				applyoption_str(env, 1);
		}
		SIZE = (int)ft_strlen(RESULT);
		if (!NEXT)
			break ;
		env->form = NEXT;
	}
}
