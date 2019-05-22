/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:24:55 by tamigore          #+#    #+#             */
/*   Updated: 2019/04/27 17:28:46 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int		ft_printf(char *format, ...)
{
	int			count;
	va_list		ap;
	t_env		*env;

	va_start(ap, format);	
	if (!(env = ft_init_env(format)))
		return (-1);
	ft_puttab(env->subs);
	if (!(env = ft_pars_arg(env, ap)))
	{
		ft_putstr(format);
		return (ft_strlen(format));
	}
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
			free(env->form->content);
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

t_env	*ft_init_env(char *str)
{
	t_env	*new;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	new->str = str;
	if (!(new->subs = ft_init_subs(str)))
		return (NULL);
	return (new);
}

t_form	*ft_init_form(t_env *env, char *str, va_list ap, int x)
{
	t_form	*new;
	int		size;

	size = 0;
	while (str[size])
		size++;
	if (!(new = (t_form *)malloc(sizeof(t_form))))
		return (NULL);
	new->size = size;
	new->indic = ft_find_indic(env->subs[x]);
	new->width = ft_find_width(env->subs[x], ap);
	new->preci = ft_find_preci(env->subs[x], ap);
	new->modif = ft_find_modif(env->subs[x]);
	printf("i : %d, j : %d\n", i, j);
	new->content = str;
	new->result = NULL;
	new->next = NULL;
	new->prev = NULL;
	if (env->form)
		new->prev = env->form;
	return (new);
}

char	**ft_init_subs(char *str)
{
	char	**tab;
	int		count;
	int		x;

	x = 0;
	count = 0;
	while (str[x])
	{
		if (str[x] == '%')
			count++;
		x++;
	}
	if (!(tab = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	if (!(tab = ft_fill_tab(tab, str)))
		return (NULL);
	return (tab);
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
