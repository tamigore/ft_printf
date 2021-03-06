/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <tamigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 10:45:25 by tamigore          #+#    #+#             */
/*   Updated: 2020/01/20 17:52:51 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*strjoin_double(char *int_part, char *float_part, int len)
{
	char	*dest;
	int		i;

	i = 0;
	if (len == -1)
	{
		if (!(int_part = strjoin_double_add(int_part, float_part, i)))
			return (NULL);
		return (int_part);
	}
	if (!(dest = ft_strnew(ft_strlen(int_part) + ft_strlen(float_part) + 1)))
		return (NULL);
	while (i < (int)ft_strlen(int_part))
	{
		dest[i] = int_part[i];
		i++;
	}
	dest[i++] = '.';
	i = -1;
	while (++i < (int)ft_strlen(float_part))
		dest[i + ft_strlen(int_part) + 1] = float_part[i];
	free(int_part);
	free(float_part);
	return (dest);
}

char		*ft_doubleitoa(long long x, int neg, int len, long long i)
{
	char	*str;

	if (x == LLONG_MIN)
		return (ft_strdup("-9223372036854775807"));
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

static char	*ft_addlen(char *str, int len)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(res = ft_strnew(len)))
		return (NULL);
	while (i < len - (int)ft_strlen(str))
		res[i++] = '0';
	while (i < len)
		res[i++] = str[j++];
	free(str);
	return (res);
}

char		*double_to_str(long double f, int len)
{
	long double	frac;
	char		*inte;
	char		*deci;
	char		*res;

	if (f / 2 == f && f > 0)
		return (ft_strdup("inf"));
	else if (f / 2 == f && f < 0)
		return (ft_strdup("-inf"));
	frac = (long double)(f - (long long int)f);
	frac *= ft_unit(10, len);
	if (!(inte = double_inte(f, frac, len)))
		return (NULL);
	if (!(deci = double_deci(f, frac, len)))
		return (NULL);
	if ((int)ft_strlen(deci) < len)
		if (!(deci = ft_addlen(deci, len)))
			return (NULL);
	if (!(res = strjoin_double(inte, deci, len)))
		return (NULL);
	if (f < 0)
		if (!(res = ft_free_join("-", res, 2)))
			return (NULL);
	return (res);
}

char		*ft_conv_double(va_list ap, t_form *new)
{
	char	*str;

	if (ft_search(new->m, 'L') == 1)
	{
		if (!(str = double_to_str((long double)va_arg(ap, long double),
						new->p)))
			return (NULL);
	}
	else if (!(str = double_to_str((double)va_arg(ap, double), new->p)))
		return (NULL);
	return (str);
}
