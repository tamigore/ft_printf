/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inte_deci.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <tamigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:53:51 by tamigore          #+#    #+#             */
/*   Updated: 2020/01/20 17:59:18 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			double_len(long double f)
{
	int		i;

	i = 1;
	while (f > 10)
	{
		i++;
		f /= 10;
	}
	return (i);
}

char		*double_inte(long double f, long double frac, int len)
{
	if (f >= 0)
	{
		if ((double_len(frac) < double_len(frac + 0.5)) &&
			(double_len(frac + 0.5) > len))
			return (ft_doubleitoa((long long)(f + 1), 0, 2, 0));
		else
			return (ft_doubleitoa((long long)f, 0, 2, 0));
	}
	else
	{
		if ((double_len(-1 * frac) < double_len(-1 * frac + 0.5)) &&
			(double_len(-1 * frac + 0.5) > len))
			return (ft_doubleitoa(-1 * (long long)(f - 1), 0, 2, 0));
		else
			return (ft_doubleitoa(-1 * (long long)f, 0, 2, 0));
	}
}

char		*double_deci(long double f, long double frac, int len)
{
	if (f >= 0)
	{
		if ((double_len(frac) < double_len(frac + 0.5)) &&
			(double_len(frac + 0.5) > len))
			return (ft_strdup("0"));
		else
			return (ft_doubleitoa((long long)(frac + 0.5), 0, 2, 0));
	}
	else
	{
		if ((double_len(-1 * frac) < double_len(-1 * frac + 0.5)) &&
			(double_len(-1 * frac + 0.5) > len))
			return (ft_strdup("0"));
		else
			return (ft_doubleitoa(-1 * (long long)(frac - 0.5), 0, 2, 0));
	}
}
