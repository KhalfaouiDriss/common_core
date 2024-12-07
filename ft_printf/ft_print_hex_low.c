#include "ft_printf.h"

int ft_print_hex_low(unsigned long Num)
{
	int count;
	char base[16] = "0123456789abcdef";
	char res[16]; 
	int i = 0;

	count = 0;
	if(!Num)
		count += ft_putstr("0");
	else
	{
		while(Num)
		{
			res[i++] = base[Num % 16];
			Num /= 16;
		}
		res[i] = '\0';
		while (i >= 0)
		{
			count += ft_putchar(res[i--]);
		}
	}
	return count;
}

#include <stdio.h>

int	main(void)
{
	char	*s = "Driss";
	int		d;

	d = 123;
	ft_printf("Hi i am %s, i am %d years old %u ptr : %p hex_low : %x hex_upp %X  ||| %%\n", s, 22, 2, s, 1234, 1234);
	printf("----------------------------\n");
	printf("Hi i am %s, i am %d years old %u ptr : %p hex_low : %x hex_upp %X  ||| %%\n", s, 22, 2, s, 1234, 1234);
	return (0);
}