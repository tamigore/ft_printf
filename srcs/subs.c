/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:24:33 by tamigore          #+#    #+#             */
/*   Updated: 2019/04/27 17:10:33 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_find_indic(char *subs)
{
	char	*new;
	int		i;

	i = 0;
	while (subs[i] == '-' || subs[i] == '+' || subs[i] == ' ' || subs[i] == '#')
		i++;
	if (!(new = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (subs[i] == '-' || subs[i] == '+' || subs[i] == ' ' || subs[i] == '#')
	{
		new[i] = subs[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int		ft_find_preci(char *subs, va_list ap)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (subs[i])
	{
		if (subs[i] == '.')
		{
			if (subs[i + 1] >= '1' && subs[i + 1] <= '9')
			{
				while (subs[i + 1] >= '0' && subs[i + 1] <= '9')
				{
					x *= 10;
					x += subs[i++ + 1] - '0';
				}
				return (x);
			}
			else if (subs[i + 1] == '*')
				return (va_arg(ap, int));
		}
		i++;
	}
	return (x);
}

int		ft_find_width(char *subs, va_list ap)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (subs[i])
	{
		if (subs[i] == '.')
			return (0);
		else if (subs[i] >= '1' && subs[i] <= '9')
		{
			while (subs[i] >= '0' && subs[i] <= '9')
			{
				x *= 10;
				x += subs[i++] - '0';
			}
			return (x);
		}
		else if (subs[i] == '*')
			return (va_arg(ap, int));
		i++;
	}
	return (x);
}

char	*ft_find_modif(char *subs)
{
	char	*new;
	int		i;
	int		x;

	i = 0;
	while (subs[i] && (subs[i] != 'h' || subs[i] != 'l' || subs[i] != 'L'))
		i++;
	if ((subs[i] == subs[i + 1]) && (subs[i] == 'h' || subs[i] == 'l'))
		x = 2;
	else if (subs[i] == 'h' || subs[i] == 'l')
		x = 1;
	else
		x = 0;
	if (!(new = ft_strndup(&subs[i], x)))
		return (NULL);
	return (new);
}

int		ft_err(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_find_type(&str[i + 1]) == 0)
				return (0);
			i += ft_count(&str[i + 1]) + 1;
		}
		i++;
	}
	return (1);
}
