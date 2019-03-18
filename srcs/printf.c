/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:32:11 by tamigore          #+#    #+#             */
/*   Updated: 2019/01/07 17:51:58 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "stdio.h"

int		main(void)
{
    int i;
    int j;

    i = printf("lol, pour %d %s tu as combien de %c\n", 201, "kokonut", 'k');
	j = ft_printf("lol, pour %d %s tu as combien de %c\n", 201, "kokonut", 'k');
    printf("i = %d ; j = %d", i, j);
    return (0);
}

int 	ft_printf(char * format, ...)
{
    va_list     ap;
    t_env       *env;

    va_start(ap, format);
    if (!(env = ft_init_env(format)))
        return (-1);
    va_end(ap);
    return (0);
}

t_env   *ft_init_env(char *str)
{
    t_env   *new;

    if (!(new = (t_env *)malloc(sizeof(t_env))))
        return (NULL);
    new->str = str;
    if (!(new->subs = ft_init_subs(str)))
        return (NULL);
    new->form = ft_init_form(str);
    return (new);
}

char    **ft_init_subs(char *str)
{
    char    **tab;
    int     i;
    int     count;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] == '%')
            count++;
        i++;
    }
    if (!(tab = (char **)malloc(sizeof(char *))))
        return (NULL);

    return (tab);
}

t_form  ft_init_form(char *str)
{
    t_form  new;
    int     size;

    size = 0;
    while(str[size] != ' ')
        size++;
    new.type = NULL;
    new.size = size;
    new.content = str;
    new.next = NULL;
    new.prev = NULL;
    return (new);
}
