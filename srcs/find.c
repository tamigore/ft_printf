/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:18:10 by tamigore          #+#    #+#             */
/*   Updated: 2019/08/08 18:51:27 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_find_indic(char *subs)
{
	char	*new;
	int		x;
	int		i;

	i = 0;
	x = 0;
	new = ft_strnew(5);
	while (subs[i])
	{
		if (ft_strsearch("- #+", subs[i]) == 1 &&
				ft_strsearch(new, subs[i]) == 0)
			new[x++] = subs[i];
		if (subs[i] == '0' && ft_strsearch(new, subs[i]) == 0)
		{
			if (i > 0 && ft_strsearch("1234567890.", subs[i - 1]) == 0)
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
			if (subs[i + 1] >= '1' && subs[i + 1] <= '9')
			{
				if (x < 0)
					x = 0;
				while (subs[i + 1] >= '0' && subs[i + 1] <= '9')
				{
					x *= 10;
					x += subs[i++ + 1] - '0';
				}
				return (x);
			}
			else if (subs[i + 1] == '*')
				return (va_arg(ap, int));
			else
				x = -1;
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
	while (ft_strsearch(" -+#0123456789diuoxXcsfphl.*%", str[x]) == 1)
	{
		if (ft_strsearch("diuoxXcsfp%", str[x]) == 1)
			return (str[x]);
		x++;
	}
	return (x);
}
