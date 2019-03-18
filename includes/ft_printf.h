/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:31:48 by tamigore          #+#    #+#             */
/*   Updated: 2018/11/19 16:54:40 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_form
{
	char            size;
	char			*type;
	char			*content;
	struct s_form	*next;
	struct s_form	*prev;
}                   t_form;

typedef struct      s_env
{
    char            *str;
    char            **subs;
    struct  s_form  form;
}                   t_env;

int     ft_printf(char * format, ...);
t_env   *ft_init_env(char *str);
t_form  ft_init_form(char *str);
char    **ft_init_subs(char *str);


#endif
