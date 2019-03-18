/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:13:32 by tamigore          #+#    #+#             */
/*   Updated: 2018/11/19 17:07:46 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*p;
	int		i;
	int		j;
	int		n;

	i = 0;
	n = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j--;
	if (j < i)
	{
		i = 1;
		j = 0;
	}
	if (!(p = (char *)malloc(j - i + 2)))
		return (NULL);
	while (i <= j)
		p[n++] = s[i++];
	p[n] = '\0';
	return (p);
}
