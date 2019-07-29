#include "ft_printf.h"

double		ft_unit(double nb, int len)
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
	if (unit == 0)
		return (1);
	else	
		return (nb * ft_unit(nb, unit - 1));
}

char		*ft_superitoa(int x)
{
	int		i;
	int		len;
	int		neg;
	char	*str;

	if (x == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ABS(x);
	len = 2;
	neg = 0;
	if (x < 0)
	{
		neg = 1;
		x *= -1;
	}
	while (i /= 10)
		len++;
	len += neg;
	if (!(str = (char *)malloc(sizeof(char) * (len))))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = x % 10 + '0';
		x = x / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

char		*ft_itoa_base(unsigned long long int nb, int base)
{
	int		i;
	char	*res;

	i = (nb > 9) ? 2 : 1;
	if (nb == 0)
		return (ft_strdup("0"));
	while (ft_doubleunit(base, i) - 1 < nb)
		i++;
	if (!(res = (char*)malloc(sizeof(res) * i)))
		return (NULL);
	res[i] = '\0';
	while (i > 0)
	{
		res[--i] = (nb % base) + (nb % base > 9 ? 'A' - 10 : '0');
		nb = nb / base;
	}
	return (res);
}

char	*ft_itoa_long(long long val, int base)
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
