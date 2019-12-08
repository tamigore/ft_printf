/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <tamigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:24:55 by tamigore          #+#    #+#             */
/*   Updated: 2019/12/08 17:16:34 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_env	*ft_init_env(char *str, va_list ap, int x)
{
	t_env	*new;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	if (!(new->str = ft_check_str(str, new)))
		return (NULL);
	new->form = NULL;
	if (!(new->subs = ft_init_subs(new->str)))
		return (NULL);
	if (new->subs[0] == NULL)
	{
		ft_putstr(new->str);
		return (new);
	}
	if (!(new->form = ft_init_form(new, ap, x++)))
		return (NULL);
	while (new->subs[x])
	{
		if (!(new->form->next = ft_init_form(new, ap, x)))
			return (NULL);
		new->form->next->prev = new->form;
		new->form = new->form->next;
		x++;
	}
	return (new);
}

t_form	*ft_init_form(t_env *env, va_list ap, int x)
{
	t_form	*new;
	int		i;

	if (!(new = (t_form *)malloc(sizeof(t_form))) ||
		!(new->indic = ft_find_indic(env->subs[x], 0, 0)) ||
		!(new->modif = ft_find_modif(env->subs[x])))
		return (NULL);
	if ((i = ft_find_width(env->subs[x], ap, 0, 0)) < 0 &&
			!ft_search(new->indic, '-'))
		if (!(new->indic = ft_free_join(new->indic, "-", 1)))
			return (NULL);
	new->width = (i < 0 ? -i : i);
	new->preci = ft_find_preci(env->subs[x], ap, 0, 0);
	new->type = ft_find_type(env->subs[x]);
	if (!ft_search(env->subs[x], '.') && new->type == 'f')
		new->preci = 6;
	if (!(new->content = ft_init_content(new, ap)))
		return (NULL);
	new->size = ft_strlen(new->content);
	if (!(new->result = ft_strdup(new->content)))
		return (NULL);
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
		{
			if (ft_search("diouxXcspf%", ft_find_type(&str[x + 1])) == 1)
			{
				count++;
				x += ft_count_type(&str[x + 1]);
			}
		}
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

	str = NULL;
	if (ft_search("cps%", new->type) == 1)
	{
		if (!(str = ft_init_content_supp(new, ap)))
			return (NULL);
	}
	if (new->type == 'd' || new->type == 'i')
		if (!(str = ft_conv_type_d(new, ap)))
			return (NULL);
	if (ft_search("ouxX", new->type) == 1)
		if (!(str = ft_conv_type(new, ap)))
			return (NULL);
	if (new->type == 'f')
		if (!(str = ft_conv_double(ap, new)))
			return (NULL);
	if (new->preci == -1 && str[0] == '0' && str[1] == '\0' && new->type != 'f')
	{
		if (str)
			free(str);
		if (!(str = ft_strdup("")))
			return (NULL);
	}
	return (str);
}

char	*ft_init_content_supp(t_form *new, va_list ap)
{
	char	*str;

	str = NULL;
	if (new->type == 'c' || new->type == '%')
		if (!(str = ft_conv_char(new, ap)))
			return (NULL);
	if (new->type == 's')
	{
		if (!(str = ft_strdup((char *)va_arg(ap, char *))))
		{
			if (!(str = ft_strdup("(null)")))
				return (NULL);
		}
	}
	if (new->type == 'p')
		if (!(str = ft_arg_point(ap, new->preci)))
			return (NULL);
	return (str);
}
