/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inte_deci.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:53:51 by tamigore          #+#    #+#             */
/*   Updated: 2019/09/25 20:54:17 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*double_inte(long double f, long double frac)
{
	if (f >= 0)
	{
		if (ft_strlen(ft_doubleitoa((long long)frac, 0, 2, 0)) <
				ft_strlen(ft_doubleitoa((long long)(frac + 0.5), 0, 2, 0)) &&
				ft_strlen(ft_doubleitoa((long long)(frac + 0.5), 0, 2, 0)) == 7)
			return (ft_doubleitoa((long long)(f + 1), 0, 2, 0));
		else
			return (ft_doubleitoa((long long)f, 0, 2, 0));
	}
	else
	{
		if (ft_strlen(ft_doubleitoa(-1 * (long long)(frac), 0, 2, 0)) <
			ft_strlen(ft_doubleitoa(-1 * (long long)(frac - 0.5), 0, 2, 0)) &&
			ft_strlen(ft_doubleitoa(-1 * (long long)(frac - 0.5), 0, 2, 0)) > 6)
			return (ft_doubleitoa(-1 * (long long)(f - 1), 0, 2, 0));
		else
			return (ft_doubleitoa(-1 * (long long)f, 0, 2, 0));
	}
}

char		*double_deci(long double f, long double frac)
{
	if (f >= 0)
	{
		if (ft_strlen(ft_doubleitoa((long long)(frac), 0, 2, 0)) <
			ft_strlen(ft_doubleitoa((long long)(frac + 0.5), 0, 2, 0)) &&
			ft_strlen(ft_doubleitoa((long long)(frac + 0.5), 0, 2, 0)) > 6)
			return (ft_strdup("0"));
		else
			return (ft_doubleitoa((long long)(frac + 0.5), 0, 2, 0));
	}
	else
	{
		if (ft_strlen(ft_doubleitoa(-1 * (long long)(frac), 0, 2, 0)) <
			ft_strlen(ft_doubleitoa(-1 * (long long)(frac - 0.5), 0, 2, 0)) &&
			ft_strlen(ft_doubleitoa(-1 * (long long)(frac - 0.5), 0, 2, 0)) > 6)
			return (ft_strdup("0"));
		else
			return (ft_doubleitoa(-1 * (long long)(frac - 0.5), 0, 2, 0));
	}
}
