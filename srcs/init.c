/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <tamigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:24:55 by tamigore          #+#    #+#             */
/*   Updated: 2020/01/16 16:17:20 by tamigore         ###   ########.fr       */
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
	new->f = NULL;
	if (!(new->subs = ft_init_subs(new->str)))
		return (NULL);
	if (new->subs[0] == NULL)
	{
		ft_putstr(new->str);
		return (new);
	}
	if (!(new->f = ft_init_form(new, ap, x++)))
		return (NULL);
	while (new->subs[x])
	{
		if (!(new->f->n = ft_init_form(new, ap, x)))
			return (NULL);
		new->f->n->b = new->f;
		new->f = new->f->n;
		x++;
	}
	return (new);
}

t_form	*ft_init_form(t_env *env, va_list ap, int x)
{
	t_form	*new;
	int		i;

	if (!(new = (t_form *)malloc(sizeof(t_form))) ||
		!(new->i = ft_find_indic(env->subs[x], 0, 0)) ||
		!(new->m = ft_find_modif(env->subs[x])))
		return (NULL);
	if ((i = ft_find_width(env->subs[x], ap, 0, 0)) < 0 &&
			!ft_search(new->i, '-'))
		if (!(new->i = ft_free_join(new->i, "-", 1)))
			return (NULL);
	new->w = (i < 0 ? -i : i);
	new->p = ft_find_preci(env->subs[x], ap, 0, 0);
	new->t = ft_find_type(env->subs[x]);
	if (!ft_search(env->subs[x], '.') && new->t == 'f')
		new->p = 6;
	if (!(new->c = ft_init_content(new, ap)))
		return (NULL);
	new->s = ft_strlen(new->c);
	if (!(new->r = ft_strdup(new->c)))
		return (NULL);
	new->n = NULL;
	new->b = NULL;
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
	if (ft_search("cps%", new->t) == 1)
	{
		if (!(str = ft_init_content_supp(new, ap)))
			return (NULL);
	}
	if (new->t == 'd' || new->t == 'i')
		if (!(str = ft_conv_type_d(new, ap)))
			return (NULL);
	if (ft_search("ouxX", new->t) == 1)
		if (!(str = ft_conv_type(new, ap)))
			return (NULL);
	if (new->t == 'f')
		if (!(str = ft_conv_double(ap, new)))
			return (NULL);
	if (new->p == -1 && str[0] == '0' && str[1] == '\0' && new->t != 'f')
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
	if (new->t == 'c' || new->t == '%')
		if (!(str = ft_conv_char(new, ap)))
			return (NULL);
	if (new->t == 's')
	{
		if (!(str = ft_strdup((char *)va_arg(ap, char *))))
		{
			if (!(str = ft_strdup("(null)")))
				return (NULL);
		}
	}
	if (new->t == 'p')
		if (!(str = ft_arg_point(ap, new->p)))
			return (NULL);
	return (str);
}
