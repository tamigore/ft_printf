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

	tmp = NULL;
	i = 0;
	j = 0;
	if (WIDTH > (int)ft_strlen(str))
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
			while (i < (WIDTH - (int)ft_strlen(str)))
				tmp[i++] = ' ';
			while (str[j])
				tmp[i++] = str[j++];
		}
	}
	return (tmp);
}

char	*ft_modif_str_preci(t_env *env, char *str)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = NULL;
	i = 0;
	j = 0;
	if (!(tmp = ft_strnew(PRECI)))
		return (NULL);
	if (PRECI > (int)ft_strlen(str))
	{
		while (str[j])
			tmp[i++] = str[j++];
	}
	else
	{
		while (i < PRECI)
			tmp[i++] = str[j++];
	}
	return (tmp);
}

char	*ft_modif_preci(t_env *env, char *str)
{
	int		k;
	int		i;
	int		j;
	char	*tmp;

	tmp = NULL;
	i = 0;
	j = 0;
	k = (int)(ft_strlen(str) - ft_strsearch(INDIC, '+') - ft_strsearch(INDIC, ' '));
	if (str[0] == '-')
		PRECI = PRECI + 2;
	if (!(tmp = ft_strnew(PRECI + (int)(ft_strsearch(INDIC, '+') + ft_strsearch(INDIC, ' ')))))
		return (NULL);
	if (ft_strsearch(INDIC, '+'))
		tmp[i++] = '+';
	if (!ft_strsearch(INDIC, '0'))
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
	return(tmp);
}

int		ft_modif(t_env *env)
{
	while (env->form)
	{
		if (PRECI > 0 && TYPE != 'c' && TYPE != 'f')
		{
			if (TYPE == 's')
			{
				if (!(ft_modif_str_preci(env, RESULT)))
					return (0);
			}
			else if (PRECI > (int)ft_strlen(RESULT))
				if (!(ft_modif_preci(env, RESULT)))
					return (0);
		}
		if (WIDTH != 0 && WIDTH > PRECI)
			if (!(RESULT = ft_modif_width(env, RESULT)))
				return (0);
		if (WIDTH != 0 && TYPE == 's' && WIDTH < PRECI)
			if (!(RESULT = ft_modif_width(env, RESULT)))
				return (0);
		SIZE = (int)ft_strlen(RESULT);
		if (env->form->next == NULL)
			break ;
		env->form = NEXT;
	}
	while (env->form->prev)
		env->form = env->form->prev;
	return (1);
}
