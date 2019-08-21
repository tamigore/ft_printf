/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 10:45:25 by tamigore          #+#    #+#             */
/*   Updated: 2019/08/21 17:15:57 by tamigore         ###   ########.fr       */
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
		i = ft_strlen(int_part) - 1;
		if (float_part[0] >= '5')
		{
<<<<<<< HEAD
			while (int_part[i] == '9')
				int_part[i--] = '0';
			int_part[i]++;
=======
			while (int_part[i] == '9' && i > 0)
				int_part[i--] = '0';
			if (i == 0 && int_part[i] == '9')
			{
				int_part[i] = '0';
				if (!(int_part = ft_free_join("1", int_part, 2)))
					return (NULL);
			}
			else
				int_part[i]++;
>>>>>>> 9caafce9abc259c5b0eccdf49d05dcb5d75fa8f9
		}
		return (ft_strdup(int_part));
	}
	if (!(dest = ft_strnew(ft_strlen(int_part) + ft_strlen(float_part) + 1)))
		return (NULL);
	while (i < ft_strlen(int_part))
	{
		dest[i] = int_part[i];
		i++;
	}
	dest[i++] = '.';
	i = -1;
	while (++i < ft_strlen(float_part))
		dest[i + ft_strlen(int_part) + 1] = float_part[i];
	free(int_part);
	free(float_part);
	return (dest);
}

static char	*ft_doubleitoa(long long x, int neg, int len, long long i)
{
	char	*str;

	if (x == LLONG_MIN)
		return (ft_strdup("-9223372036854775807"));
	i = ABS(x);
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
	while(i < len - ft_strlen(str))
		res[i++] = '0';
	while(i < len)
		res[i++] = str[j++];
	return (res);
}

char		*double_to_str(long double f, int len)
{
	long double	fractional;
	char		*str_integer;
	char		*str_decimal;
	char		*res;

	fractional = (long double)(f - (long long int)f);
	fractional *= ft_unit(10, len);
	if (ft_nbrlen(fractional) < ft_nbrlen(fractional + 0.5) ||
			ft_nbrlen(fractional) < ft_nbrlen(fractional - 0.5))
	{
		fractional = 0;
		if (f < 0)
			f--;
		else
			f++;
	}
	if (f >= 0)
	{
		str_integer = ft_doubleitoa((long long)f, 0, 2, 0);
		str_decimal = ft_doubleitoa((long long)(fractional + 0.5), 0, 2, 0);
	}
	else
	{
		str_integer = ft_doubleitoa(-1 * (long long)f, 0, 2, 0);
		str_decimal = ft_doubleitoa(-1 * (long long)(fractional - 0.5), 0, 2, 0);
	}	
	if (ft_strlen(str_decimal) < len)
		if (!(str_decimal = ft_addlen(str_decimal, len)))
			return (NULL);
	if (!(res = strjoin_double(str_integer, str_decimal, len)))
		return (NULL);
	if (f < 0)
		if (!(res = ft_free_join("-", res, 2)))
			return (NULL);
	return (res);
}

char		*ft_conv_double(va_list ap, t_form *new)
{
	char	*str;

	if (ft_strsearch(new->modif, 'L') == 1)
	{
		if (!(str = double_to_str((long double)va_arg(ap, long double),
						new->preci)))
			return (NULL);
	}
	else if (!(str = double_to_str((double)va_arg(ap, double), new->preci)))
		return (NULL);
	if (new->preci > ft_strlen(str))
		str = ft_modif_preci_double(str, new->preci);
	return (str);
}

char		*ft_modif_preci_double(char *str, int len)
{
	char	*tmp;
	int		i;
	int		x;

	x = 0;
	while (str[x] && str[x] != '.')
		x++;
	if (len == 0)
	{
		if (!(tmp = ft_strndup(str, x)))
			return (NULL);
		free(str);
		return (tmp);
	}
	if (!(tmp = ft_strnew(x + len + 1)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	while (i < len + x + 1)
		tmp[i++] = '0';
	free(str);
	return (tmp);
}
