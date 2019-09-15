#include "ft_printf.h"
#include <stdio.h>

typedef struct		s_float
{
	unsigned long long int	mantissa:52;
	unsigned int		exp:11;
	unsigned int		sign:1;
}					t_float;

typedef union		u_float_split
{
	double			value;
	t_float			split;
}					t_float_split;

void		print_bits(unsigned long long int value, int size)
{
	int		i;

	i = size - 1;
	while (i >= 0)
	{
		if (value & (0b1 << i))
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i--;
	}
}

void		print_split(t_float_split test)
{
	ft_printf("sign = ");
	print_bits(test.split.sign, 1);
	ft_printf("\nexponent = ");
	print_bits(test.split.exp, 11);
	ft_printf("\nexponent value : %lu\n", test.split.exp);
	ft_printf("exponent real value : %d\n", test.split.exp - 1023);
	ft_printf("mantissa = ");
	print_bits(test.split.mantissa, 52);
	ft_printf("\n");
}

int			main(void)
{
	t_float_split	test;

	test.split.sign = 1;
	test.split.exp = 0;
	test.split.mantissa = 0;
//	print_split(test);
	ft_printf("my printf: %lf\n", test.value);
	printf("real printf: %lf\n", test.value);

	test.split.sign = 0;
	test.split.exp = 0;
	test.split.mantissa = 0;
//	print_split(test);
	ft_printf("my printf: %lf\n", test.value);
	printf("real printf: %lf\n", test.value);

	test.split.sign = 0;
	test.split.exp = 0b11111111111;
	test.split.mantissa = 0;
//	print_split(test);
	ft_printf("my printf: %lf\n", test.value);
	printf("real printf: %lf\n", test.value);

	test.split.sign = 1;
	test.split.exp = 0b11111111111;
	test.split.mantissa = 0;
//	print_split(test);
	ft_printf("my printf: %lf\n", test.value);
	printf("real printf: %lf\n", test.value);

	test.split.sign = 0;
	test.split.exp = 0b11111111111;
	test.split.mantissa = 0b1;
//	print_split(test);
	ft_printf("my printf: %lf\n", test.value);
	printf("real printf: %lf\n", test.value);

	test.split.sign = 1;
	test.split.exp = 0b11111111111;
	test.split.mantissa = 0b1;
//	print_split(test);
	ft_printf("my printf: %lf\n", test.value);
	printf("real printf: %lf\n", test.value);

	test.split.sign = 0;
	test.split.exp = 0b11111111111;
	test.split.mantissa = 0b1000000000000000000000000000000000000000000000000001;
//	print_split(test);
	ft_printf("my printf: %lf\n", test.value);
	printf("real printf: %lf\n", test.value);

	test.split.sign = 1;
	test.split.exp = 0b11111111111;
	test.split.mantissa = 0b1000000000000000000000000000000000000000000000000001;
//	print_split(test);
	ft_printf("my printf: %lf\n", test.value);
	printf("real printf: %lf\n", test.value);

	test.split.sign = 0;
	test.split.exp = 0b11111111111;
	test.split.mantissa = 0b1111111111111111111111111111111111111111111111111111;
//	print_split(test);
	ft_printf("my printf: %lf\n", test.value);
	printf("real printf: %lf\n", test.value);

	test.split.sign = 1;
	test.split.exp = 0b11111111111;
	test.split.mantissa = 0b1111111111111111111111111111111111111111111111111111;
//	print_split(test);
	ft_printf("my printf: %lf\n", test.value);
	printf("real printf: %lf\n", test.value);




	test.split.sign = 0;
	test.split.exp = 0;
	test.split.mantissa = 0b0000000000000000000000000000000000000000000000000001;
//	print_split(test);
	ft_printf("my printf: %.1074lf\n", test.value);
	printf("real printf: %.1074lf\n", test.value);

	test.split.sign = 0;
	test.split.exp = 0b11111111110;
	test.split.mantissa = 0b1111111111111111111111111111111111111111111111111111;
//	print_split(test);
	ft_printf("my printf: %lf\n", test.value);
	printf("real printf: %lf\n", test.value);



	return (0);
}
