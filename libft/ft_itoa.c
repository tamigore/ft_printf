/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:05:26 by tamigore          #+#    #+#             */
/*   Updated: 2018/11/19 16:56:17 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		ft_neg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static	int		ft_unit(unsigned int nb)
{
	int unit;

	unit = 0;
	if (nb == 0)
		unit++;
	while (nb > 0)
	{
		nb /= 10;
		unit++;
	}
	return (unit);
}

char			*ft_itoa(int n)
{
	char			*p;
	int				unit;
	unsigned int	nb;
	int				i;

	i = 0;
	if (n < 0)
		nb = -n;
	else
		nb = n;
	unit = ft_unit(nb);
	if (!(p = (char *)malloc(unit + 1 + ft_neg(n))))
		return (NULL);
	while (unit > 0)
	{
		p[i++] = nb % 10 + '0';
		nb /= 10;
		unit--;
	}
	if (n < 0)
		p[i++] = '-';
	p[i] = '\0';
	p = ft_strrev(p);
	return (p);
}
