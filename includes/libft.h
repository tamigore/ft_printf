/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:31:48 by tamigore          #+#    #+#             */
/*   Updated: 2019/04/25 18:17:45 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define BUFF_SIZE 42

/*
**	FT_STR
*/

size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *src);
char			*ft_strndup(const char *src, int n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *h, const char *n, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_strrev(char *s);

/*
**	FT_PUT
*/

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(const char *s);
void			ft_putnbr(int n);
void			ft_puttab(char **tab);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
**	FT_IS
*/

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);

/*
**	FT_MEM
*/

void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memalloc(size_t size);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_memdel(void **ap);

/*
**	OTHERS
*/

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_itoa(int n);
void			ft_sorttab(char **tab);

/*
**	OPTION
*/

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void			ft_swap(char *s1, char *s2);
void			ft_sorttab(char **tab);
int				get_next_line(const int fd, char **line);
int				ft_strsearch(char *str, char c);

#endif
