#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long addr;
	int count;
	char base[16] = "0123456789abcdef";
	char res[16]; 
	int i = 0;
	int j = 0;
	char tmp;

	count = 0;
	addr = (unsigned long)ptr;
	if(!addr)
		count += ft_putstr("0x0");
	else
	{
		count += ft_putstr("0x");
		while(addr)
		{
			res[i++] = base[addr % 16];
			addr /= 16;
		}
		res[i] = '\0';
		while (i >= 0)
		{
			count += ft_putchar(res[i--]);
		}
	}
	return count;
}