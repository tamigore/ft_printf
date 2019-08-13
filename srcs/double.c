/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 10:45:25 by tamigore          #+#    #+#             */
/*   Updated: 2019/08/13 20:32:09 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*strjoin_double(char *dest, char *int_part, char *float_part)
{
	int		i;

	i = -1;
	while (++i < ft_strlen(int_part))
		dest[i] = int_part[i];
	dest[i++] = '.';
	i = -1;
	while (++i < ft_strlen(float_part))
		dest[i + ft_strlen(int_part) + 1] = float_part[i];
	free(int_part);
	free(float_part);
	return (dest);
}

char		*double_to_str(long double f, int len)
{
	long double	fractional;
	char		*str_integer;
	char		*str_decimal;
	char		*res;

	fractional = (f - (int)f) * (f < 0 ? -1 : 1);
	str_integer = ft_superitoa((int)f, 0, 2, 0);
	if (!(res = malloc(sizeof(char) * (ft_strlen(str_integer) + len + 1))))
		return (NULL);
	ft_bzero(res, ft_strlen(str_integer) + len + 1);
	fractional = fractional * ft_unit(10, len);
	if (f > 0)
		str_decimal = ft_superitoa((int)(fractional + 0.5), 0, 2, 0);
	else
		str_decimal = ft_superitoa((int)(fractional - 0.5), 0, 2, 0);
	strjoin_double(res, str_integer, str_decimal);
	return (res);
}

char		*ft_conv_double(va_list ap, t_form *new)
{
	char	*str;

	if (new->modif[0] == 'l' || new->modif[0] == 'L')
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
