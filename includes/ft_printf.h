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

# define ABS(X) 	(x > 0) ? x : -x
# define UPORDOW(X)	(x % 10 > 5) ? (x / 10 + 1) : (x / 10)
# define SIZE		(env->form->size)
# define INDIC		(env->form->indic)
# define WIDTH		(env->form->width)
# define PRECI		(env->form->preci)
# define MODIF		(env->form->modif)
# define TYPE		(env->form->type)
# define CONTENT	(env->form->content)
# define RESULT		(env->form->result)
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

int		ft_printf(char *format, ...);
t_env	*ft_init_env(char *str, va_list ap);
t_form	*ft_init_form(t_env *env, va_list ap, int x);
char	**ft_init_subs(char *str);
char	**ft_fill_tab(char **tab, char *str);
int		ft_subs_len(char *str, int i);
int		ft_print_all(t_env *env);
void	ft_freeall(t_env *env);

char	*ft_find_result(t_env *env);
char	*ft_arg_char(t_env *env);
char	*ft_arg_int(t_env *env);
char	*ft_arg_float(t_env *env);
char	*ft_arg_point(t_env *env);
char	*ft_arg_str(t_env *env);
char	*ft_init_content(t_form *new, va_list ap);

char	*ft_float_to_char(double x);
int		ft_count(char *str);
char	*ft_strcat_float(char *integer, char *decimal);
char	*ft_itoa_conv(int x, char c);
char	ft_find_type(char *str);
char	*ft_deci_conv(int nb, char *base);

char	*ft_find_indic(char *subs);
int		ft_find_preci(char *subs, va_list ap);
int		ft_find_width(char *subs, va_list ap);
char	*ft_find_modif(char *subs);
int		ft_err(char *str);

#endif
