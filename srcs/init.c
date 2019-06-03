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
	if ((ft_err(format) == 0) ||!(env = ft_init_env(format, ap)))
		return (-1);
	if (!env->form)
		return (ft_strlen(format));
	while (env->form)
	{
		if (!env->form->next)
			break ;
		env->form = env->form->next;
	}
	while (env->form->prev)
		env->form = env->form->prev;	
	while (env->form)
	{
		if (!(RESULT = ft_find_result(env)))
			return (-1);
		SIZE = ft_strlen(RESULT);
		if (!env->form->next)
			break ;
		env->form = env->form->next;
	}
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
		if (env->str[x] == '%')
		{
			ft_putstr(RESULT);
			count += SIZE;
			env->form = env->form->next;
			x += ft_count(&(env->str[x + 1])) + 2;
		}
		else
		{
			ft_putchar(env->str[x++]);
			count++;
		}
	}
	return (count);
}

t_env	*ft_init_env(char *str, va_list ap)
{
	t_env	*new;
	int		x;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	new->str = str;
	if (!(new->subs = ft_init_subs(str)))
		return (NULL);
	new->form = NULL;
	if (new->subs[0] == NULL)
	{
		ft_putstr(str);
		return (new);
	}
	x = 0;
	if (!(new->form = ft_init_form(new, ap, x++)))
		return (NULL);;
	while (new->subs[x])
	{
		if (!(new->form->next = ft_init_form(new, ap, x)))
			return (NULL);
		new->form->next->prev = new->form;
		new->form = new->form->next;
		x++;
	}
	while (new->form->prev)
		new->form = new->form->prev;
	return (new);
}

t_form	*ft_init_form(t_env *env, va_list ap, int x)
{
	t_form	*new;

	if (!(new = (t_form *)malloc(sizeof(t_form))) ||
		!(new->indic = ft_find_indic(env->subs[x])) ||
		!(new->modif = ft_find_modif(env->subs[x])))
		return (NULL);
	new->width = ft_find_width(env->subs[x], ap);
	new->preci = ft_find_preci(env->subs[x], ap);
	new->type = ft_find_type(env->subs[x]);
	if (!(new->content = ft_init_content(new, ap)))
		return (NULL);
	new->size = (int)ft_strlen(new->content);
	new->result = NULL;
	new->next = NULL;
	new->prev = NULL;
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
