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

char	*ft_itoa_conv(int x, char c)
{

	char		*str;
    char  *oct = "01234567";
    char  *HEX = "0123456789ABCDEF";
	char  *hex = "0123456789abcdef";

    if (c == 'x')
        str = ft_deci_conv(x, hex);
	else if (c == 'X')
        str = ft_deci_conv(x, HEX);
    else if (c == 'o')
        str = ft_deci_conv(x, oct);
    else if (c == 'u')
    {
        if (x >= 0)
            str = ft_itoa(x);
        else
            str = ft_itoa(-x);
    }
    else
        str = ft_itoa(x);
	return (str);
}

char    *ft_deci_conv(int nb, char *base)
{
    char			*str;
    int				i;
	unsigned int	x;

    i = 0;
	if (!(str = (char *)malloc(sizeof(char))))
		return (NULL);
	if (nb < 0)
		x = 4294967296 + nb;
	else
		x = nb;
	if (x == 0)
		str[i++] = '0';
	else
	{
    	while (x > 0)
		{
			str[i++] = base[x % ft_strlen(base)];
			x /= ft_strlen(base);
		}
	}
	str[i] = '\0';
	return (ft_strrev(str));
}

char	ft_find_type(char *str)
{
	static const char	*cut = "diuoxXcsfp%";
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
	static const char	*cut = "diuoxXcsfp%";
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
