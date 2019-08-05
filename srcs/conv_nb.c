/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_nb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 10:47:15 by tamigore          #+#    #+#             */
/*   Updated: 2019/08/05 20:04:33 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_find_base(char c)
{
	if (c == 'o')
		return (8);
	else if (c == 'x' || c == 'X')
		return (16);
	else
		return (10);
}

char		*ft_conv_type_d(t_form *new, va_list ap)
{
	if (ft_strcmp(new->modif, "l") == 0)
		return (ft_itoa_long((long)va_arg(ap, long int), 10, 1));
	else if (ft_strcmp(new->modif, "ll") == 0)
		return (ft_itoa_long((long long)va_arg(ap, long long int), 10, 1));
	else if (ft_strcmp(new->modif, "h") == 0)
		return (ft_superitoa((short)va_arg(ap, int), 0, 2, 0));
	else if (ft_strcmp(new->modif, "hh") == 0)
		return (ft_superitoa((char)va_arg(ap, int), 0, 2, 0));
	else
		return (ft_superitoa((int)va_arg(ap, int), 0, 2, 0));
}

static char	*ft_conv(char *str, t_form *new)
{
	int	i;

	i = 0;
	if (str && new->type == 'X')
	{
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'f')
				str[i] -= 32;
			i++;
		}
	}
	else if (str)
	{
		while (str[i])
		{
			if (str[i] >= 'A' && str[i] <= 'F')
				str[i] += 32;
			i++;
		}
	}
	return (str);
}

char		*ft_conv_type(t_form *new, va_list ap)
{
	char	*str;

	if (ft_strcmp(new->modif, "l") == 0)
		str = (ft_itoa_base((unsigned long int)va_arg(ap, unsigned long int),
					ft_find_base(new->type)));
	else if (ft_strcmp(new->modif, "ll") == 0)
		str = (ft_itoa_base((unsigned long long int)va_arg(ap,
						unsigned long long int), ft_find_base(new->type)));
	else if (ft_strcmp(new->modif, "h") == 0)
		str = (ft_itoa_base((unsigned short int)va_arg(ap, unsigned int),
					ft_find_base(new->type)));
	else if (ft_strcmp(new->modif, "hh") == 0)
		str = (ft_itoa_base((unsigned char)va_arg(ap, unsigned int),
					ft_find_base(new->type)));
	else
		str = (ft_itoa_base((unsigned int)va_arg(ap, unsigned int),
					ft_find_base(new->type)));
	str = ft_conv(str, new);
	return (str);
}

char		*ft_conv_char(t_form *new, va_list ap)
{
	char	*str;
	char	c;

	if (new->type == 'c')
		c = (char)va_arg(ap, int);
	else
		c = '%';
	if (c == 0)
		return (ft_strdup("^@"));
	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}
