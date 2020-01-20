/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <tamigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:24:43 by tamigore          #+#    #+#             */
/*   Updated: 2020/01/20 17:56:50 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct		s_form
{
	int				s;
	char			*i;
	int				p;
	int				w;
	char			*m;
	char			t;
	char			*c;
	char			*r;
	struct s_form	*n;
	struct s_form	*b;
}					t_form;

typedef struct		s_env
{
	char			*str;
	char			**subs;
	struct s_form	*f;
}					t_env;

/*
** printf.c
*/

int					ft_printf(char *format, ...)
 __attribute__((format(printf,1,2)));
void				ft_apply(t_env *env);
int					ft_print_all(t_env *env, int x, int count);
int					ft_subs_len(char *str, int i);
char				**ft_fill_tab(char **tab, char *str);

/*
** free.c
*/

void				ft_freeall(t_env *env, int x);
void				ft_free_exit(t_env *env, int x);
int					ft_err(char *str);
char				*ft_free_join(char *s1, char *s2, int x);
int					ft_erorrcheck(t_env *env, int i, int j);

/*
** init.c
*/

t_env				*ft_init_env(char *str, va_list ap, int x);
t_form				*ft_init_form(t_env *env, va_list ap, int x);
char				**ft_init_subs(char *str);
char				*ft_init_content(t_form *new, va_list ap);
char				*ft_init_content_supp(t_form *new, va_list ap);

/*
** usefull.c
*/

int					ft_count_type(char *str);
char				*ft_pars_indic(char *str, char *subs);
char				*ft_check_str(char *str, t_env *env);
char				*ft_arg_point(va_list ap, int x);
char				*strjoin_double_add(char *inte, char *deci, int i);

/*
** find.c
*/

char				*ft_find_indic(char *subs, int x, int i);
int					ft_find_preci(char *subs, va_list ap, int i, int x);
int					ft_find_width(char *subs, va_list ap, int i, int x);
char				*ft_find_modif(char *subs);
char				ft_find_type(char *str);

/*
** modif.c
*/

char				*ft_modif_width(t_env *env, char *str, int i, int j);
char				*ft_modif_str_preci(t_env *env, char *str);
char				*ft_modif_p_preci(t_env *env, char *str);
char				*ft_modif_preci(t_env *env, int i, int j, int k);
int					ft_modif(t_env *env);

/*
** option.c
*/

int					option(t_env *env, int x);

/*
** option_one.c
*/

int					oposi(t_env *env, int width);
int					ohash(t_env *env, int width, int i);
int					olzero(t_env *env, int width);
int					ospace(t_env *env, int width);
int					olalign(t_env *env, int width);

/*
** option_duo.c
*/

int					oposineg(t_env *env, int width);
int					oposizero(t_env *env, int width);
int					onegspace(t_env *env, int width);
int					ozerospace(t_env *env, int width);

/*
** conv_nb.c
*/

int					ft_find_base(char c);
char				*ft_conv_type_d(t_form *new, va_list ap);
char				*ft_conv_type(t_form *new, va_list ap);
char				*ft_conv_char(t_form *new, va_list ap);

/*
** itoa.c
*/

double				ft_unit(double nb, int len);
unsigned long long	ft_doubleunit(unsigned long long nb, int unit);
char				*ft_superitoa(int n, int neg, int len, int i);
char				*ft_itoa_base(unsigned long long nb, int base);
char				*ft_itoa_long(long long val, int base, int len);

/*
** double.c
*/

char				*double_to_str(long double f, int len);
char				*ft_conv_double(va_list ap, t_form *new);
char				*ft_doubleitoa(long long x, int neg, int len, long long i);

/*
** inte_deci.c
*/

int					double_len(long double f);
char				*double_inte(long double f, long double frac, int len);
char				*double_deci(long double f, long double frac, int len);

/*
** norm_add.c
*/

int					ft_find_preci_add(char *subs, int i, int x);
int					ft_print_all_add(t_env *env, int count);
char				*ft_modif_preci_add(t_env *env, int i, int j, char *tmp);
int					option_all_add(t_env *env, int err);
void				ohash_add(t_env *env, int width, int i, char *tmp);

#endif
