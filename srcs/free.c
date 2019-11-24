/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <tamigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:02:55 by tamigore          #+#    #+#             */
/*   Updated: 2019/11/22 17:44:53 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_freeall(t_env *env, int x)
{
	t_form	*tmp;

	if (env)
	{
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

void	ft_free_exit(t_env *env, int x)
{
	t_form	*tmp;

	if (env->form)
	{
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

int		ft_err(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_search("diouxXcpsf%", ft_find_type(&str[i + 1])) == 0)
				return (ft_find_type(&str[i + 1]));
			i += ft_count_type(&str[i + 1]) + 1;
		}
		i++;
	}
	return (1);
}

char	*ft_free_join(char *s1, char *s2, int x)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(s1, s2)))
		return (NULL);
	if (x == 1)
		free(s1);
	else if (x == 2)
		free(s2);
	else if (x == 3)
	{
		free(s1);
		free(s2);
	}
	return (tmp);
}

int		ft_erorrcheck(t_env *env, int j, int i)
{
	while (env->form)
	{
		i = 0;
		j = 0;
		if ((ft_search(INDIC, '0') == 1 && ft_search("diouxX", TYPE) == 1
			&& PRECI > 0) || (ft_search(INDIC, '0') == 1 && WIDTH == 0))
			if (!(INDIC = ft_free_rmchar(INDIC, '0')))
				return (0);
		if (ft_search("diucsp%", TYPE) == 1 && ft_search(INDIC, '#') == 1)
			if (!(INDIC = ft_free_rmchar(INDIC, '#')))
				return (0);
		if (!NEXT)
			break ;
		env->form = NEXT;
	}
	return (1);
}
