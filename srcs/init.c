/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:24:55 by tamigore          #+#    #+#             */
/*   Updated: 2019/06/04 19:04:06 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	*ft_init_content(t_form *new, va_list ap)
{
	char	*str;

	if (ft_strsearch("diouxX", new->type) == 1)
	{
		if (ft_strcmp(new->modif, "l"))
			str = ft_itoa_conv(va_arg(ap, long int), new->type);
		else if (ft_strcmp(new->modif, "ll"))
			str = ft_itoa_conv(va_arg(ap, long long int), new->type);
		else if (ft_strcmp(new->modif, "h"))
			str = ft_itoa_conv(va_arg(ap, /*short*/ int), new->type);
		else if (ft_strcmp(new->modif, "hh"))
			str = ft_itoa_conv(va_arg(ap, /*char*/int), new->type);
		else
			str = ft_itoa_conv((int)va_arg(ap, int), new->type);
	}
	else if (new->type == 'f')
		str = ft_float_to_char(va_arg(ap, double));
	else if (new->type == 'c' || new->type == '%')
	{
		if (!(str = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		if (new->type == 'c')
			str[0] = (char)va_arg(ap, int);
		else
			str[0] = '%';
		str[1] = '\0';
	}
	else if (new->type == 's')
		str = va_arg(ap, char *);
	else if (new->type == 'p')
		str = ft_itoa_conv(va_arg(ap, int), 'x');
	else
		str = NULL;
	return (str);
}

char	*ft_init_result(t_env *env)
{
	if (ft_strsearch("diouxX", TYPE) == 1)
		return (ft_arg_int(env));
	else if (TYPE == 'f')
		return (ft_arg_float(env));
	else if (TYPE == 'c' || TYPE == '%')
		return (ft_arg_char(env));
	else if (TYPE == 's')
		return (ft_arg_str(env));
	else if (TYPE == 'p')
		return (ft_arg_point(env));
	return (NULL);
}
