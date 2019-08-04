/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 11:22:08 by tamigore          #+#    #+#             */
/*   Updated: 2019/08/04 13:28:17 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	oposi(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = ft_strlen(RES) + 1;
	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	while (i < width - ft_strlen(RES) - 1)
		tmp[i++] = ' ';
	tmp[i++] = '+';
	while (RES[j])
		tmp[i++] = RES[j++];
	RES = tmp;
}

void	ohash(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	i = 2;
	j = 0;
	if (width != 0)
		tmp = ft_strnew(width);
	else
		tmp = ft_strnew(ft_strlen(RES) + 2);
	tmp[0] = '0';
	tmp[1] = TYPE;
	if (TYPE == 'o')
		i--;
	if (ft_strsearch(INDIC, '0') == 1)
	{
		while (i < width - ft_strlen(RES))
			tmp[i++] = '0';
	}
	while (RES[j])
		tmp[i++] = RES[j++];
	RES = tmp;
}

void	olzero(t_env *env, int width)
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
	tmp = ft_strnew(width);
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
	RES = tmp;
}

void	ospace(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = (int)ft_strlen(RES) + 1;
	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	while (i < (width - (int)ft_strlen(RES)))
		tmp[i++] = ' ';
	while (RES[j])
		tmp[i++] = RES[j++];
	RES = tmp;
}

void	olalign(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0 || width < ft_strlen(RES))
		width = ft_strlen(RES);
	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	while (RES[j])
		tmp[i++] = RES[j++];
	while (i < width)
		tmp[i++] = ' ';
	RES = tmp;
}
