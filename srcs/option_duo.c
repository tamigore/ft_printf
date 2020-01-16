/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_duo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 11:13:23 by tamigore          #+#    #+#             */
/*   Updated: 2019/11/19 14:09:31 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		oposineg(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = ft_strlen((env->f->r)) + ((env->f->r)[0] == '-' ? 0 : 1);
	i = 0;
	j = 0;
	if (!(tmp = ft_strnew(width)))
		return (0);
	if (ft_superatoi((env->f->r)) >= 0)
		tmp[i++] = '+';
	while ((env->f->r)[j])
		tmp[i++] = (env->f->r)[j++];
	while (i < width)
		tmp[i++] = ' ';
	free((env->f->r));
	(env->f->r) = tmp;
	return (1);
}

int		oposizero(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width <= (int)ft_strlen((env->f->r)) && (env->f->t) != 'f')
		width = ft_strlen((env->f->r)) + 1;
	i = 0;
	j = 0;
	if (!(tmp = ft_strnew(width)))
		return (0);
	if (ft_superatoi((env->f->r)) >= 0)
		tmp[i++] = '+';
	else
	{
		tmp[i++] = '-';
		j++;
		width++;
	}
	while (i < width - (int)ft_strlen((env->f->r)))
		tmp[i++] = '0';
	while ((env->f->r)[j])
		tmp[i++] = (env->f->r)[j++];
	free((env->f->r));
	(env->f->r) = tmp;
	return (1);
}

int		onegspace(t_env *env, int width)
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
	if (ft_superatoi((env->f->r)) >= 0)
		tmp[i++] = ' ';
	while ((env->f->r)[j])
		tmp[i++] = (env->f->r)[j++];
	while (i < width)
		tmp[i++] = ' ';
	free((env->f->r));
	(env->f->r) = tmp;
	return (1);
}

int		ozerospace(t_env *env, int width)
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
	if (ft_superatoi((env->f->r)) >= 0)
		tmp[i++] = ' ';
	else
	{
		tmp[i++] = '-';
		j++;
		width++;
	}
	while (i < (width - (int)ft_strlen((env->f->r))))
		tmp[i++] = '0';
	while ((env->f->r)[j])
		tmp[i++] = (env->f->r)[j++];
	free((env->f->r));
	(env->f->r) = tmp;
	return (1);
}
