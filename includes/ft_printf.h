/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:24:43 by tamigore          #+#    #+#             */
/*   Updated: 2019/08/04 13:49:06 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_
# define _FT_PRINTF_

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define ABS(X) 	(x > 0) ? x : -x
# define UPORDOW(X)	(x % 10 > 5) ? (x / 10 + 1) : (x / 10)
# define SIZE		(env->form->size)
# define INDIC		(env->form->indic)
# define WIDTH		(env->form->width)
# define PRECI		(env->form->preci)
# define MODIF		(env->form->modif)
# define TYPE		(env->form->type)
# define CONTENT	(env->form->content)
# define RES		(env->form->result)
# define NEXT		(env->form->next)
# define PREV		(env->form->prev)

typedef struct		s_form
{
	int				size;
	char			*indic;
	int				preci;
	int				width;
	char			*modif;
	char			type;
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

/*
** printf.c
*/

int		ft_printf(char *format, ...);
int		ft_print_all(t_env *env);
void	ft_freeall(t_env *env);
int		ft_err(char *str);

/*
** subs.c
*/

char	**ft_fill_tab(char **tab, char *str);
int		ft_subs_len(char *str, int i);

/*
** init.c
*/

t_env	*ft_init_env(char *str, va_list ap, int x);
t_form	*ft_init_form(t_env *env, va_list ap, int x);
char	**ft_init_subs(char *str);
char	*ft_init_content(t_form *new, va_list ap);
int		ft_erorrcheck(t_env *env);

/*
** parsing.c
*/

char	*ft_arg_char(t_env *env);
char	*ft_arg_int(t_env *env, int i, char c, int count);
char	*ft_arg_float(t_env *env);
char	*ft_arg_point(t_env *env);
char	*ft_arg_str(t_env *env);

/*
** usefull.c
*/

int		ft_count_type(char *str);
char	*ft_float_to_char(double x, double count, unsigned int y);
char	*ft_strcat_float(char *integer, char *decimal);
char	*ft_check_str(char *str);
char	*ft_pars_indic(char *str, char *subs);

/*
** find.c
*/

char	*ft_find_indic(char *subs);
int		ft_find_preci(char *subs, va_list ap, int i, int x);
int		ft_find_width(char *subs, va_list ap);
char	*ft_find_modif(char *subs);
char	ft_find_type(char *str);

/*
** modif.c
*/

char	*ft_modif_width(t_env *env, char *str, int i, int j);
char	*ft_modif_str_preci(t_env *env, char *str);
char	*ft_modif_preci(t_env *env, char *str, int i, int j);
int		ft_modif(t_env *env);

/*
** option.c
*/

void	option(t_env *env, int x);

/*
** option_one.c
*/

void	oposi(t_env *env, int width);
void	ohash(t_env *env, int width);
void	olzero(t_env *env, int width);
void	ospace(t_env *env, int width);
void	olalign(t_env *env, int width);

/*
** option_one.c
*/

void	oposineg(t_env *env, int width);
void	oposizero(t_env *env, int width);
void	onegspace(t_env *env, int width);
void	ozerospace(t_env *env, int width);

/*
** conv_nb.c
*/

int		ft_find_base(char c);
char	*ft_conv_type_d(t_form *new, va_list ap);
char	*ft_conv_type(t_form *new, va_list ap);
char	*ft_conv_char(t_form *new, va_list ap);

/*
** itoa.c
*/

double				ft_unit(double nb, int len);
unsigned long long	ft_doubleunit(unsigned long long nb, int unit);
char				*ft_superitoa(int n, int neg, int len, int i);
char				*ft_itoa_base(unsigned long long int nb, int base);
char				*ft_itoa_long(long long val, int base);

/*
** double.c
*/

char		*double_to_str(double f, int len);

#endif
