/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:25:11 by tamigore          #+#    #+#             */
/*   Updated: 2019/04/27 17:28:50 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int x)
{
	unsigned int	y;
	char			*str;
	int				neg;
	int				count;

	neg = 0;
	count = 1;
	if (x < 0)
		neg = 1;
	y = ABS(x);
	while (y >= 10)
	{
		y /= 10;
		count++;
	}
	if (!(str = (char *)malloc(count + 1 + neg)))
		return (NULL);
	str[neg + count--] = '\0';
	y = ABS(x);
	while (y > 0)
	{
		str[neg + count--] = (y % 10) + '0';
		y /= 10;
	}
	if (neg == 1)
		*str = '-';
	return (str);
}

char	ft_pars_char(char *str)
{
	static const char	*cut = "diuoxXcsfp";
	int					x;
	int					y;

	x = 0;
	while (str[x])
	{
		y = 0;
		while (cut[y])
		{
			if (cut[y] == str[x])
				return (cut[y]);
			y++;
		}
		x++;
	}
	return (0);
}

int		ft_count(char *str)
{
	static const char	*cut = "diuoxXcsfp";
	int					x;
	int					y;

	x = 0;
	while (str[x])
	{
		y = 0;
		while (cut[y])
		{
			if (cut[y] == str[x])
				return (x);
			y++;
		}
		x++;
	}
	return (0);
}

char	*ft_float_to_char(double nb)
{
	char			*integer;
	char			*decimal;
	double			count;
	unsigned int	y;
	unsigned int	x;

	count = 0;
	x = 0;
	y = (unsigned int)nb;
	if (nb < 0)
	{
		integer = ft_itoa(-y);
		nb = nb + y;
	}
	else
	{
		integer = ft_itoa(y);
		nb = nb - y;
	}
	while (nb && count < 7)
	{
		nb *= 10;
		x *= 10;
		x += (unsigned int)nb;
		nb = nb - (x % 10);
		count++;
	}
	decimal = ft_itoa(UPORDOW(x));
	return (ft_strcat_float(integer, decimal));
}

char	*ft_strcat_float(char *integer, char *decimal)
{
	char	*str;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!(str = (char *)malloc(ft_strlen(integer) + ft_strlen(decimal))))
		return (NULL);
	while (integer[x])
	{
		str[x] = integer[x];
		x++;
	}
	str[x++] = '.';
	while (decimal[y])
		str[x++] = decimal[y++];
	str[x] = '\0';
	return (str);
}
