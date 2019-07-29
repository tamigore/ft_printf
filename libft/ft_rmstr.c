#include "libft.h"

char	*ft_rmstr(char *str, int i, int j)
{
	char	*tmp;
	int		x;

	x = 0;
	if (!(tmp = ft_strnew(ft_strlen(str) - i + j + 1)))
		return (NULL);
	while (str[x])
	{
		if (x == i)
			while (x <= j)
				x++;
		tmp[x - i + j] = str[x];
		x++;
	}
	return (tmp);
}
