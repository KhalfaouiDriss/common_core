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