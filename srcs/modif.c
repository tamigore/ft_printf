/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <tamigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:55:01 by tamigore          #+#    #+#             */
/*   Updated: 2019/11/24 17:40:20 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_modif_width(t_env *env, char *str, int i, int j)
{
	if (TYPE == 'c')
		WIDTH -= (CONTENT[0] == '\0' ? 1 : 0);
	if (WIDTH > (int)ft_strlen(RES))
	{
		if (!(str = ft_strnew(WIDTH + 1)))
			return (NULL);
		if (ft_search(INDIC, '-') == 1)
		{
			while (RES[j])
				str[i++] = RES[j++];
			while (i <= (WIDTH - 1))
				str[i++] = ' ';
		}
		else
		{
			while (i < (WIDTH - (int)ft_strlen(RES)))
				str[i++] = ' ';
			while (RES[j])
				str[i++] = RES[j++];
		}
		free(RES);
		return (str);
	}
	return (RES);
}

char	*ft_modif_str_preci(t_env *env, char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (PRECI == -1)
	{
		free(RES);
		return (ft_strdup(""));
	}
	if (!(tmp = ft_strnew(PRECI)))
		return (NULL);
	if (PRECI > (int)ft_strlen(str))
	{
		while (str[j])
			tmp[i++] = str[j++];
	}
	else
		while (i < PRECI)
			tmp[i++] = str[j++];
	free(RES);
	SIZE = ft_strlen(tmp);
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
	while (i < (PRECI - (int)ft_strlen(str) + 4))
		tmp[i++] = '0';
	while (str[j])
		tmp[i++] = str[j++];
	free(RES);
	SIZE = ft_strlen(tmp);
	return (tmp);
}

char	*ft_modif_preci(t_env *env, int i, int j, int k)
{
	char	*tmp;

	if ((ft_search(INDIC, ' ') == 1 || ft_search(INDIC, '+') == 1) &&
			ft_superatoi(RES) >= 0)
		k--;
	if (ft_superatoi(RES) < 0)
		PRECI = PRECI + 1;
	if (!(tmp = ft_strnew(PRECI + (int)ft_strlen(RES) - k)))
		return (NULL);
	if (ft_search(INDIC, '+') == 1 && ft_superatoi(RES) >= 0)
		tmp[i++] = '+';
	if (ft_search(INDIC, ' ') == 1 && ft_superatoi(RES) >= 0)
		tmp[i++] = ' ';
	if (ft_superatoi(RES) < 0)
	{
		tmp[i++] = '-';
		k--;
		j++;
	}
	while (i < (PRECI - k))
		tmp[i++] = '0';
	if (!(tmp = ft_modif_preci_add(env, i, j, tmp)))
		return (NULL);
	free(RES);
	return (tmp);
}

int		ft_modif(t_env *env)
{
	while (env->form)
	{
		if (TYPE == 's' && (PRECI > 0 || PRECI == -1))
			if (!(RES = ft_modif_str_preci(env, RES)))
				return (0);
		if (ft_search("fcsp%", TYPE) == 0 &&
				PRECI > SIZE - ft_search(RES, '-'))
			if (!(RES = ft_modif_preci(env, 0, 0, ft_strlen(RES))))
				return (0);
		if (TYPE == 'p' && PRECI > (int)ft_strlen(RES) - 2)
			if (!(RES = ft_modif_p_preci(env, RES)))
				return (0);
		if (WIDTH != 0 && WIDTH > PRECI)
			if (!(RES = ft_modif_width(env, NULL, 0, 0)))
				return (0);
		if (WIDTH != 0 && TYPE == 's' && WIDTH <= PRECI)
			if (!(RES = ft_modif_width(env, NULL, 0, 0)))
				return (0);
		SIZE = ft_strlen(RES);
		if (!(NEXT))
			break ;
		env->form = NEXT;
	}
	return (1);
}
