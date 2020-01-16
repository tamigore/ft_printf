/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <tamigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 11:22:08 by tamigore          #+#    #+#             */
/*   Updated: 2020/01/16 16:06:30 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		oposi(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = ft_strlen((env->f->r)) + 1;
	i = 0;
	j = 0;
	if (!(tmp = ft_strnew(width)))
		return (0);
	while (i < width - (int)ft_strlen((env->f->r)) - 1)
		tmp[i++] = ' ';
	if (ft_superatoi((env->f->r)) >= 0)
		tmp[i++] = '+';
	while ((env->f->r)[j])
		tmp[i++] = (env->f->r)[j++];
	free((env->f->r));
	(env->f->r) = tmp;
	return (1);
}

int		ohash(t_env *env, int width, int i)
{
	char	*tmp;

	if ((env->f->t) == 'f')
	{
		if (ft_search((env->f->r), '.') == 0)
			if (!((env->f->r) = ft_free_join((env->f->r), ".", 1)))
				return (0);
		return (1);
	}
	if (((env->f->t) == 'x' || (env->f->t) == 'X') && (env->f->r)[0] == 0)
		return (1);
	if (width < (int)ft_strlen((env->f->r)))
		width = ft_strlen((env->f->r));
	if (!(tmp = ft_strnew(width + 2)))
		return (0);
	ohash_add(env, width, i, tmp);
	free((env->f->r));
	(env->f->r) = tmp;
	return (1);
}

int		olzero(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;
	int		neg;

	if (width == 0)
		width = ft_strlen((env->f->r));
	i = 0;
	j = 0;
	neg = 0;
	if (!(tmp = ft_strnew(width)))
		return (0);
	if (ft_superatoi((env->f->r)) < 0)
	{
		tmp[i++] = '-';
		j++;
		neg++;
	}
	while (i < (width - (int)ft_strlen((env->f->r)) + neg))
		tmp[i++] = '0';
	while ((env->f->r)[j])
		tmp[i++] = (env->f->r)[j++];
	free((env->f->r));
	(env->f->r) = tmp;
	return (1);
}

int		ospace(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width <= (int)ft_strlen((env->f->r)))
		width = ft_strlen(env->f->r) + (ft_superatoi(env->f->r) < 0 ? 0 : 1);
	i = 0;
	j = 0;
	if (!(tmp = ft_strnew(width)))
		return (0);
	while (i < width - (int)ft_strlen((env->f->r)))
		tmp[i++] = ' ';
	while ((env->f->r)[j])
		tmp[i++] = (env->f->r)[j++];
	free((env->f->r));
	(env->f->r) = tmp;
	return (1);
}

int		olalign(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0 || width < (int)ft_strlen((env->f->r)))
		width = ft_strlen((env->f->r));
	i = 0;
	j = 0;
	if (!(tmp = ft_strnew(width)))
		return (0);
	while ((env->f->r)[j])
		tmp[i++] = (env->f->r)[j++];
	while (i < width)
		tmp[i++] = ' ';
	free((env->f->r));
	(env->f->r) = tmp;
	return (1);
}
