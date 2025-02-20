/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:31:15 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/02/17 02:51:56 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char *frmt)
{
	int		count;
	void	*ptr;

	count = 0;
	if (*frmt == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (*frmt == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (*frmt == 'd' || *frmt == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (*frmt == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (*frmt == 'x')
		count += ft_puthexa(va_arg(args, unsigned int), 1);
	else if (*frmt == 'X')
		count += ft_puthexa(va_arg(args, unsigned int), 0);
	else if (*frmt == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr == NULL)
			return (count += ft_putstr("(nil)"), count);
		count += ft_putstr("0x");
		count += ft_puthexa((unsigned long)ptr, 1);
	}
	return (count);
}

int	ft_printf(const char *frmt, ...)
{
	va_list	args;
	int		count;

	va_start(args, frmt);
	count = 0;
	if (!frmt)
		return (-1);
	while (*frmt)
	{
		if (*frmt == '%' && *(frmt + 1))
		{
			frmt++;
			if (*frmt == '%')
				count += ft_putchar('%');
			else
				count += ft_format(args, frmt);
		}
		else
			count += ft_putchar(*frmt);
		frmt++;
	}
	va_end(args);
	return (count);
}
