/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:55:01 by tamigore          #+#    #+#             */
/*   Updated: 2019/08/08 17:34:19 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_modif_width(t_env *env, char *str, int i, int j)
{
	char	*tmp;

	tmp = NULL;
	if (TYPE == 'c')
		WIDTH -= (CONTENT[0] == '\0' ? 1 : 0);
	if (WIDTH > ft_strlen(str))
	{
		if (!(tmp = ft_strnew(WIDTH + 1)))
			return (NULL);
		if (ft_strsearch(INDIC, '-') == 1)
		{
			while (str[j])
				tmp[i++] = str[j++];
			while (i <= (WIDTH - 1))
				tmp[i++] = ' ';
		}
		else
		{
			while (i < (WIDTH - ft_strlen(str)))
				tmp[i++] = ' ';
			while (str[j])
				tmp[i++] = str[j++];
		}
		free(RES);
		return (tmp);
	}
	return (str);
}

char	*ft_modif_str_preci(t_env *env, char *str)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = NULL;
	i = 0;
	j = 0;
	if (PRECI == -1)
	{
		free(RES);
		return (ft_strdup(""));
	}
	if (!(tmp = ft_strnew(PRECI)))
		return (NULL);
	if (PRECI > ft_strlen(str))
	{
		while (str[j])
			tmp[i++] = str[j++];
	}
	else
	{
		while (i < PRECI)
			tmp[i++] = str[j++];
	}
	free(RES);
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
	if (!(tmp = ft_strnew(PRECI + 3)))
		return (NULL);
	tmp[0] = '0';
	tmp[1] = 'x';
	while (i < (PRECI - ft_strlen(str) + 4))
		tmp[i++] = '0';
	while (str[j])
		tmp[i++] = str[j++];
	free(RES);
	return (tmp);
}

char	*ft_modif_preci(t_env *env, char *str, int i, int j)
{
	int		k;
	char	*tmp;

	tmp = NULL;
	k = (int)(ft_strlen(str) - ft_strsearch(INDIC, '+') -
			ft_strsearch(INDIC, ' '));
	if (str[0] == '-')
		PRECI = PRECI + 2;
	if (!(tmp = ft_strnew(PRECI + ft_strsearch(INDIC, '+') +
					ft_strsearch(INDIC, ' '))))
		return (NULL);
	if (ft_strsearch(INDIC, '+') == 1)
		tmp[i++] = '+';
	if (ft_strsearch(INDIC, ' ') == 1)
		tmp[i++] = ' ';
	if (str[0] == '-')
	{
		tmp[i++] = '-';
		j++;
	}
	while (i < (PRECI - k))
		tmp[i++] = '0';
	while (str[j])
		tmp[i++] = str[j++];
	free(RES);
	return (tmp);
}

int		ft_modif(t_env *env)
{
	while (env->form)
	{
		if ((PRECI > 0 || PRECI == -1) && ft_strsearch("cfp", TYPE) == 0)
		{
			if (TYPE == 's')
				if (!(RES = ft_modif_str_preci(env, RES)))
					return (0);
			if (TYPE != 's' && PRECI > ft_strlen(RES) - ft_strsearch(RES, '-'))
				if (!(RES = ft_modif_preci(env, RES, 0, 0)))
					return (0);
		}
		if (TYPE == 'p' && PRECI > ft_strlen(RES) - 2)
			if (!(RES = ft_modif_p_preci(env, RES)))
				return (0);
		SIZE = ft_strlen(RES);
		if (WIDTH != 0 && WIDTH > PRECI)
			if (!(RES = ft_modif_width(env, RES, 0, 0)))
				return (0);
		if (WIDTH != 0 && TYPE == 's' && WIDTH < PRECI)
			if (!(RES = ft_modif_width(env, RES, 0, 0)))
				return (0);
		SIZE = ft_strlen(RES);
		if (!(NEXT))
			break ;
		env->form = NEXT;
	}
	return (1);
}
