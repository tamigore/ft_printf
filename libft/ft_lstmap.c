/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:06:18 by tamigore          #+#    #+#             */
/*   Updated: 2018/11/19 16:58:00 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *p;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	p = new;
	while (lst->next)
	{
		lst = lst->next;
		p->next = f(lst);
		p = p->next;
	}
	free(p);
	return (new);
}
