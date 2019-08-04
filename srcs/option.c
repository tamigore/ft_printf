/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 11:11:54 by tamigore          #+#    #+#             */
/*   Updated: 2019/08/04 13:26:12 by tamigore         ###   ########.fr       */
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
		if (RES[i] != '\0')
		{
			while (RES[i])
				ft_swap(&RES[i++], &RES[j++]);
		}
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
		if (RES[0] != '-')
			oposi(env, WIDTH);
	}
	else if (ft_strsearch(INDIC, '#') == 1)
	{
		if (RES[0] != '0' && RES[1])
			ohash(env, WIDTH);
	}
	else if (ft_strsearch(INDIC, '0') == 1)
		olzero(env, WIDTH);
	else if (ft_strsearch(INDIC, ' ') == 1 && TYPE != 'u')
	{
		if (RES[0] != '-')
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
			if (checkoptionerror(env) == 1 && PRECI <= ft_strlen(RES))
			{
				if (applydoubleoption(env) == 0)
					applyoption(env);
			}
		}
		if (ft_strsearch("csp%", TYPE) == 1 && x == 2)
		{
			if (checkoptionerror(env) == 1 && PRECI <= ft_strlen(RES))
				applyoption_str(env);
		}
		SIZE = ft_strlen(RES);
		if (!NEXT)
			break ;
		env->form = NEXT;
	}
	while (PREV)
		env->form = PREV;
}
