/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:06:22 by tamigore          #+#    #+#             */
/*   Updated: 2018/11/19 16:58:23 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*p;

	if (!(p = malloc(sizeof(*p))))
		return (NULL);
	if (content == NULL)
	{
		p->content = NULL;
		p->content_size = 0;
	}
	else
	{
		if (!(p->content = malloc(content_size)))
			return (NULL);
		p->content_size = content_size;
		ft_memcpy(p->content, content, content_size);
	}
	p->next = NULL;
	return (p);
}
