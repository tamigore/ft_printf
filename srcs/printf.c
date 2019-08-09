/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:12:02 by tamigore          #+#    #+#             */
/*   Updated: 2019/08/09 15:20:01 by tamigore         ###   ########.fr       */
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
	if (!(env = ft_init_env(format, ap, 0)) || ft_erorrcheck(env, 0, 0) < 0)
		ft_free_exit(env);
	if (!env->form)
	{
		count = ft_strlen(env->str);
		ft_freeall(env);
		return (count);
	}
	while (env->form->prev)
		env->form = env->form->prev;
	if (!option(env, 1) || !ft_modif(env))
		ft_free_exit(env);
	while (env->form->prev)
		env->form = env->form->prev;
	if (!option(env, 2))
		ft_free_exit(env);
	count = ft_print_all(env);
	ft_freeall(env);
	va_end(ap);
	return (count);
}

void	ft_freeall(t_env *env)
{
	t_form	*tmp;
	int		x;

	if (env)
	{
		x = 0;
		while (env->form)
		{
			if (INDIC)
				free(INDIC);
			if (MODIF)
				free(MODIF);
			if (CONTENT)
				free(CONTENT);
			if (RES)
				free(RES);
			tmp = env->form;
			env->form = env->form->next;
			free(tmp);
		}
		free(env->str);
		while (env->subs[x])
			free(env->subs[x++]);
		free(env->subs);
		free(env);
	}
}

void	ft_free_exit(t_env *env)
{
	t_form	*tmp;
	int		x;

	if (env->form)
	{
		x = 0;
		while (env->form)
		{
			if (INDIC)
				free(INDIC);
			if (MODIF)
				free(MODIF);
			if (CONTENT)
				free(CONTENT);
			if (RES)
				free(RES);
			tmp = env->form;
			env->form = env->form->next;
			free(tmp);
		}
		free(env->str);
		while (env->subs[x])
			free(env->subs[x++]);
		free(env->subs);
		free(env);
	}
	exit(0);
}

int		ft_print_all(t_env *env)
{
	int count;
	int x;

	x = 0;
	count = 0;
	while (env->str[x])
	{
		if (env->str[x] == '%' && ft_strsearch("diouxXcspf%",
					ft_find_type(&env->str[x + 1])) == 1)
		{
			ft_putstr(RES);
			if (TYPE == 'c' && CONTENT[0] == '\0')
				count++;
			count += SIZE;
			x += ft_count_type(&(env->str[x + 1])) + 1;
			if (NEXT)
				env->form = env->form->next;
		}
		else
		{
			ft_putchar(env->str[x++]);
			count++;
		}
	}
	while (PREV)
		env->form = PREV;
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
