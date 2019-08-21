/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 11:22:08 by tamigore          #+#    #+#             */
/*   Updated: 2019/08/21 20:02:45 by tamigore         ###   ########.fr       */
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
	if (ft_superatoi(RES) >= 0)
		tmp[i++] = '+';
	while (RES[j])
		tmp[i++] = RES[j++];
	free(RES);
	RES = tmp;
	return (1);
}

int		ohash(t_env *env, int width, int i, int j)
{
	char	*tmp;

	if (TYPE == 'f')
	{
		if (ft_strsearch(RES, '.') == 0)
			if (!(RES = ft_free_join(RES, ".", 1)))
				return (0);
		return (1);
	}
	if ((TYPE == 'x' || TYPE == 'X') && RES[0] == 0)
		return (1);
	if (width != 0)
	{
		if (!(tmp = ft_strnew(width)))
			return (0);
	}
	else if (!(tmp = ft_strnew(ft_strlen(RES) + 2)))
		return (0);
	tmp[0] = '0';
	if (TYPE == 'o')
		i--;
	else
		tmp[1] = TYPE;
	if (ft_strsearch(INDIC, '0') == 1)
		while (i < width - ft_strlen(RES))
			tmp[i++] = '0';
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
	if (ft_superatoi(RES) < 0)
	{
		tmp[i++] = '-';
		j++;
		neg++;
	}
	while (i < (width - ft_strlen(RES) + neg))
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

	if (width <= ft_strlen(RES))
		width = ft_strlen(RES) + (ft_superatoi(RES) < 0 ? 0 : 1);
	i = 0;
	j = 0;
	if (!(tmp = ft_strnew(width)))
		return (0);
	while (i < width - ft_strlen(RES))
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
