/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:25:02 by tamigore          #+#    #+#             */
/*   Updated: 2019/08/04 14:11:14 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
char		*ft_arg_char(t_env *env)
{
	char	*str;
	int		count;

	count = 2;
	if (WIDTH > 0)
		count = WIDTH + 1;
	if (!(str = (char *)malloc(sizeof(char) * count)))
		return (NULL);
	count = 0;
	if (ft_strsearch(INDIC, '-'))
	{
		str[count++] = CONTENT[0];
		while (count < WIDTH)
			str[count++] = ' ';
	}
	else
	{
		while (count < WIDTH - 1)
			str[count++] = ' ';
		str[count++] = CONTENT[0];
	}
	str[count] = '\0';
	return (str);
}

static char	*ft_count_arg_int(t_env *env)
{
	char	*str;
	int		count;

	count = 0;
	if (SIZE >= WIDTH && SIZE >= PRECI)
		count = SIZE;
	else if (WIDTH >= PRECI && WIDTH >= SIZE)
		count = WIDTH;
	else if (PRECI >= WIDTH && PRECI >= SIZE)
		count = PRECI;
	if (count == SIZE)
	{
		if (CONTENT[0] != '-' && (ft_strsearch(INDIC, '+') == 1 ||
					ft_strsearch(INDIC, ' ') == 1))
			count++;
		if (TYPE == 'o' && ft_strsearch(INDIC, '#') == 1)
			count++;
	}
	else
		if (CONTENT[0] == '-')
			count++;
	if (!(str = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	return(str);
}

char		*ft_arg_int(t_env *env, int i, char c, int count)
{
	char	*str;

	c = (ft_strsearch(INDIC, '0') == 1 ? '0' : ' ');
	if (!(str = ft_count_arg_int(env)))
		return (NULL);
	if (ft_strsearch(INDIC, '-'))
	{
		while (CONTENT[i])
			str[count++] = CONTENT[i++];
	}
	while (WIDTH > PRECI + count)
	{
		if (WIDTH > SIZE + count)
			str[count++] = c;
		else
			break ;
	}
	while (PRECI > SIZE + i)
		str[count + i++] = '0';
	if (!ft_strsearch(INDIC, '-'))
	{
		while (CONTENT[i])
			str[count++] = CONTENT[i++];
	}
	str[count] = '\0';
	return (str);
}

char		*ft_arg_str(t_env *env)
{
	char	*str;
	int		count;
	int		i;

	count = SIZE + 1;
	if (WIDTH > SIZE)
		count = WIDTH + 1;
	if (!(str = (char *)malloc(sizeof(char) * count)))
		return (NULL);
	count = 0;
	i = 0;
	if (ft_strsearch(INDIC, '-'))
	{
		while (CONTENT[i++])
			str[count++] = CONTENT[i++];
		while (count < WIDTH)
			str[count++] = ' ';
	}
	else
	{
		while (count < WIDTH - SIZE)
			str[count++] = ' ';
		while (CONTENT[i])
			str[count++] = CONTENT[i++];
	}
	str[count] = '\0';
	return (str);
}

char		*ft_arg_point(t_env *env)
{
	char	*str;
	int		count;
	int		i;

	count = SIZE + 1;
	if (WIDTH > SIZE)
		count = WIDTH + 1;
	if (!(str = (char *)malloc(sizeof(char) * count)))
		return (NULL);
	count = 0;
	i = 0;
	if (ft_strsearch(INDIC, '-'))
	{
		while (CONTENT[i++])
			str[count++] = CONTENT[i++];
		while (count < WIDTH)
			str[count++] = ' ';
	}
	else
	{
		while (count < WIDTH - SIZE)
			str[count++] = ' ';
		while (CONTENT[i])
			str[count++] = CONTENT[i++];
	}
	str[count] = '\0';
	return (str);
}

char		*ft_arg_float(t_env *env)
{
	char	*str;
	int		count;
	int		i;

	count = SIZE + 1;
	if (WIDTH > SIZE)
		count = WIDTH + 1;
	else
	{
		if (CONTENT[0] != '-' && ft_strsearch(INDIC, '+') == 1)
			count++;
	}
	if (!(str = (char *)malloc(sizeof(char) * count)))
		return (NULL);
	count = 0;
	i = 0;
	if (ft_strsearch(INDIC, '-'))
	{
		while (CONTENT[i++])
			str[count++] = CONTENT[i++];
		while (count < WIDTH)
			str[count++] = ' ';
	}
	else
	{
		while (count < WIDTH - SIZE)
			str[count++] = ' ';
		while (CONTENT[i])
			str[count++] = CONTENT[i++];
	}
	str[count] = '\0';
	return (str);
}
*/
