/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:32:11 by tamigore          #+#    #+#             */
/*   Updated: 2019/04/21 19:25:27 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "stdio.h"

int		main(void)
{
    int i;
    int j;

    i = printf("lol, pour %5.6d %s tu as combien de %c, noix de coco ~ %f\n", -420, "kokonut", 'k', 324653.2375);
	j = ft_printf("lol, pour %5.6d %s tu as combien de %c, noix de coco ~ %f\n", -420, "kokonut", 'k', 324653.2375);
    printf("i = %d ; j = %d", i, j);
    return (0);
}

int 	ft_printf(char * format, ...)
{
    int         count;
    va_list     ap;
    t_env       *env; 

    va_start(ap, format);
    if (!(env = ft_init_env(format)))
        return (-1);
    ft_puttab(env->subs);
    if (!(env = ft_pars_arg(env, ap)))
        return (-1);
    if ((count = ft_print_all(env)) < 0)
        return (count);
    va_end(ap);
    return (count);
}

int     ft_print_all(t_env *env)
{
    int count;
    int x;

    x = 0;
    count = 0;
    while (env->form->prev)
        env->form = env->form->prev;
    while (env->str[x])
    {
        if (env->str[x] == '%' && env->str[x + 1] != '%')
        {
            ft_putstr(env->form->content);
            count += env->form->size;
            env->form = env->form->next;
            x += ft_count(&(env->str[x])) + 1;
        }
        else if (env->str[x] == '%' && env->str[x + 1] == '%')
        {
            ft_putchar('%');
            x += 2;
            count++;
        }
        else
        {
            ft_putchar(env->str[x++]);
            count++;
        }
    }
    return (count);
}

t_env   *ft_init_env(char *str)
{
    t_env   *new;

    if (!(new = (t_env *)malloc(sizeof(t_env))))
        return (NULL);
    new->str = str;
    if (!(new->subs = ft_init_subs(str)))
        return (NULL);
    return (new);
}

t_form  *ft_init_form(char *str)
{
    t_form  *new;
    int     size;

    size = 0;
    while(str[size])
        size++;
    if (!(new = (t_form *)malloc(sizeof(t_form))))
        return (NULL);
    new->size = size;
    new->width = 0;
    new->preci = 0;
    new->content = str;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}

char    **ft_init_subs(char *str)
{
    char            **tab;
    int             count;
    int             x;

    x = 0;
    count = 0;
    while (str[x])
    {
        if (str[x] == '%')
        {
            x++;
            if (str[x] != '%')
                count++;
        }
        x++;
    }
    if (!(tab = (char **)malloc(sizeof(char *) * (count + 1))))
        return (NULL);
    if (!(tab = ft_fill_tab(tab, str)))
        return (NULL);
    return (tab);
}

char    **ft_fill_tab(char **tab, char *str)
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
            if (str[i] != '%')
            {
                if (!(tab[x] = ft_strndup(&str[i], ft_subs_len(str, i))))
                    return (NULL);
                x++;
            }
        }
        i++;
    }
    tab[x] = NULL;
    return (tab);
}

int     ft_subs_len(char *str, int i)
{
    static  const   char    *cut = "diuoxXcsfeEgGpn";
    int                     count;
    int                     x;

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
