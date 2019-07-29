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
	new->result = new->content;
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
		if (str[x] == '%' && ft_strsearch("diouxXcspf%", ft_find_type(&str[x + 1])) == 1)
		{
			count++;
			x += ft_count_type(&str[x + 1]);
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
	char	c;

	if (new->type == 'd' || new->type == 'i')
	{
		str = ft_conv_type_d(new, ap);
		if (new->preci == -1 && str[0] == '0')
			return (ft_strnew(0));
	}
	else if (ft_strsearch("ouxX", new->type) == 1)
	{
		str = ft_conv_type(new, ap);
		if (new->preci == -1 && str[0] == '0')
			return (ft_strnew(0));
	}
	else if (new->type == 'f')
		str = double_to_str((double)va_arg(ap, double), new->preci);
	else if (new->type == 'c' || new->type == '%')
	{
		if (new->type == 'c')
			c = (char)va_arg(ap, int);
		else
			c = '%';
		if (c == 0)
			return (ft_strdup("^@"));
		if (!(str = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		str[0] = c;
		str[1] = '\0';
	}
	else if (new->type == 's')
	{
		str = va_arg(ap, char *);
		if (str == NULL)
			str = "(null)";
	}
	else if (new->type == 'p')
		str = ft_itoa_base(va_arg(ap, unsigned int), 16);
	else
		str = NULL;
	return (str);
}

int		ft_erorrcheck(t_env *env)
{
	int		i;
	int		j;
	char	*tmp;

	while (env->form)
	{
		i = 0;
		j = 0;
		if (ft_strsearch(INDIC, '0') == 1 && ft_strsearch(INDIC, '-') == 1)
		{
			if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(INDIC) - 1))))
				return (-1);
			while (INDIC[i])
			{
				if (INDIC[i] == '0')
					i++;
				tmp[j++] = INDIC[i++];
			}
			tmp[j] = INDIC[i];
			INDIC = tmp;
		}
		if (ft_strsearch(INDIC, '#') == 1 && TYPE == 'o' && CONTENT[0] == '\0')
		{
			if (!(tmp = (char *)malloc(sizeof(char) * 2)))
				return (-1);
			tmp[0] = '0';
			tmp[1] = '\0';
			RESULT = tmp;
		}
		if (!env->form->next)
			break;
		env->form = NEXT;
	}
	while (env->form->prev)
		env->form = env->form->prev;
	return (0);
}
