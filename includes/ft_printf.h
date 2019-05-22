/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:24:43 by tamigore          #+#    #+#             */
/*   Updated: 2019/04/27 17:28:41 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_
# define _FT_PRINTF_

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define ABS(X) (x > 0) ? x : -x
# define UPORDOW(X) (x % 10 > 5) ? (x / 10 + 1) : (x / 10)

typedef struct		s_form
{
	int				size;
	char			indic;
	int				preci;
	int				width;
	char			*modif;
	char			*content;
	char			*result;
	struct s_form	*next;
	struct s_form	*prev;
}					t_form;

typedef struct		s_env
{
	char			*str;
	char			**subs;
	struct s_form	*form;
}					t_env;

int		ft_printf(char *format, ...);
t_env	*ft_init_env(char *str);
t_form	*ft_init_form(char *str, int i, int j);
char	**ft_init_subs(char *str);
char	**ft_fill_tab(char **tab, char *str);
int		ft_subs_len(char *str, int i);
int		ft_print_all(t_env *env);
void	ft_freeall(t_env *env);

t_env	*ft_pars_arg(t_env *env, va_list ap);
t_form	*ft_arg_char(t_env *env, va_list ap, int x, char c);
t_form	*ft_arg_int(t_env *env, va_list ap, int x, char c);
t_form	*ft_arg_float(t_env *env, va_list ap, int x);
t_form	*ft_arg_point(t_env *env, va_list ap, int x);
t_form	*ft_arg_str(t_env *env, va_list ap, int x);
t_form	*ft_init_fform(t_env *env, va_list ap);

char	*ft_float_to_char(double x);
int		ft_count(char *str);
char	*ft_strcat_float(char *integer, char *decimal);
char	*ft_itoa_conv(int x, char c);
char	ft_pars_char(char *str);
char	*ft_deci_conv(int nb, char *base);

char	ft_find_indic(char *subs);
int		ft_find_preci(char *subs, va_list ap);
int		ft_find_width(char *subs, va_list ap);
char	*ft_find_modif(char *subs);

#endif
