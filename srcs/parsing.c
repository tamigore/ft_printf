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
#include "stdio.h"

t_env   *ft_pars_arg(t_env *env, va_list ap)
{
    int     x;
    char    c;

    x = 0;
    while(env->subs[x])
    {
        c = ft_pars_char(env->subs[x++]);
        if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
            ft_arg_int(env, ap, x);
        else if (c == 'f')
            ft_arg_float(env, ap, x);
        else if (c == 'c')
            ft_arg_char(env, ap, x);
        else if (c == 's')
            ft_arg_str(env, ap, x);
        else if (c == 'p')
            ft_arg_point(env, ap, x);
        ft_putstr(env->form->content);
        ft_putchar('\n');
    }
    return (env);
}

char    *ft_arg_char(t_env *env, va_list ap, int x)
{
    char    str[2];

    str[0] = va_arg(ap, int);
    str[1] = '\0';
    if (x == 1)
    {
        if (!(env->form = ft_init_form(str)))
            return (NULL);
    }
    else
    {
        if (!(env->form->next = ft_init_form(str)))
            return (NULL);;
        env->form->next->prev = env->form;
        env->form = env->form->next;
    }
    return (env->form->content);
}

char    *ft_arg_int(t_env *env, va_list ap, int x)
{
    if (x == 1)
    {
        if (!(env->form = ft_init_form(ft_itoa(va_arg(ap, int)))))
            return (NULL);
    }
    else
    {
        if (!(env->form->next = ft_init_form(ft_itoa(va_arg(ap, int)))))
            return (NULL);;
        env->form->next->prev = env->form;
        env->form = env->form->next;
    }
    return (env->form->content);
}

char    *ft_arg_str(t_env *env, va_list ap, int x)
{
    if (x == 1)
    {
        if (!(env->form = ft_init_form(va_arg(ap, char *))))
            return (NULL);
    }
    else
    {
        if (!(env->form->next = ft_init_form(va_arg(ap, char *))))
            return (NULL);
        env->form->next->prev = env->form;
        env->form = env->form->next;
    }
    return (env->form->content);
}

char    *ft_arg_point(t_env *env, va_list ap, int x)
{
    if (x == 1)
    {
        if (!(env->form = ft_init_form(va_arg(ap, char *))))
            return (NULL);
    }
    else
    {
        if (!(env->form->next = ft_init_form(va_arg(ap, char *))))
            return (NULL);
        env->form->next->prev = env->form;
        env->form = env->form->next;
    }
    return (env->form->content);
}

char    *ft_arg_float(t_env *env, va_list ap, int x)
{
    t_form  *copy;

    if (!(copy= ft_init_form(ft_float_to_char(va_arg(ap, double)))))
        return (NULL);
    if (x == 0)
        env->form = copy;
    else
    {
        env->form->next = copy;
        copy->prev = env->form;
        env->form = env->form->next;
    }
    return (env->form->content);
}

char    *ft_float_to_char(float x)
{
    char    *str;

    if (x == 0)
        str = NULL;
    else
        str = NULL;
    return (str);
}
