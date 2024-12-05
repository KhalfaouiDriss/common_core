#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int		ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putnbr(int nbr);
int	ft_putstr(char *str);
int ft_putptr(void *ptr);
int ft_print_hex_low(unsigned long Num);
int ft_print_hex_upp(unsigned long Num);
int ft_u_putnbr(unsigned int nbr);

#endif