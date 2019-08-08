/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:21:51 by tamigore          #+#    #+#             */
/*   Updated: 2019/08/08 14:30:42 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**ft_fill_tab(char **tab, char *str)
{
	int x;
	int i;

	x = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!(tab[x] = ft_strndup(&str[i], ft_subs_len(str, i))))
				return (NULL);
			x++;
			i += ft_subs_len(str, i) - 1;
		}
		i++;
	}
	tab[x] = NULL;
	return (tab);
}

int		ft_subs_len(char *str, int i)
{
	static const char	*cut = "diuoxXcsfp%";
	int					count;
	int					x;

	count = 1;
	while (str[i])
	{
		x = 0;
		while (cut[x])
		{
			if (cut[x] == str[i])
				return (count);
			x++;
		}
		count++;
		i++;
	}
	return (-1);
}

char	*ft_free_join(char *s1, char *s2, int x)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(s1, s2)))
		return (NULL);
	if (x == 1)
		free(s1);
	else if (x == 2)
		free(s2);
	else if (x == 3)
	{
		free(s1);
		free(s2);
	}
	return (tmp);
}
