#include "libft.h"

int main()
{
	char *s = "driss";
	char *d = ft_substr(s, 3, 10);
	ft_putstr_fd(d, 0);
}
