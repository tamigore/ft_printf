/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:32:11 by tamigore          #+#    #+#             */
/*   Updated: 2019/01/07 17:51:58 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void	ft_printf(const char * restrict format, ...);

int		main(void)
{
	ft_printf("lol, pour %d %s tu as combien de %c", 201, "kokonut", 'k');
	return (0);
}

void	ft_printf(const char * restrict format, ...)
{

	size_t	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i = ft_format(format, i, av);
		ft_putchar(fotmat[i++]);
	}
}

size_t	ft_format(const char * restrict format, size_t i,  va_list av)
{
}
