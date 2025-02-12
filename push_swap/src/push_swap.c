#include "../push_swap.h"

void push_swap(t_list **stack_a, t_list **stack_b)
{
    int size = ft_lstsize(*stack_a);
    if (is_sorted(stack_a))
        return;
    if (size == 2)
        sa(stack_a);
    else if (size == 3)
        ft_sort_three(stack_a);
    else    
        sort_stack(stack_a, stack_b);
}

int main(int ac, char **av)
{
    printf("I'm here !!!!!!!");
    int stack_size;
    if (ac < 2)
        ft_error("args is empty\n");

    t_list *a = NULL;
    t_list *b = NULL;

    ft_check_args(ac, av);
    
    if (ac == 2)
    {
        av = ft_split(av[1], ' ');
        if (!av)
            ft_error("Memory allocation failed for arguments\n");
    }

    ft_init_Stuck(&a, av, ac);

    stack_size = ft_lstsize(a);
    assign_index(a, stack_size);

    push_swap(&a, &b);

    free_list(&a);
    free_list(&b);
    
    if (ac == 2)
        ft_split_free(av);
        
    return 0;
}
