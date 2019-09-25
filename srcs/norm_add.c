/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:57:14 by tamigore          #+#    #+#             */
/*   Updated: 2019/09/25 18:56:17 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find_preci_add(char *subs, int i, int x)
{
	if (subs[i + 1] == '0')
		i++;
	if (x < 0)
		x = 0;
	while (subs[i + 1] >= '0' && subs[i + 1] <= '9')
	{
		x *= 10;
		x += subs[i++ + 1] - '0';
	}
	return (x);
}

int		ft_print_all_add(t_env *env, int count)
{
	if (ft_search(INDIC, '-') == 0)
		ft_putstr(RES);
	write(1, "\0", 1);
	count++;
	if (ft_search(INDIC, '-') == 1)
		ft_putstr(RES);
	return (count);
}

char	*ft_modif_preci_add(t_env *env, int i, int j, char *tmp)
{
	while (RES[j])
		tmp[i++] = RES[j++];
	if (ft_search(INDIC, '#') == 1 && CONTENT[0] != '0')
	{
		if (TYPE == 'x')
		{
			if (!(tmp = ft_free_join("0x", tmp, 2)))
				return (NULL);
		}
		else if (TYPE == 'X')
			if (!(tmp = ft_free_join("0X", tmp, 2)))
				return (NULL);
	}
	return (tmp);
}

int		option_all_add(t_env *env, int err)
{
	while (RES[err] && (!(RES[err] >= '0' && RES[err] <= '9')))
		err++;
	while (RES[err] && RES[err] >= '0' && RES[err] <= '9')
		err++;
	if (RES[err] == '\0')
	{
		if (!(RES = ft_free_join(RES, ".", 1)))
			return (0);
	}
	else
		RES[err] = '.';
	return (1);
}

void	ohash_add(t_env *env, int width, int i, char *tmp)
{
	int		j;

	j = 0;
	tmp[0] = '0';
	if (TYPE == 'o')
		i--;
	else
		tmp[1] = TYPE;
	if (ft_search(INDIC, '0') == 1)
		while (i < width - ft_strlen(RES))
			tmp[i++] = '0';
	while (RES[j])
		tmp[i++] = RES[j++];
}
