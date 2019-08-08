/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 11:11:54 by tamigore          #+#    #+#             */
/*   Updated: 2019/08/08 16:53:38 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		checkoptionerror(t_env *env)
{
	if (INDIC[0] == '\0' || !INDIC)
		return (0);
	return (1);
}

static void		applyoption_str(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_strsearch(INDIC, '-') == 1)
	{
		while (RES[i] == ' ')
			i++;
		while (RES[i])
			ft_swap(&RES[i++], &RES[j++]);
	}
	if (ft_strsearch(INDIC, '0') == 1)
	{
		while (RES[i] == ' ')
			RES[i++] = '0';
	}
}

static int		applydoubleoption(t_env *env)
{
	if (ft_strsearch(INDIC, '+') == 1 && ft_strsearch(INDIC, '-') == 1)
	{
		if (!oposineg(env, WIDTH))
			return (-1);
	}
	else if (ft_strsearch(INDIC, '+') == 1 && ft_strsearch(INDIC, '0') == 1)
	{
		if (!oposizero(env, WIDTH))
			return (-1);
	}
	else if (ft_strsearch(INDIC, '-') == 1 && ft_strsearch(INDIC, ' ') == 1)
	{
		if (!onegspace(env, WIDTH))
			return (-1);
	}
	else if (ft_strsearch(INDIC, '0') == 1 && ft_strsearch(INDIC, ' ') == 1)
	{
		if (!ozerospace(env, WIDTH))
			return (-1);
	}
	else
		return (0);
	return (1);
}

static int		applyoption(t_env *env)
{
	if (ft_strsearch(INDIC, '+') == 1 && TYPE != 'u')
	{
		if (RES[0] != '-')
			if (!oposi(env, WIDTH))
				return (0);
	}
	else if (ft_strsearch(INDIC, '#') == 1)
	{
		if (RES[0] != '0')
			if (!ohash(env, WIDTH))
				return (0);
	}
	else if (ft_strsearch(INDIC, '0') == 1)
	{
		if (!olzero(env, WIDTH))
			return (0);
	}
	else if (ft_strsearch(INDIC, ' ') == 1 && TYPE != 'u')
	{
		if (RES[0] != '-')
			if (!ospace(env, WIDTH))
				return (0);
	}
	else if (ft_strsearch(INDIC, '-') == 1)
	{
		if (!olalign(env, WIDTH))
			return (0);
	}
	return (1);
}

int				option(t_env *env, int x)
{
	int	err;

	while (env->form)
	{
		if (ft_strsearch("csp%", TYPE) == 0 && x == 1)
		{
			if (checkoptionerror(env) == 1 && PRECI <= ft_strlen(RES))
			{
				err = applydoubleoption(env);
				if (err == -1)
					return (0);
				else if (err == 0)
					if (!applyoption(env))
						return (0);
			}
		}
		if (ft_strsearch("csp%", TYPE) == 1 && x == 2)
		{
			if (checkoptionerror(env) == 1 && PRECI <= ft_strlen(RES))
				applyoption_str(env);
		}
		if (x == 2 && ft_strsearch(INDIC, '#') == 1 && (TYPE == 'x' || TYPE == 'X') && PRECI == ft_strlen(RES))
			if (!(RES = ft_strjoin("0", ft_free_join(&TYPE, RES, 2))))
				return (0);
		SIZE = ft_strlen(RES);
		if (!NEXT)
			break ;
		env->form = NEXT;
	}
	while (PREV)
		env->form = PREV;
	return (1);
}
