/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <tamigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:12:02 by tamigore          #+#    #+#             */
/*   Updated: 2019/11/24 17:48:42 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	int			count;
	va_list		ap;
	t_env		*env;

	va_start(ap, format);
	if (!ft_strlen(format))
		return (0);
	if (!(env = ft_init_env(format, ap, 0)) || !ft_erorrcheck(env, 0, 0))
	{
		ft_freeall(env, 0);
		return (0);
	}
	if (!env->f)
	{
		count = ft_strlen(env->str);
		ft_freeall(env, 0);
		return (count);
	}
	ft_apply(env);
	count = ft_print_all(env, 0, 0);
	ft_freeall(env, 0);
	va_end(ap);
	return (count);
}

void	ft_apply(t_env *env)
{
	while ((env->f->b))
		env->f = (env->f->b);
	if (!option(env, 1) || !ft_modif(env))
		ft_free_exit(env, 0);
	while (env->f->b)
		env->f = env->f->b;
	if (!option(env, 2))
		ft_free_exit(env, 0);
}

int		ft_print_all(t_env *env, int x, int count)
{
	while (env->str[x])
	{
		if (env->str[x] == '%' && ft_search("diouxXcspf%",
					ft_find_type(&env->str[x + 1])) == 1)
		{
			if ((env->f->t) == 'c' && (env->f->c)[0] == '\0')
				count = ft_print_all_add(env, count);
			else
				ft_putstr((env->f->r));
			count += (env->f->s);
			x += ft_count_type(&(env->str[x + 1])) + 1;
			if ((env->f->n))
				env->f = env->f->n;
		}
		else
		{
			ft_putchar(env->str[x++]);
			count++;
		}
	}
	while ((env->f->b))
		env->f = (env->f->b);
	return (count);
}

char	**ft_fill_tab(char **tab, char *str)
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
			if (!(tab[x] = ft_strndup(&str[i], ft_subs_len(str, i))))
				return (NULL);
			x++;
			i += ft_subs_len(str, i) - 1;
		}
		i++;
	}
	tab[x] = NULL;
	return (tab);
}

int		ft_subs_len(char *str, int i)
{
	static const char	*cut = "diuoxXcsfp%";
	int					count;
	int					x;

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
