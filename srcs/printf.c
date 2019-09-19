/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:12:02 by tamigore          #+#    #+#             */
/*   Updated: 2019/09/19 19:37:26 by tamigore         ###   ########.fr       */
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
	{
		ft_freeall(env, 0);
		return (0);
	}
	if (!env->form)
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
	while (PREV)
		env->form = PREV;
	if (!option(env, 1) || !ft_modif(env))
		ft_free_exit(env, 0);
	while (env->form->prev)
		env->form = env->form->prev;
	if (!option(env, 2))
		ft_free_exit(env, 0);
}

int		ft_print_all(t_env *env, int x, int count)
{
	while (env->str[x])
	{
		if (env->str[x] == '%' && ft_strsearch("diouxXcspf%",
					ft_find_type(&env->str[x + 1])) == 1)
		{
			if (TYPE == 'c' && CONTENT[0] == '\0')
			{
				if (ft_strsearch(INDIC, '-') == 0)
					ft_putstr(RES);
				write(1, "\0", 1);
				count++;
				if (ft_strsearch(INDIC, '-') == 1)
					ft_putstr(RES);
			}
			else
				ft_putstr(RES);
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
