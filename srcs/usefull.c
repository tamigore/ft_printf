/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <tamigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:25:11 by tamigore          #+#    #+#             */
/*   Updated: 2020/01/20 15:39:40 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_count_type(char *str)
{
	int					x;

	x = 0;
	while (ft_search(" -+#0123456789diuoxXcsfphlL.*%", str[x]) == 1)
	{
		if (ft_search("diuoxXcsfp%", str[x]) == 1)
			return (x + 1);
		x++;
	}
	return (x);
}

char			*ft_pars_indic(char *str, char *subs)
{
	if (ft_search(str, '+') == 1 && ft_search(str, ' ') == 1)
		if (!(str = ft_rmchar(str, ' ')))
			return (NULL);
	if (ft_search(str, '0') == 1 && ft_search(str, '-') == 1)
		if (!(str = ft_rmchar(str, '0')))
			return (NULL);
	if (ft_search("diucsp%", ft_find_type(subs)) == 1 &&
			ft_search(str, '#') == 1)
		if (!(str = ft_rmchar(str, '#')))
			return (NULL);
	return (str);
}

char			*ft_check_str(char *str, t_env *env)
{
	int		x;
	char	*tmp;

	x = 0;
	if (!(tmp = ft_strdup(str)))
		return (NULL);
	while (tmp[x])
	{
		if (tmp[x] == '%')
		{
			if (ft_search("diouxXcspf%", ft_find_type(&tmp[x + 1])) != 1)
			{
				free(tmp);
				free(env);
				return (NULL);
			}
			else
				x += ft_count_type(&tmp[x + 1]);
		}
		x++;
	}
	return (tmp);
}

char			*ft_arg_point(va_list ap, int x)
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
	else if (!(str = ft_free_join("0x", str, 2)))
		return (NULL);
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char			*strjoin_double_add(char *inte, char *deci, int i)
{
	i = ft_strlen(inte) - 1;
	if (deci[0] >= '5')
	{
		while (inte[i] == '9' && i > 0)
			inte[i--] = '0';
		if (i == 0 && inte[i] == '9')
		{
			inte[i] = '0';
			if (!(inte = ft_free_join("1", inte, 2)))
				return (NULL);
		}
		else
			inte[i]++;
	}
	free(deci);
	return (inte);
}
