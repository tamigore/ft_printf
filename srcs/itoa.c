#include "ft_printf.h"

double		ft_unit(double nb, int len);
{
	int		i;
	double	tmp;

	tmp = nb;
	i = 0;
	while (++i < len)
		nb *= tmp;
	return (nb);
}

unsigned long long		ft_doubleunit(unsigned long long nb, int unit)
{
	if (pow == 0)
		return (1);
	else	
		return (nb * ft_unit(nb, unit - 1);
}

char	*ft_itoabase(unsigned long long int nb, int base)
{
	int		i;
	char	*str;

	i = (nb > 9) ? 2 : 1;
	if (nb == 0)
		return (ft_strdup("0"));
	while (ft_doubleunit(base, i) - 1 < nb)
		i++;
	if (!(str = (char*)malloc(sizeof(char) * i)))
		return (NULL);
	str[i--] = '\0';
	while (i > 0)
	{
		str[i--] = (nb % base) + ((nb % base > 9) ? 'A' - 10 : '0');
		nb = nb / base;
	}
	return (str);
}

char	*ft_itoalong(long long val, int base)
{
	char		*str;
	int			len;
	int			sign;
	long long	n;

	len = 1;
	sign = (val < 0) ? 1 : 0;
	if (sign == 1)
		val = -val;
	n = val;
	if (val == 0)
		return (ft_strdup("0"));
	while (n /= base)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + sign + 1))))
		return (NULL);
	str[len + sign] = '\0';
	str[0] = '-';
	while (len-- > 0)
	{
		str[len + sign] = "0123456789abcdef"[val % base];
		val /= base;
	}
	return (str);
}

char	*ft_itoa_conv(int x, char c)
{
	char	*str;
	char	*oct = "01234567";
	char	*hex = "0123456789abcdef";
	char	*HEX = "0123456789ABCDEF";
}
