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

	x = 1;
	if (!(env->form = ft_init_fform(env, ap)))
		return (NULL);
	while (env->subs[x])
	{	
		c = ft_pars_char(env->subs[x]);
		if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
			env->form->next = ft_arg_int(env, ap, x, c);
		else if (c == 'f')
			env->form->next = ft_arg_float(env, ap, x);
		else if (c == 'c')
			env->form->next = ft_arg_char(env, ap, x, 0);
		else if (c == 's')
			env->form->next = ft_arg_str(env, ap, x);
		else if (c == 'p')
			env->form->next = ft_arg_point(env, ap, x);
		else if (c == '%')
			env->form->next = ft_arg_char(env, ap, x, '%');
		x++;
		env->form->next->prev = env->form;
		env->form = env->form->next;
		ft_putstr(env->form->content);
		ft_putchar('\n');
	}
	while (env->form->prev)
		env->form = env->form->prev;
	return (env);
}

t_form	*ft_init_fform(t_env *env, va_list ap)
{
	char	c;

	if (env->subs[0])
	{
		c = ft_pars_char(env->subs[0]);
		if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
			env->form = ft_arg_int(env, ap, 0, c);
		else if (c == 'f')
			env->form = ft_arg_float(env, ap, 0);
		else if (c == 'c')
			env->form = ft_arg_char(env, ap, 0, 0);
		else if (c == 's')
			env->form = ft_arg_str(env, ap, 0);
		else if (c == 'p')
			env->form = ft_arg_point(env, ap, 0);
		else if (c == '%')
			env->form = ft_arg_char(env, ap, 0, '%');
		ft_putstr(env->form->content);
		ft_putchar('\n');
		return (env->form);
	}
	return (NULL);
}

t_form	*ft_arg_char(t_env *env, va_list ap, int x, char c)
{
	char	*str;
	int		count;
	int		i;

	count = 2;
	i = ft_find_width(env->subs[x], ap);
	ft_find_preci(env->subs[x], ap);
	if (c == 0)
		c = (char)va_arg(ap, int);
	if (i > 0)
		count = i + 1;
	if (!(str = (char *)malloc(sizeof(char) * count)))
		return (NULL);
	count = 0;
	if (env->subs[x][0] == '-')
	{
		str[count++] = c;
		while (count < i)
			str[count++] = ' ';
	}
	else
	{
		while (count < i - 1)
			str[count++] = ' ';
		str[count++] = c;
	}
	str[count] = '\0';
	return (ft_init_form(str, i, 0));
}

t_form	*ft_arg_int(t_env *env, va_list ap, int x, char c)
{
	char	*str;
	char	*cpy;
	int		tab[2];
	int		count;

	tab[0] = ft_find_width(env->subs[x], ap);
	tab[1] = ft_find_preci(env->subs[x], ap);
	cpy = ft_itoa_conv(va_arg(ap, int), c);
	if (ft_strlen(cpy) >= tab[0] && ft_strlen(cpy) >= tab[1])
		count = ft_strlen(cpy);
	else if (tab [0] >= tab[1] && tab[0] >= ft_strlen(cpy))
		count = tab[0];
	else if (tab [0] >= tab[1] && tab[0] >= ft_strlen(cpy))
		count = tab[1];
	if (count == ft_strlen(cpy) && env->subs[x][0] == )
	return (ft_init_form(cpy, tab[0], tab[1]));
}

t_form	*ft_arg_str(t_env *env, va_list ap, int x)
{
	int		i;
	int		j;

	i = ft_find_width(env->subs[x], ap);
	j = ft_find_preci(env->subs[x], ap);
	return (ft_init_form(va_arg(ap, char *), i, j));
}

t_form	*ft_arg_point(t_env *env, va_list ap, int x)
{
	int		i;
	int		j;

	i = ft_find_width(env->subs[x], ap);
	j = ft_find_preci(env->subs[x], ap);
	return (ft_init_form(ft_itoa_conv(va_arg(ap, int), 'x'), i, j));
}

t_form	*ft_arg_float(t_env *env, va_list ap, int x)
{
	int		i;
	int		j;

	i = ft_find_width(env->subs[x], ap);
	j = ft_find_preci(env->subs[x], ap);
	return (ft_init_form(ft_float_to_char(va_arg(ap, double)), i, j));
}
