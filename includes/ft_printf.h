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

# define ABS(X) (x > 0) ? x : -x 

typedef struct		s_form
{
	int             size;
	char			*type;
	char			*content;
	struct s_form	*next;
	struct s_form	*prev;
}                   t_form;

typedef struct      s_env
{
    char            *str;
    char            **subs;
    struct  s_form  *form;
}                   t_env;

int     ft_printf(char * format, ...);
t_env   *ft_init_env(char *str);
t_form  *ft_init_form(char *str);
char    **ft_init_subs(char *str);
char    **ft_fill_tab(char  **tab, char *str);
int     ft_subs_len(char *str, int i);
int     ft_print_all(t_env *env);


char    ft_pars_char(char *str);
t_env   *ft_pars_arg(t_env *env, va_list ap);
char    *ft_arg_char(t_env *env, va_list ap, int x);
char    *ft_arg_int(t_env *env, va_list ap, int x);
char    *ft_arg_float(t_env *env, va_list ap, int x);
char    *ft_arg_point(t_env *env, va_list ap, int x);
char    *ft_arg_str(t_env *env, va_list ap, int x);
char    *ft_float_to_char(float x);
int     ft_count(char *str);

#endif
