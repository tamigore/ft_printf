/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:14:16 by tamigore          #+#    #+#             */
/*   Updated: 2018/12/05 14:56:12 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


static t_list	*ft_file(t_list **file, int fd)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

static char		*ft_strnjoin(char *s1, char *s2, int r)
{
	char	*join;
	int		diff;
	char	*tmp;

	tmp = s1;
	diff = ft_strlen(s2) - r;
	if (!s1 || !s2 || !(join = ft_strnew(ft_strlen(s1) + ft_strlen(s2) - diff)))
		return (NULL);
	ft_strcat(join, s1);
	ft_strncat(join, s2, r);
	free(tmp);
	return (join);
}

static int		ft_strcncat(char **content, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	if (!(*content = ft_strnew(i + 1)))
		return (0);
	ft_strncat(*content, str, i);
	return (i);
}

static char		*ft_free(char *content, int r)
{
	char	*tmp;

	tmp = content;
	content = ft_strdup(content + r);
	free(tmp);
	return (content);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list			*list;
	int				r;
	int				i;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL || read(fd, buf, 0) == -1)
		return (-1);
	list = ft_file(&file, fd);
	while ((r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] = '\0';
		if (!(list->content = ft_strnjoin(list->content, buf, r)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (r < BUFF_SIZE && !ft_strlen(list->content))
		return (0);
	i = ft_strcncat(line, list->content);
	if (i < (int)ft_strlen(list->content))
		list->content = ft_free(list->content, i + 1);
	else
		ft_strclr(list->content);
	return (1);
}
