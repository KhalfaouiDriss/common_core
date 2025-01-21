#include "../push_swap.h"

int calc_med(t_list *stack)
{
    return (ft_lstsize(stack) / 2);
}

void swap_to_b(t_list **stack_a, t_list **stack_b)
{
    int med = calc_med(*stack_a);
    int i = 1;

    while (i <= med)
    {
        if(is_sorted(stack_a))
            return;
        if (ft_lstsize(*stack_a) <= 2)
            return;

        t_list *tmp = *stack_a;
        if (tmp->index <= med)
        {
            pb(stack_a, stack_b);
            i++;
        }
        else
        {
            ra(stack_a);
        }
    }
}

void push_min_to_b(t_list **stack_a, t_list **stack_b)
{
    while (!is_sorted(stack_a))
    {
        if (*stack_a == NULL || ft_lstsize(*stack_a) <= 2)
            break;

        swap_to_b(stack_a, stack_b);
        index_stuck(stack_a);
        index_stuck(stack_b);
    }

    if (ft_lstsize(*stack_a) == 2 && !is_sorted(stack_a))
        sa(stack_a);
}

void swap_to_a(t_list **stack_a, t_list **stack_b)
{
    int med = ft_lstsize(*stack_b) / 2; // Calculate the median of stack B
    int size;
    int i = 0;

    while (i <= med && *stack_b != NULL)
    {
        size = ft_lstsize(*stack_b);

        // Handle cases where stack B has one or two elements
        if (size == 1)
        {
            pa(stack_b, stack_a); // Push the only element to stack A
            return;
        }
        else if (ft_lstsize(*stack_b) == 2)
        {
            if ((*stack_b)->index < (*stack_b)->next->index)
                sb(stack_b); // Ensure stack B is sorted
            pa(stack_b, stack_a);
            pa(stack_b, stack_a);
            return;
        }

        // Push element from B to A if it's the largest remaining in B
        if ((*stack_b)->index == size)
        {
            pa(stack_b, stack_a);
            i++;
        }
        else if ((*stack_b)->value < (*stack_b)->next->value)
        {
            sb(stack_b); // Swap top two elements for correct order
        }
        else
        {
            rb(stack_b); // Rotate B to bring next candidate to the top
        }

        // Recalculate indexes to ensure consistency after each operation
        index_stuck(stack_b);

        // Debugging: Print stacks for verification (can be removed or wrapped in debug macros)
        // printf("\nStack A:\n");
        // ft_printlst(*stack_a);
        // printf("\nStack B:\n");
        // ft_printlst(*stack_b);
    }
}



void push_max_to_a(t_list **stack_a, t_list **stack_b)
{
    while (*stack_b)
    {
        if (*stack_b == NULL || ft_lstsize(*stack_b) <= 2)
            break;
        swap_to_a(stack_a, stack_b);
        // index_stuck(stack_a);
        index_stuck(stack_b);
    }
    if(ft_lstsize(*stack_b) == 2)
    {
        if ((*stack_b)->index < (*stack_b)->next->index)
                sb(stack_b); // Ensure stack B is sorted
        while(*stack_b)
            pa(stack_b, stack_a);
    }
}

void push_swap(t_list **stack_a, t_list **stack_b)
{
    push_min_to_b(stack_a, stack_b);
    push_max_to_a(stack_a, stack_b);

}

int main(int ac, char **av)
{
    t_list **a = (t_list **)malloc(sizeof(t_list *));
    t_list **b = (t_list **)malloc(sizeof(t_list *));

    if (!a || !b)
        ft_error("Memory allocation failed\n");

    *a = NULL;
    *b = NULL;

    if (ac < 2)
        ft_error("args is empty\n");

    ft_check_args(ac, av);

    if (ac == 2)
        av = ft_split(av[1], ' ');

    ft_init_Stuck(a, av, ac);
    index_stuck(a);

    printf("\nStack A (Sorted):\n");
    ft_printlst(*a);
    printf("\nStack B (Empty):\n");
    ft_printlst(*b);

    push_swap(a, b);
    index_stuck(a);

    printf("\nStack A (Sorted):\n");
    ft_printlst(*a);
    printf("\nStack B:\n");
    ft_printlst(*b);

    free_list(a);
    free_list(b);
    free(a);
    free(b);

    if (ac == 2)
        ft_split_free(av);

    return 0;
}
