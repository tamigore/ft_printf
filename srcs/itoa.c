/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <tamigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 10:57:18 by tamigore          #+#    #+#             */
/*   Updated: 2019/12/08 18:21:20 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

double				ft_unit(double nb, int len)
{
	int		i;
	double	tmp;

	tmp = nb;
	i = 0;
	while (++i < len)
		nb *= tmp;
	return (nb);
}

unsigned long long	ft_doubleunit(unsigned long long nb, int unit)
{
	if (unit == 0)
		return (1);
	else
		return (nb * ft_unit(nb, unit - 1));
}

char				*ft_superitoa(int x, int neg, int len, int i)
{
	char	*str;

	if (x == -2147483648)
		return (ft_strdup("-2147483648"));
	i = (x > 0) ? x : -x;
	if (x < 0)
	{
		neg = 1;
		x *= -1;
	}
	while (i /= 10)
		len++;
	len += neg;
	if (!(str = (char *)malloc(sizeof(char) * (len))))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = x % 10 + '0';
		x = x / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

char				*ft_itoa_base(unsigned long long nb, int base)
{
	int		i;
	char	*res;

	i = (nb >= (unsigned long long)base) ? 2 : 1;
	if (nb == 0)
		return (ft_strdup("0"));
	while (ft_doubleunit(base, i) - 1 < nb)
		i++;
	if (!(res = (char*)malloc(sizeof(res) * i)))
		return (NULL);
	res[i] = '\0';
	while (i > 0)
	{
		res[--i] = (nb % base) + (nb % base > 9 ? 'A' - 10 : '0');
		nb = nb / base;
	}
	return (res);
}

char				*ft_itoa_long(long long val, int base, int len)
{
	char		*str;
	int			sign;
	long long	n;

	if (val == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	sign = (val < 0) ? 1 : 0;
	if (sign == 1)
		val = -val;
	n = val;
	if (val == 0)
		return (ft_strdup("0"));
	while (n /= base)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + sign + 1))))
		return (NULL);
	str[len + sign] = '\0';
	str[0] = '-';
	while (len-- > 0)
	{
		str[len + sign] = "0123456789abcdef"[val % base];
		val /= base;
	}
	return (str);
}
