/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <tamigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 11:11:54 by tamigore          #+#    #+#             */
/*   Updated: 2020/01/16 16:17:19 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		applyoption_str(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_search((env->f->i), '-') == 1)
	{
		while ((env->f->r)[i] == ' ')
			i++;
		while ((env->f->r)[i])
			ft_swap(&(env->f->r)[i++], &(env->f->r)[j++]);
	}
	if (ft_search((env->f->i), '0') == 1)
	{
		while ((env->f->r)[i] == ' ')
			(env->f->r)[i++] = '0';
	}
}

static int		applydoubleoption(t_env *env)
{
	if (ft_search((env->f->i), '+') && ft_search((env->f->i), '-'))
	{
		if (!oposineg(env, (env->f->w)))
			return (-1);
	}
	else if (ft_search((env->f->i), '+') && ft_search((env->f->i), '0'))
	{
		if (!oposizero(env, (env->f->w)))
			return (-1);
	}
	else if (ft_search((env->f->i), '-') && ft_search((env->f->i), ' '))
	{
		if (!onegspace(env, (env->f->w)))
			return (-1);
	}
	else if (ft_search((env->f->i), '0') && ft_search((env->f->i), ' '))
	{
		if (!ozerospace(env, (env->f->w)))
			return (-1);
	}
	else
		return (0);
	return (1);
}

static int		applyoption(t_env *env)
{
	if (ft_search((env->f->i), '+') && (env->f->t) != 'u')
	{
		if (!oposi(env, (env->f->w)))
			return (0);
	}
	else if (ft_search((env->f->i), '#') && (env->f->r)[0] != '0')
	{
		if (ft_search("xXof", (env->f->t)) == 1)
			if (!ohash(env, (env->f->w), 2))
				return (0);
	}
	else if (ft_search((env->f->i), '0') == 1)
	{
		if (!olzero(env, (env->f->w)))
			return (0);
	}
	else if (ft_search((env->f->i), ' ') && (env->f->t) != 'u')
	{
		if (!ospace(env, (env->f->w)))
			return (0);
	}
	else if (ft_search((env->f->i), '-') == 1)
		if (!olalign(env, (env->f->w)))
			return (0);
	return (1);
}

static int		option_all(t_env *env, int x, int err)
{
	if (ft_search("csp%", (env->f->t)) == 0 && x == 1)
	{
		if ((env->f->p) <= (int)ft_strlen((env->f->r)))
		{
			err = applydoubleoption(env);
			if (err == -1)
				return (0);
			else if (err == 0)
				if (!applyoption(env))
					return (0);
		}
	}
	if (ft_search("csp%", (env->f->t)) == 1 && x == 2)
	{
		if ((env->f->p) <= (int)ft_strlen((env->f->r)))
			applyoption_str(env);
	}
	if ((env->f->t) == 'f' && x == 2 && ft_search((env->f->i), '#') == 1 &&
			ft_search((env->f->r), '.') == 0)
		if (!(option_all_add(env, err)))
			return (0);
	(env->f->s) = ft_strlen((env->f->r));
	return (1);
}

int				option(t_env *env, int x)
{
	int		err;

	err = 0;
	while (env->f)
	{
		if ((env->f->i)[0] != '\0' && (env->f->i))
			if (option_all(env, x, err) == 0)
				return (0);
		if (!(env->f->n))
			break ;
		env->f = (env->f->n);
	}
	while ((env->f->b))
		env->f = (env->f->b);
	return (1);
}
