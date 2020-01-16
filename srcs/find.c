/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <tamigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:18:10 by tamigore          #+#    #+#             */
/*   Updated: 2020/01/16 16:36:37 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_find_indic(char *subs, int x, int i)
{
	char	*new;

	if (!(new = ft_strnew(5)))
		return (NULL);
	while (subs[i])
	{
		if (ft_search("- #+", subs[i]) == 1 &&
				ft_search(new, subs[i]) == 0)
			new[x++] = subs[i];
		if (subs[i] == '0' && ft_search(new, subs[i]) == 0)
		{
			if (i > 0 && ft_search("1234567890.", subs[i - 1]) == 0)
				new[x++] = subs[i];
			else if (i == 0)
				new[x++] = subs[i];
		}
		i++;
	}
	if (!(new = ft_pars_indic(new, subs)))
		return (NULL);
	return (new);
}

int		ft_find_preci(char *subs, va_list ap, int i, int x)
{
	while (subs[i])
	{
		if (subs[i] == '.')
		{
			if (subs[i + 1] == '0')
			{
				if (subs[i + 2] >= '1' && subs[i + 2] <= '9')
					i++;
				else
					return (-1);
			}
			if (subs[i + 1] >= '1' && subs[i + 1] <= '9')
				x = ft_find_preci_add(subs, i, x);
			else if (subs[i + 1] == '*')
			{
				if ((x = va_arg(ap, int)) == 0)
					return (-1);
				return (x);
			}
			else
				x = -1;
		}
		i++;
	}
	return (x);
}

int		ft_find_width(char *subs, va_list ap, int i, int x)
{
	while (subs[i])
	{
		if (subs[i] == '.')
			return (x);
		else if (subs[i] >= '1' && subs[i] <= '9')
		{
			x = 0;
			while (subs[i] >= '0' && subs[i] <= '9')
			{
				x *= 10;
				x += subs[i++] - '0';
			}
			return (x);
		}
		else if (subs[i] == '*')
			x = va_arg(ap, int);
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
	x = 0;
	while (subs[i] && subs[i] != 'h' && subs[i] != 'l' && subs[i] != 'L')
		i++;
	if (subs[i])
	{
		if ((subs[i] == subs[i + 1]) && (subs[i] == 'h' || subs[i] == 'l'))
			x = 2;
		else if (subs[i] == 'h' || subs[i] == 'l' || subs[i] == 'L')
			x = 1;
	}
	if (!(new = ft_strndup(&subs[i], x)))
		return (NULL);
	return (new);
}

char	ft_find_type(char *str)
{
	int		x;

	x = 0;
	while (ft_search(" -+#0123456789diuoxXcsfphlL.*%", str[x]) == 1)
	{
		if (ft_search("diuoxXcsfp%", str[x]) == 1)
			return (str[x]);
		x++;
	}
	return (x);
}
