/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:55:01 by tamigore          #+#    #+#             */
/*   Updated: 2019/06/04 19:04:02 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_modif_width(t_env *env, char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (WIDTH > ft_strlen(str))
	{
		if (!(tmp = ft_strnew(WIDTH + 1)))
			return (NULL);
		if (ft_strsearch(INDIC, '-') == '1')
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
		free(str);
	}
	return (tmp);
}

char	*ft_modif_str_preci(t_env *env, char *str)
{
}

char	*ft_modif_preci(t_env *env, char *str)
{
	int		k;
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	k = ft_strlen(str) - POSI - SPACE;
	if (str[0] == '-')
		PRECI = PRECI + 2;
	if (!(tmp = ft_strnew(PRECI + POSI + SPACE)))
		return (NULL);
	if (POSI != 0)
		tmp[i++] = '+';
	if (ft_strsearch(INDIC, '0') == 0)
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
	free(str);
	return(tmp);
}

int		ft_modif(t_env *env)
{
	while (env->form)
	{
		if (PRECI > 0 && CONV != 'c' && CONV != 'f')
		{
			if (TYPE == 's')
				ft_modif_str_preci(form, RESULT);
			else if (PRECI > ft_strlen(RESULT))
				ft_modif_preci(form, RESULT);
		}
		if (WIDTH != 0 && WIDTH > PRECI)
			if (!(RESULT = ft_modif_width(env->form, RESULT)))
				return (0);
		if (WIDTH != 0 && TYPE == 's' && WIDTH < PRECI)
			if (!(RESULT = ft_modif_width(env->form, RESULT)))
				return (0);
		env->form = NEXT;
	}
	return (1);
}
