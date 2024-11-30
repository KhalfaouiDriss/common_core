
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
	{
		count += ft_putstr("-2147483648");
		return (count);
	}
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar((nbr % 10) + '0');
	return (count);
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
	if (format[i] == '%' && format[i + 1] == '%')
	{
		i++;
		size += check_format(format[i], list);
	}
	else if (format[i] == '%' && format[i + 1])
	{
		size += ft_putchar('%');
	}
	else
	{
		size += ft_putchar(format[i]);
	}
	va_end(list);
	return (size);
}

int	main(void)
{
	char	s;
	int		d;

	d = 123;
	s = 'A';
	ft_printf("%c frr %s \n %d\n", s, "driss", d);
	printf("\n----------------------------\n");
	printf("%c frr %s \n %d\n", s, "driss", d);
	return (0);
}
