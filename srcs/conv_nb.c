#include "ft_printf.h"

int		ft_find_base(char c)
{
	if (c == 'o')
		return 8;
	else if (c == 'x' || c == 'X')
		return 16;
	else
		return 10;
}

char	*ft_conv_type_d(t_form *new, va_list ap)
{
	if (ft_strcmp(new->modif, "l") == 0)
		return (ft_itoa_long((long)va_arg(ap, long int), 10));
	else if (ft_strcmp(new->modif, "ll") == 0)
		return (ft_itoa_long((long long)va_arg(ap, long long int), 10));
	else if (ft_strcmp(new->modif, "h") == 0)
		return (ft_superitoa((short)va_arg(ap, int)));
	else if (ft_strcmp(new->modif, "hh") == 0)
		return (ft_superitoa((char)va_arg(ap, int)));
	else
		return (ft_superitoa((int)va_arg(ap, int)));
}

char	*ft_conv_type(t_form *new, va_list ap)
{
	char	*str;
	int		i;

	if (ft_strcmp(new->modif, "l") == 0)
		str = (ft_itoa_base((unsigned long int)va_arg(ap, unsigned long int), ft_find_base(new->type)));
	else if (ft_strcmp(new->modif, "ll") == 0)
		str = (ft_itoa_base((unsigned long long int)va_arg(ap, unsigned long long int), ft_find_base(new->type)));
	else if (ft_strcmp(new->modif, "h") == 0)
		str = (ft_itoa_base((unsigned short int)va_arg(ap, unsigned int), ft_find_base(new->type)));
	else if (ft_strcmp(new->modif, "hh") == 0)
		str = (ft_itoa_base((unsigned char)va_arg(ap, unsigned int), ft_find_base(new->type)));
	else
		str = (ft_itoa_base((unsigned int)va_arg(ap, unsigned int), ft_find_base(new->type)));
	if (str && new->type == 'X')
	{
		i = 0;
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'f')
				str[i] -= 32;
			i++;
		}
	}
	else if (str)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] >= 'A' && str[i] <= 'F')
				str[i] += 32;
			i++;
		}
	}
	return (str);
}
