/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:25:02 by tamigore          #+#    #+#             */
/*   Updated: 2019/04/27 17:28:48 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_env	*ft_pars_arg(t_env *env, va_list ap)
{
	int		x;
	char	c;

	x = 0;
	while (env->subs[x])
	{
		c = ft_pars_char(env->subs[x]);
		if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
			ft_arg_int(env, ap, x, c);
		else if (c == 'f')
			ft_arg_float(env, ap, x);
		else if (c == 'c')
			ft_arg_char(env, ap, x);
		else if (c == 's')
			ft_arg_str(env, ap, x);
		else if (c == 'p')
			ft_arg_point(env, ap, x);
		x++;
		ft_putstr(env->form->content);
		ft_putchar('\n');
	}
	return (env);
}

t_form	*ft_arg_char(t_env *env, va_list ap, int x)
{
	char	str[2];
	int		i;
	int		j;

	i = ft_find_width(env->subs[x], ap);
	j = ft_find_preci(env->subs[x], ap);
	str[0] = va_arg(ap, int);
	str[1] = '\0';
	if (x == 0)
	{
		if (!(env->form = ft_init_form(str, i, j)))
			return (NULL);
	}
	else
	{
		if (!(env->form->next = ft_init_form(str, i, j)))
			return (NULL);
		env->form->next->prev = env->form;
		env->form = env->form->next;
	}
	return (env->form);
}

t_form	*ft_arg_int(t_env *env, va_list ap, int x, char c)
{
	int		i;
	int		j;

	i = ft_find_width(env->subs[x], ap);
	j = ft_find_preci(env->subs[x], ap);
	if (x == 0)
	{
		if (!(env->form = ft_init_form(ft_itoa(va_arg(ap, int), c), i, j)))
			return (NULL);
	}
	else
	{
		if (!(env->form->next = ft_init_form(ft_itoa(va_arg(ap, int), c), i, j)))
			return (NULL);
		env->form->next->prev = env->form;
		env->form = env->form->next;
	}
	return (env->form);
}

t_form	*ft_arg_str(t_env *env, va_list ap, int x)
{
	int		i;
	int		j;

	i = ft_find_width(env->subs[x], ap);
	j = ft_find_preci(env->subs[x], ap);
	if (x == 0)
	{
		if (!(env->form = ft_init_form(va_arg(ap, char *), i, j)))
			return (NULL);
	}
	else
	{
		if (!(env->form->next = ft_init_form(va_arg(ap, char *), i, j)))
			return (NULL);
		env->form->next->prev = env->form;
		env->form = env->form->next;
	}
	return (env->form);
}

t_form	*ft_arg_point(t_env *env, va_list ap, int x)
{
	int		i;
	int		j;

	i = ft_find_width(env->subs[x], ap);
	j = ft_find_preci(env->subs[x], ap);
	if (x == 0)
	{
		if (!(env->form = ft_init_form(va_arg(ap, char *), i, j)))
			return (NULL);
	}
	else
	{
		if (!(env->form->next = ft_init_form(va_arg(ap, char *), i, j)))
			return (NULL);
		env->form->next->prev = env->form;
		env->form = env->form->next;
	}
	return (env->form);
}

t_form	*ft_arg_float(t_env *env, va_list ap, int x)
{
	t_form	*copy;
	int		i;
	int		j;

	i = ft_find_width(env->subs[x], ap);
	j = ft_find_preci(env->subs[x], ap);
	if (!(copy = ft_init_form(ft_float_to_char(va_arg(ap, double)), i, j)))
		return (NULL);
	if (x == 0)
		env->form = copy;
	else
	{
		env->form->next = copy;
		copy->prev = env->form;
		env->form = env->form->next;
	}
	return (env->form);
}
