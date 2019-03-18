/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:15:10 by tamigore          #+#    #+#             */
/*   Updated: 2018/11/19 16:41:15 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		j;
	int		i;
	char	*p;

	j = 0;
	i = ft_strlen(s);
	while (j <= i)
	{
		if (s[j] == (char)c)
		{
			p = (char *)&s[j];
			return (p);
		}
		j++;
	}
	return (NULL);
}
