/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_duo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 11:13:23 by tamigore          #+#    #+#             */
/*   Updated: 2019/08/13 20:32:02 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		oposineg(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = ft_strlen(RES) + (RES[0] == '-' ? 0 : 1);
	i = 0;
	j = 0;
	if (!(tmp = ft_strnew(width)))
		return (0);
	if (ft_superatoi(RES) >= 0)
		tmp[i++] = '+';
	while (RES[j])
		tmp[i++] = RES[j++];
	while (i < width)
		tmp[i++] = ' ';
	free(RES);
	RES = tmp;
	return (1);
}

int		oposizero(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width <= ft_strlen(RES))
		width = ft_strlen(RES) + 1;
	i = 0;
	j = 0;
	if (!(tmp = ft_strnew(width)))
		return (0);
	if (ft_superatoi(RES) >= 0)
		tmp[i++] = '+';
	else
	{
		tmp[i++] = '-';
		j++;
		width++;
	}
	while (i < width - ft_strlen(RES))
		tmp[i++] = '0';
	while (RES[j])
		tmp[i++] = RES[j++];
	free(RES);
	RES = tmp;
	return (1);
}

int		onegspace(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = ft_strlen(RES) + 1;
	i = 0;
	j = 0;
	if (!(tmp = ft_strnew(width)))
		return (0);
	if (ft_superatoi(RES) >= 0)
		tmp[i++] = ' ';
	while (RES[j])
		tmp[i++] = RES[j++];
	while (i < width)
		tmp[i++] = ' ';
	free(RES);
	RES = tmp;
	return (1);
}

int		ozerospace(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = ft_strlen(RES) + 1;
	i = 0;
	j = 0;
	if (!(tmp = ft_strnew(width)))
		return (0);
	if (ft_superatoi(RES) >= 0)
		tmp[i++] = ' ';
	else
	{
		tmp[i++] = '-';
		j++;
		width++;
	}
	while (i < (width - ft_strlen(RES)))
		tmp[i++] = '0';
	while (RES[j])
		tmp[i++] = RES[j++];
	free(RES);
	RES = tmp;
	return (1);
}
