/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <tamigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:57:14 by tamigore          #+#    #+#             */
/*   Updated: 2020/01/14 17:36:40 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find_preci_add(char *subs, int i, int x)
{
	if (subs[i + 1] == '0')
		i++;
	if (x < 0)
		x = 0;
	while (subs[i + 1] >= '0' && subs[i + 1] <= '9')
	{
		x *= 10;
		x += subs[i++ + 1] - '0';
	}
	return (x);
}

int		ft_print_all_add(t_env *env, int count)
{
	if (ft_search((env->f->i), '-') == 0)
		ft_putstr((env->f->r));
	write(1, "\0", 1);
	count++;
	if (ft_search((env->f->i), '-') == 1)
		ft_putstr((env->f->r));
	return (count);
}

char	*ft_modif_preci_add(t_env *env, int i, int j, char *tmp)
{
	while ((env->f->r)[j])
		tmp[i++] = (env->f->r)[j++];
	if (ft_search((env->f->i), '#') == 1 && (env->f->c)[0] != '0')
	{
		if ((env->f->t) == 'x')
		{
			if (!(tmp = ft_free_join("0x", tmp, 2)))
				return (NULL);
		}
		else if ((env->f->t) == 'X')
			if (!(tmp = ft_free_join("0X", tmp, 2)))
				return (NULL);
	}
	return (tmp);
}

int		option_all_add(t_env *env, int e)
{
	while ((env->f->r)[e] && !ft_search("0123456789", (env->f->r)[e]))
		e++;
	while ((env->f->r)[e] && (env->f->r)[e] >= '0' && (env->f->r)[e] <= '9')
		e++;
	if ((env->f->r)[e] == '\0')
	{
		if (!((env->f->r) = ft_free_join((env->f->r), ".", 1)))
			return (0);
	}
	else
		(env->f->r)[e] = '.';
	return (1);
}

void	ohash_add(t_env *env, int width, int i, char *tmp)
{
	int		j;

	j = 0;
	tmp[0] = '0';
	if ((env->f->t) == 'o')
		i--;
	else
		tmp[1] = (env->f->t);
	if (ft_search((env->f->i), '0') == 1)
		while (i < width - (int)ft_strlen((env->f->r)))
			tmp[i++] = '0';
	while ((env->f->r)[j])
		tmp[i++] = (env->f->r)[j++];
}
