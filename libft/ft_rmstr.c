/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 17:55:10 by tamigore          #+#    #+#             */
/*   Updated: 2019/08/04 10:43:54 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rmstr(char *str, int i, int j)
{
	char	*tmp;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!(tmp = ft_strnew(ft_strlen(str) - i + j + 1)))
		return (NULL);
	while (str[x])
	{
		if (x == i)
			while (x <= j && str[x])
				x++;
		tmp[y++] = str[x++];
	}
	tmp[y] = '\0';
	return (tmp);
}
