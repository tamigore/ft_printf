/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:25:11 by tamigore          #+#    #+#             */
/*   Updated: 2019/08/08 17:53:18 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_type(char *str)
{
	int					x;

	x = 0;
	while (ft_strsearch(" -+#0123456789diuoxXcsfphl.*%", str[x]) == 1)
	{
		if (ft_strsearch("diuoxXcsfp%", str[x]) == 1)
			return (x + 1);
		x++;
	}
	return (x);
}
/*
char	*ft_strcat_float(char *integer, char *decimal)
{
	char	*str;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!(str = (char *)malloc(ft_strlen(integer) + ft_strlen(decimal))))
		return (NULL);
	while (integer[x])
	{
		str[x] = integer[x];
		x++;
	}
	str[x++] = '.';
	while (decimal[y])
		str[x++] = decimal[y++];
	str[x] = '\0';
	return (str);
}
*/
char	*ft_pars_indic(char *str, char *subs)
{
	if (ft_strsearch(str, '+') == 1 && ft_strsearch(str, ' ') == 1)
		if (!(str = ft_rmchar(str, ' ')))
			return (NULL);
	if (ft_strsearch(str, '0') == 1 && ft_strsearch(str, '-') == 1)
		if (!(str = ft_rmchar(str, '0')))
			return (NULL);
	if (ft_strsearch("diucsp%", ft_find_type(subs)) == 1 &&
			ft_strsearch(str, '#') == 1)
		if (!(str = ft_rmchar(str, '#')))
			return (NULL);
	return (str);
}

char	*ft_check_str(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] == '%')
		{
			if (ft_strsearch("diouxXcspf%", ft_find_type(&str[x + 1])) != 1)
				str = ft_free_rmstr(str, x, x + ft_count_type(&str[x + 1]));
			else
				x += ft_count_type(&str[x + 1]);
		}
		x++;
	}
	return (str);
}

char	*ft_arg_point(va_list ap, int x)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = ft_itoa_base(va_arg(ap, unsigned long long int), 16)))
		return (NULL);
	if (str[0] == '0')
	{
		free(str);
		if (x == -1)
			return (ft_strdup("0x"));
		return (ft_strdup("0x0"));
	}
	else
		str = ft_free_join("0x", str, 2);
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}
