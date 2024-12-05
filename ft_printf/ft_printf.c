#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}


int	check_format(char c, va_list list)
{
	if (c == 'c')
	{
		return (ft_putchar(va_arg(list, int)));
	}
	if (c == 's')
	{
		return (ft_putstr(va_arg(list, char *)));
	}
	if (c == 'd' || c == 'i')
	{
		return (ft_putnbr(va_arg(list, int)));
	}
	if (c == 'u')
	{
		return (ft_u_putnbr(va_arg(list, unsigned int)));
	}
	if (c == 'p')
	{
		return (ft_putptr(va_arg(list, void *)));
	}
	if(c == 'x')
	{
		return(ft_print_hex_low(va_arg(list, unsigned long)));
	}
	if(c == 'X')
	{
		return(ft_print_hex_upp(va_arg(list, unsigned long)));
	}
	if(c == '%')
	{
		return(ft_putchar('%'));
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		i;
	int		size;

	i = 0;
	size = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == '%')
				size += ft_putchar('%');
			else
				size += check_format(format[i], list);
		}
		else
		{
			size += ft_putchar(format[i]);
		}
		i++;
	}
	va_end(list);
	return (size);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	*s = "Driss";
// 	int		d;

// 	d = 123;
// 	ft_printf("Hi i am %s, i am %d years old %u ptr : %p hex_low : %x hex_upp %X  ||| %%\n", s, 22, 2, s, 1234, 1234);
// 	printf("----------------------------\n");
// 	printf("Hi i am %s, i am %d years old %u ptr : %p hex_low : %x hex_upp %X  ||| %%\n", s, 22, 2, s, 1234, 1234);
// 	return (0);
// }
