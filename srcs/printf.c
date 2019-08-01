/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:12:02 by tamigore          #+#    #+#             */
/*   Updated: 2019/08/01 12:44:30 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	int			count;
	va_list		ap;
	t_env		*env;

	va_start(ap, format);
	if (ft_strlen(format) == 0)
		return (0);
	if (!(env = ft_init_env(format, ap)))
		return (-1);
	if (!env->form || ft_erorrcheck(env) < 0)
		return (ft_strlen(env->str));
//	ft_putnbr(PRECI);
//	ft_putstr(": preci\n");
	option(env, 1);
//	ft_putstr(RESULT);
//	ft_putstr(": opt1\n");
	while (env->form->prev)
		env->form = env->form->prev;
	if (!ft_modif(env))
		return (-1);
//	ft_putstr(RESULT);
//	ft_putstr(": modif\n");
	option(env, 2);
//	ft_putstr(RESULT);
//	ft_putstr(": opt2\n");
	while (env->form->prev)
		env->form = env->form->prev;
	count = ft_print_all(env);
	ft_freeall(env);
	va_end(ap);
	return (count);
}

void	ft_freeall(t_env *env)
{
	t_form	*tmp;
	int	x;

	if (env->form)
	{
		x = 0;
		while (env->form)
		{
			free(INDIC);
			free(MODIF);
			free(CONTENT);
			free(RESULT);
			tmp = env->form->next;
			free(env->form);
			env->form = tmp;
		}
		free(env->str);
		while (env->subs[x])
			free(env->subs[x++]);
		free(env);
	}
}

int		ft_print_all(t_env *env)
{
	int count;
	int x;

	x = 0;
	count = 0;
	while (env->str[x])
	{
		if (env->str[x] == '%' && ft_strsearch("diouxXcspf%", ft_find_type(&env->str[x + 1])) == 1)
		{
			ft_putstr(RESULT);
			count += SIZE;
			if (ft_strcmp(CONTENT, "^@") == 0 && TYPE == 'c')
				count--;
			env->form = env->form->next;
			x += ft_count_type(&(env->str[x + 1])) + 1;
		}
		else
		{
			ft_putchar(env->str[x++]);
			count++;
		}
	}
	return (count);
}

int		ft_err(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_strsearch("diouxXcpsf%", ft_find_type(&str[i + 1])) == 0)
				return (ft_find_type(&str[i + 1]));
			i += ft_count_type(&str[i + 1]) + 1;
		}
		i++;
	}
	return (1);
}
