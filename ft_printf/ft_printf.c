#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}


int	check_format(char c, va_list list)
{
	unsigned long long arg;

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
		arg = va_arg(list, unsigned long long);
		if (arg == 0)
			return (write(1, "(nil)", 5));
		ft_putstr("0x");
		return (ft_puthexadecimal(arg, 'p') + 2);
	}
	if(c == 'x')
	{
		return(ft_puthexadecimal(va_arg(list, unsigned int), c));
	}
	if(c == 'X')
	{
		return(ft_puthexadecimal(va_arg(list, unsigned int), c));
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

// int main(void)
// {
//     int my_return;
//     int original_return;

//     // === Basic Tests ===
//     printf("Testing basic cases:\n");
//     my_return = ft_printf("ft_printf: Hello, World!\n");
//     original_return = printf("printf: Hello, World!\n");
//     printf("Return values: ft_printf = %d, printf = %d\n\n", my_return, original_return);

//     my_return = ft_printf("ft_printf: Empty line\n\n");
//     original_return = printf("printf: Empty line\n\n");
//     printf("Return values: ft_printf = %d, printf = %d\n\n", my_return, original_return);

//     // === Multiple Characters ===
//     printf("Testing multiple characters:\n");
//     my_return = ft_printf("ft_printf: %c %c %c\n", 'a', 'b', 'c');
//     original_return = printf("printf: %c %c %c\n", 'a', 'b', 'c');
//     printf("Return values: ft_printf = %d, printf = %d\n\n", my_return, original_return);

//     // === Multiple Strings ===
//     printf("Testing multiple strings:\n");
//     my_return = ft_printf("ft_printf: %s, %s!\n", "Hello", "World");
//     original_return = printf("printf: %s, %s!\n", "Hello", "World");
//     printf("Return values: ft_printf = %d, printf = %d\n\n", my_return, original_return);

//     // === Multiple Integers ===
//     printf("Testing multiple integers:\n");
//     my_return = ft_printf("ft_printf: %d, %i, %d\n", 0, -42, 12345);
//     original_return = printf("printf: %d, %i, %d\n", 0, -42, 12345);
//     printf("Return values: ft_printf = %d, printf = %d\n\n", my_return, original_return);

//     // === Negative Hexadecimal ===
//     printf("Testing negative hexadecimal:\n");
//     my_return = ft_printf("ft_printf: %x, %X\n", -42, -42);
//     original_return = printf("printf: %x, %X\n", -42, -42);
//     printf("Return values: ft_printf = %d, printf = %d\n\n", my_return, original_return);

//     // === Edge Case Pointers ===
//     printf("Testing pointer edge cases:\n");
//     void *ptr = NULL;
//     my_return = ft_printf("ft_printf: %p\n", ptr);
//     original_return = printf("printf: %p\n", ptr);
//     printf("Return values: ft_printf = %d, printf = %d\n\n", my_return, original_return);

//     ptr = (void *)0xFFFFFFFFFFFFFFFF;
//     my_return = ft_printf("ft_printf: %p\n", ptr);
//     original_return = printf("printf: %p\n", ptr);
//     printf("Return values: ft_printf = %d, printf = %d\n\n", my_return, original_return);

//     // === Zero Padding and Width Specifiers ===
//     printf("Testing width and zero padding:\n");
//     my_return = ft_printf("ft_printf: %d\n", 42);
//     original_return = printf("printf: %d\n", 42);
//     printf("Return values: ft_printf = %d, printf = %d\n\n", my_return, original_return);

//     my_return = ft_printf("ft_printf: %d\n", 42);
//     original_return = printf("printf: %d\n", 42);
//     printf("Return values: ft_printf = %d, printf = %d\n\n", my_return, original_return);

//     // === Special Case Strings ===
//     printf("Testing special case strings:\n");
//     my_return = ft_printf("ft_printf: '%s'\n", "");
//     original_return = printf("printf: '%s'\n", "");
//     printf("Return values: ft_printf = %d, printf = %d\n\n", my_return, original_return);

//     my_return = ft_printf("ft_printf: '%s'\n", "This is a very long string to test ft_printf!");
//     original_return = printf("printf: '%s'\n", "This is a very long string to test ft_printf!");
//     printf("Return values: ft_printf = %d, printf = %d\n\n", my_return, original_return);

//     // === Mixed Formats ===
//     printf("Testing mixed formats with tricky inputs:\n");
//     my_return = ft_printf("ft_printf: Char: %c, Int: %d, Hex: %x, String: %s, Percent: %%\n",
//                           '@', 12345, 48879, "Mixed Format Test");
//     original_return = printf("printf: Char: %c, Int: %d, Hex: %x, String: %s, Percent: %%\n",
//                              '@', 12345, 48879, "Mixed Format Test");
//     printf("Return values: ft_printf = %d, printf = %d\n\n", my_return, original_return);

//     // === Null String ===
//     printf("Testing null string (undefined behavior):\n");
//     my_return = ft_printf("ft_printf: %s\n", NULL);
//     original_return = printf("printf: %s\n", NULL);
//     printf("Return values: ft_printf = %d, printf = %d\n\n", my_return, original_return);

//     return 0;
// }



// #include <stdio.h>

// int	main(void)
// {
// 	char	*s = NULL;
// 	int		d;

// 	d = 123;
// 	// ft_printf("Hi i am %s, i am %d years old %u ptr : %p hex_low : %x hex_upp : %X  ||| %%\n", s, 22, 2, s, 1234, 1234);
// 	ft_printf("%p ||| %p\n", s, s+3);
// 	printf("----------------------------\n");
// 	printf("%p ||| %p\n", s, s+3);
// 	// printf("Hi i am %s, i am %d years old %u ptr : %p hex_low : %x hex_upp : %X  ||| %%\n", s, 22, 2, s, 1234, 1234);
// 	return (0);
// }
