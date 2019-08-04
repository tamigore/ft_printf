/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_duo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 11:13:23 by tamigore          #+#    #+#             */
/*   Updated: 2019/08/04 13:31:18 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	oposineg(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = ft_strlen(RES) + 1;
	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	tmp[i++] = '+';
	while (RES[j])
		tmp[i++] = RES[j++];
	while (i < width)
		tmp[i++] = ' ';
	RES = tmp;
}

void	oposizero(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = ft_strlen(RES) + 1;
	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	if (RES[0] != '-')
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
	RES = tmp;
}

void	onegspace(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = ft_strlen(RES) + 1;
	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	tmp[i++] = ' ';
	while (RES[j])
		tmp[i++] = RES[j++];
	while (i < width)
		tmp[i++] = ' ';
	RES = tmp;
}

void	ozerospace(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = ft_strlen(RES) + 1;
	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	tmp[i++] = ' ';
	while (i < (width - ft_strlen(RES)))
		tmp[i++] = '0';
	while (RES[j])
		tmp[i++] = RES[j++];
	RES = tmp;
}
