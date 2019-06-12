#include "ft_printf.h"

void	oposineg(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = (int)ft_strlen(RESULT) + 1;
	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	tmp[i++] = '+';
	while (RESULT[j])
		tmp[i++] = RESULT[j++];
	while (i < width)
		tmp[i++] = ' ';
	RESULT = tmp;
}

void	oposizero(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = (int)ft_strlen(RESULT) + 1;
	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	if (RESULT[0] != '-')
		tmp[i++] = '+';
	else
	{
		tmp[i++] = '-';
		j++;
		width++;
	}
	while (i < width - (int)ft_strlen(RESULT))
		tmp[i++] = '0';
	while (RESULT[j])
		tmp[i++] = RESULT[j++];
	RESULT = tmp;
}

void	onegspace(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = (int)ft_strlen(RESULT) + 1;
	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	tmp[i++] = ' ';
	while (RESULT[j])
		tmp[i++] = RESULT[j++];
	while (i < width)
		tmp[i++] = ' ';
	RESULT = tmp;
}

void	ozerospace(t_env *env, int width)
{
	int		i;
	int		j;
	char	*tmp;

	if (width == 0)
		width = (int)ft_strlen(RESULT) + 1;
	i = 0;
	j = 0;
	tmp = ft_strnew(width);
	tmp[i++] = ' ';
	while (i < (width - (int)ft_strlen(RESULT)))
		tmp[i++] = '0';
	while (RESULT[j])
		tmp[i++] = RESULT[j++];
	RESULT = tmp;
}
