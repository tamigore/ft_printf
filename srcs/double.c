/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 10:45:25 by tamigore          #+#    #+#             */
/*   Updated: 2019/08/04 13:35:22 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*strjoin_double(char *dest, char *int_part, char *float_part)
{
	int		i;

	i = -1;
	while (++i < (int)ft_strlen(int_part))
		dest[i] = int_part[i];
	dest[i++] = '.';
	i = -1;
	while (++i < (int)ft_strlen(float_part))
		dest[i + (int)ft_strlen(int_part) + 1] = float_part[i];
	free(int_part);
	free(float_part);
	return (dest);
}

char		*double_to_str(double f, int len)
{
	double	fractional;
	char	*str_integer;
	char	*str_decimal;
	char	*res;

	fractional = f - (int)f;
	str_integer = ft_superitoa((int)f, 0, 2, 0);
	if (!(res = malloc(sizeof(char) * (ft_strlen(str_integer) + len + 2))))
		return (NULL);
	ft_bzero(res, (int)ft_strlen(str_integer) + len + 1);
	fractional = fractional * ft_unit(10, len);
	if (f > 0)
		str_decimal = ft_superitoa((int)(fractional + 0.5), 0, 2, 0);
	else
		str_decimal = ft_superitoa((int)(fractional - 0.5), 0, 2, 0);
	strjoin_double(res, str_integer, str_decimal);
	return (res);
}
