/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <tamigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:02:55 by tamigore          #+#    #+#             */
/*   Updated: 2020/01/14 17:28:43 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_freeall(t_env *env, int x)
{
	t_form	*tmp;

	if (env)
	{
		while (env->f)
		{
			if ((env->f->i))
				free((env->f->i));
			if ((env->f->m))
				free((env->f->m));
			if ((env->f->c))
				free((env->f->c));
			if ((env->f->r))
				free((env->f->r));
			tmp = env->f;
			env->f = env->f->n;
			free(tmp);
		}
		free(env->str);
		while (env->subs[x])
			free(env->subs[x++]);
		free(env->subs);
		free(env);
	}
}

void	ft_free_exit(t_env *env, int x)
{
	t_form	*tmp;

	if (env->f)
	{
		while (env->f)
		{
			if ((env->f->i))
				free((env->f->i));
			if ((env->f->m))
				free((env->f->m));
			if ((env->f->c))
				free((env->f->c));
			if ((env->f->r))
				free((env->f->r));
			tmp = env->f;
			env->f = env->f->n;
			free(tmp);
		}
		free(env->str);
		while (env->subs[x])
			free(env->subs[x++]);
		free(env->subs);
		free(env);
	}
	exit(0);
}

int		ft_err(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_search("diouxXcpsf%", ft_find_type(&str[i + 1])) == 0)
				return (ft_find_type(&str[i + 1]));
			i += ft_count_type(&str[i + 1]) + 1;
		}
		i++;
	}
	return (1);
}

char	*ft_free_join(char *s1, char *s2, int x)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(s1, s2)))
		return (NULL);
	if (x == 1)
		free(s1);
	else if (x == 2)
		free(s2);
	else if (x == 3)
	{
		free(s1);
		free(s2);
	}
	return (tmp);
}

int		ft_erorrcheck(t_env *env, int j, int i)
{
	while (env->f)
	{
		i = 0;
		j = 0;
		if ((ft_search((env->f->i), '0') && ft_search("diouxX", (env->f->t)) &&
			(env->f->p) > 0) || (ft_search((env->f->i), '0') && !(env->f->w)))
			if (!((env->f->i) = ft_free_rmchar((env->f->i), '0')))
				return (0);
		if (ft_search("diucsp%", (env->f->t)) && ft_search((env->f->i), '#'))
			if (!((env->f->i) = ft_free_rmchar((env->f->i), '#')))
				return (0);
		if (!(env->f->n))
			break ;
		env->f = (env->f->n);
	}
	return (1);
}
