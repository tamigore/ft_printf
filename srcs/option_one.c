#include "ft_printf.h"

void	oposi(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = (int)ft_strlen(RESULT) + 1;
	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	while (i < (width - (int)ft_strlen(RESULT)) - 1)
		tmp[i++] = ' ';
	tmp[i++] = '+';
	while (RESULT[j])
		tmp[i++] = RESULT[j++];
	RESULT = tmp;
}

void	ohash(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	i = 2;
	j = 0;
	if (width != 0)
		tmp = ft_strnew(width);
	else
		tmp = ft_strnew((int)ft_strlen(RESULT) + 2);
	tmp[0] = '0';
	tmp[1] = TYPE;
	if (TYPE == 'o')
		i--;
	if (ft_strsearch(INDIC, '0') == 1)
	{
		while (i < width - (int)ft_strlen(RESULT))
			tmp[i++] = '0';
	}
	while (RESULT[j])
		tmp[i++] = RESULT[j++];
	RESULT = tmp;
}

void	olzero(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;
	int		neg;

	if (width == 0)
		width = (int)ft_strlen(RESULT);
	i = 0;
	j = 0;
	neg = 0;
	tmp = ft_strnew(width);
	if (RESULT[j] == '-')
	{
		tmp[i++] = '-';
		j++;
		neg++;
	}
	while (i < (width - (int)ft_strlen(RESULT) + neg))
		tmp[i++] = '0';
	while (RESULT[j])
		tmp[i++] = RESULT[j++];
	RESULT = tmp;
}

void	ospace(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = (int)ft_strlen(RESULT) + 1;
	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	while (i < (width - (int)ft_strlen(RESULT)))
		tmp[i++] = ' ';
	while (RESULT[j])
		tmp[i++] = RESULT[j++];
	RESULT = tmp;
}

void	olalign(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0 || width < (int)ft_strlen(RESULT))
		width = (int)ft_strlen(RESULT);
	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	while (RESULT[j])
		tmp[i++] = RESULT[j++];
	while (i < width)
		tmp[i++] = ' ';
	RESULT = tmp;
}
