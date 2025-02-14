#include "../push_swap.h"

t_list	*fill_stack_values(int ac, char **av)
{
	t_list		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 0;
    if (ac > 2)
        i = 1;
	while (av[i]) // تكرار حتى نهاية المصفوفة
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_error("error");

		// إضافة العقدة الأولى فقط عند أول تكرار
		if (!stack_a)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}
