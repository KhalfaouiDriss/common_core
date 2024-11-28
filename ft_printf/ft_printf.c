
// #include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>


void	ft_putchar(char c)
{
	write( 1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putchar((nbr % 10) + 48);
	}
	else
		ft_putchar(nbr + '0');
}

int check_format(char c)
{
    if(c == '.')
    {
        ft_putstr
    }
}

int ft_printf(const char  *format, ...)
{
    va_list list;
    int i = 0;
    int size = 0;
    va_start(list, format);

    va_arg(list, int);

    while(format[i])
    {
        if(format[i] == '.')
        {
            size += check_format(format, list, i)
            i++;
        }
        else
        {
            ft_putchar(format[i]);
            i++;
        }
    }
    va_end(list);
}

int main(void)
{
    const char *s = "abc.d\n";
    ft_printf(s, "123");
    return 0;
}