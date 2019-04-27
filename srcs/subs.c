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

#include "printf.h"

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
