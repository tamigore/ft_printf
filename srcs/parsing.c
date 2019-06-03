/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:25:02 by tamigore          #+#    #+#             */
/*   Updated: 2019/04/27 17:28:48 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_find_result(t_env *env)
{
	if (ft_strsearch("diouxX", TYPE) == 1)
		return (ft_arg_int(env));
	else if (TYPE == 'f')
		return (ft_arg_float(env));
	else if (TYPE == 'c' || TYPE == '%')
		return (ft_arg_char(env));
	else if (TYPE == 's')
		return (ft_arg_str(env));
	else if (TYPE == 'p')
		return (ft_arg_point(env));
	return (NULL);
}

char	*ft_init_content(t_form *new, va_list ap)
{
	char	*str;

	if (ft_strsearch("diouxX", new->type) == 1)
	{
		if (ft_strcmp(new->modif, "l"))
			str = ft_itoa_conv(va_arg(ap, long int), new->type);
		else if (ft_strcmp(new->modif, "ll"))
			str = ft_itoa_conv(va_arg(ap, long long int), new->type);
		else if (ft_strcmp(new->modif, "h"))
			str = ft_itoa_conv(va_arg(ap, /*short*/ int), new->type);
		else if (ft_strcmp(new->modif, "hh"))
			str = ft_itoa_conv(va_arg(ap, /*char*/int), new->type);
		else
			str = ft_itoa_conv((int)va_arg(ap, int), new->type);
	}
	else if (new->type == 'f')
		str = ft_float_to_char(va_arg(ap, double));
	else if (new->type == 'c' || new->type == '%')
	{
		if (!(str = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		if (new->type == 'c')
			str[0] = (char)va_arg(ap, int);
		else
			str[0] = '%';
		str[1] = '\0';
	}
	else if (new->type == 's')
		str = va_arg(ap, char *);
	else if (new->type == 'p')
		str = ft_itoa_conv(va_arg(ap, int), 'x');
	else
		str = NULL;
	return (str);
}

char	*ft_arg_char(t_env *env)
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

char	*ft_arg_int(t_env *env)
{
	char	*str;
	int		count;
	int		i;
	char	c;

	count = 0;
	c = ' ';
	if (ft_strsearch(INDIC, '0') == 1 && ft_strsearch(INDIC, '-') == 0 &&
				PRECI == 0 )
		c = '0';
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
	i = 0;
	count = 0;
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

char	*ft_arg_str(t_env *env)
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

char	*ft_arg_point(t_env *env)
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

char	*ft_arg_float(t_env *env)
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
