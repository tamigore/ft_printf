/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <tamigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:55:01 by tamigore          #+#    #+#             */
/*   Updated: 2020/01/16 16:23:30 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_modif_width(t_env *env, char *str, int i, int j)
{
	if ((env->f->t) == 'c')
		(env->f->w) -= ((env->f->c)[0] == '\0' ? 1 : 0);
	if ((env->f->w) > (int)ft_strlen((env->f->r)))
	{
		if (!(str = ft_strnew((env->f->w) + 1)))
			return (NULL);
		if (ft_search((env->f->i), '-') == 1)
		{
			while ((env->f->r)[j])
				str[i++] = (env->f->r)[j++];
			while (i <= ((env->f->w) - 1))
				str[i++] = ' ';
		}
		else
		{
			while (i < ((env->f->w) - (int)ft_strlen((env->f->r))))
				str[i++] = ' ';
			while ((env->f->r)[j])
				str[i++] = (env->f->r)[j++];
		}
		free((env->f->r));
		return (str);
	}
	return ((env->f->r));
}

char	*ft_modif_str_preci(t_env *env, char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((env->f->p) == -1)
	{
		free((env->f->r));
		return (ft_strdup(""));
	}
	if (!(tmp = ft_strnew((env->f->p))))
		return (NULL);
	if ((env->f->p) > (int)ft_strlen(str))
	{
		while (str[j])
			tmp[i++] = str[j++];
	}
	else
		while (i < (env->f->p))
			tmp[i++] = str[j++];
	free((env->f->r));
	(env->f->s) = ft_strlen(tmp);
	return (tmp);
}

char	*ft_modif_p_preci(t_env *env, char *str)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = NULL;
	i = 2;
	j = 2;
	if (!(tmp = ft_strnew((env->f->p) + 3)))
		return (NULL);
	tmp[0] = '0';
	tmp[1] = 'x';
	while (i < ((env->f->p) - (int)ft_strlen(str) + 4))
		tmp[i++] = '0';
	while (str[j])
		tmp[i++] = str[j++];
	free((env->f->r));
	(env->f->s) = ft_strlen(tmp);
	return (tmp);
}

char	*ft_modif_preci(t_env *env, int i, int j, int k)
{
	char	*tmp;

	if ((ft_search(env->f->i, ' ') || ft_search(env->f->i, '+')) &&
			ft_superatoi(env->f->r) >= 0)
		k--;
	if (ft_superatoi(env->f->r) < 0)
		(env->f->p) = (env->f->p) + 1;
	if (!(tmp = ft_strnew((env->f->p) + (int)ft_strlen(env->f->r) - k)))
		return (NULL);
	if (ft_search(env->f->i, '+') == 1 && ft_superatoi(env->f->r) >= 0)
		tmp[i++] = '+';
	if (ft_search(env->f->i, ' ') == 1 && ft_superatoi(env->f->r) >= 0)
		tmp[i++] = ' ';
	if (ft_superatoi(env->f->r) < 0)
	{
		tmp[i++] = '-';
		k--;
		j++;
	}
	while (i < ((env->f->p) - k))
		tmp[i++] = '0';
	if (!(tmp = ft_modif_preci_add(env, i, j, tmp)))
		return (NULL);
	free((env->f->r));
	return (tmp);
}

int		ft_modif(t_env *env)
{
	while (env->f)
	{
		if ((env->f->t) == 's' && ((env->f->p) > 0 || (env->f->p) == -1))
			if (!((env->f->r) = ft_modif_str_preci(env, env->f->r)))
				return (0);
		if (ft_search("fcsp%", (env->f->t)) == 0 &&
				(env->f->p) > (env->f->s) - ft_search(env->f->r, '-'))
			if (!(env->f->r = ft_modif_preci(env, 0, 0, ft_strlen(env->f->r))))
				return (0);
		if ((env->f->t) == 'p' && (env->f->p) > (int)ft_strlen((env->f->r)) - 2)
			if (!((env->f->r) = ft_modif_p_preci(env, (env->f->r))))
				return (0);
		if ((env->f->w) != 0 && (env->f->w) > (env->f->p))
			if (!((env->f->r) = ft_modif_width(env, NULL, 0, 0)))
				return (0);
		if ((env->f->w != 0) && (env->f->t == 's') && (env->f->w <= env->f->p))
			if (!(env->f->r = ft_modif_width(env, NULL, 0, 0)))
				return (0);
		(env->f->s) = ft_strlen(env->f->r);
		if (!(env->f->n))
			break ;
		env->f = env->f->n;
	}
	return (1);
}
