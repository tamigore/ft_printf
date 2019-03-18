/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:28:00 by tamigore          #+#    #+#             */
/*   Updated: 2018/11/19 17:08:29 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	char	**ft_malloctab(char **tab, const char *s, char c)
{
	int		j;
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] != c && s[i])
		{
			j++;
			i++;
		}
		if (j != 0)
		{
			if (!(tab[x] = (char *)malloc(j + 1)))
				return (NULL);
			x++;
		}
		if (s[i])
			i++;
	}
	return (tab);
}

static	void	ft_filtab(char **tab, const char *s, char c)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i] != c && s[i])
				tab[x][j++] = s[i++];
			tab[x++][j] = '\0';
		}
		if (s[i])
			i++;
	}
	tab[x] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			j++;
		i++;
	}
	if (!(tab = (char **)malloc(sizeof(char *) * (j + 1))))
		return (NULL);
	if (!(tab = ft_malloctab(tab, s, c)))
		return (NULL);
	ft_filtab(tab, s, c);
	return (tab);
}
