/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 11:22:08 by tamigore          #+#    #+#             */
/*   Updated: 2019/08/08 17:36:53 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		oposi(t_env *env, int width)
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
	while (i < width - ft_strlen(RES) - 1)
		tmp[i++] = ' ';
	tmp[i++] = '+';
	while (RES[j])
		tmp[i++] = RES[j++];
	free(RES);
	RES = tmp;
	return (1);
}

int		ohash(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	i = 2;
	j = 0;
	if ((TYPE == 'x' || TYPE == 'X') && RES[0] == 0)
		return (1);
	if (width != 0)
	{
		if (!(tmp = ft_strnew(width)))
			return (0);
	}
	else
		if (!(tmp = ft_strnew(ft_strlen(RES) + 2)))
			return (0);
	tmp[0] = '0';
	if (TYPE == 'o')
		i--;
	else
		tmp[1] = TYPE;
	if (ft_strsearch(INDIC, '0') == 1)
	{
		while (i < width - ft_strlen(RES))
			tmp[i++] = '0';
	}
	while (RES[j])
		tmp[i++] = RES[j++];
	free(RES);
	RES = tmp;
	return (1);
}

int		olzero(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;
	int		neg;

	if (width == 0)
		width = ft_strlen(RES);
	i = 0;
	j = 0;
	neg = 0;
	if (!(tmp = ft_strnew(width)))
		return (0);
	if (RES[j] == '-')
	{
		tmp[i++] = '-';
		j++;
		neg++;
	}
	while (i < (width - (int)ft_strlen(RES) + neg))
		tmp[i++] = '0';
	while (RES[j])
		tmp[i++] = RES[j++];
	free(RES);
	RES = tmp;
	return (1);
}

int		ospace(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = (int)ft_strlen(RES) + 1;
	i = 0;
	j = 0;
	if (!(tmp = ft_strnew(width)))
		return (0);
	while (i < (width - (int)ft_strlen(RES)))
		tmp[i++] = ' ';
	while (RES[j])
		tmp[i++] = RES[j++];
	free(RES);
	RES = tmp;
	return (1);
}

int		olalign(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0 || width < ft_strlen(RES))
		width = ft_strlen(RES);
	i = 0;
	j = 0;
	if (!(tmp = ft_strnew(width)))
		return (0);
	while (RES[j])
		tmp[i++] = RES[j++];
	while (i < width)
		tmp[i++] = ' ';
	free(RES);
	RES = tmp;
	return (1);
}
