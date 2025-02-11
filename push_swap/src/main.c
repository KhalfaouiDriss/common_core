#include "../push_swap.h"

int calc_chunk_size(t_list *stack)
{
    if (!stack)
        return 0;
    int size = ft_lstsize(stack);
    if (size <= 10)
        return 2;
    else if (size <= 200)
        return 4;
    return 8;
}

t_list *ft_get_max(t_list **a)
{
    if (!a || !*a)
        return NULL;
    t_list *tmp = *a;
    t_list *max = *a;
    while (tmp)
    {
        if (tmp->index > max->index)
            max = tmp;
        tmp = tmp->next;
    }
    return max;
}

void push_to_b(t_list **stack_a, t_list **stack_b)
{
    int parts = calc_chunk_size(*stack_a);
    int size = ft_lstsize(*stack_a);
    int size_part = size / parts;
    int limit = size_part;
    int middle = size / 2;

    while (ft_lstsize(*stack_a) > 3)
    {
        int i = 0;
        while (i < size_part && ft_lstsize(*stack_a) > 3)
        {
            if ((*stack_a)->index <= limit)
            {
                pb(stack_a, stack_b);
                if ((*stack_b)->place > middle)
                    rrb(stack_b);
                i++;
            }
            else
                ra(stack_a);
        }
        limit += size_part;
    }
}

void ft_sort_three(t_list **stack_a)
{
    t_list *max = ft_get_max(stack_a);
    if (max == *stack_a)
        ra(stack_a);
    else if (max == (*stack_a)->next)
        rra(stack_a);
    if ((*stack_a)->value > (*stack_a)->next->value)
        sa(stack_a);
}

void push_to_a(t_list **stack_a, t_list **stack_b)
{
    while (*stack_b)
    {
        int size = ft_lstsize(*stack_b);
        t_list *max_1 = ft_get_max(stack_b);
        t_list *max_2 = ft_lstget_index(max_1->index, *stack_b);
        t_list *max_near = (max_1->place < max_2->place) ? max_1 : max_2;
        while (*stack_b != max_near)
        {
            if (max_near->place < size / 2)
                rb(stack_b);
            else
                rrb(stack_b);
        }
        pa(stack_b, stack_a);
        if (!is_sorted(stack_a))
            sa(stack_a);
    }
}

void push_swap(t_list **stack_a, t_list **stack_b)
{
    if (is_sorted(stack_a))
        return;
    push_to_b(stack_a, stack_b);
    if (!is_sorted(stack_a))
        ft_sort_three(stack_a);
    push_to_a(stack_a, stack_b);
    // printf("\nStack A (Sorted):\n");
    // ft_printlst(*stack_a);
    // printf("\nStack B:\n");
    // ft_printlst(*stack_b);
}

int main(int ac, char **av)
{
    if (ac < 2)
        ft_error("args is empty\n");
    t_list **a = (t_list **)malloc(sizeof(t_list *));
    t_list **b = (t_list **)malloc(sizeof(t_list *));
    if (!a || !b)
        ft_error("Memory allocation failed\n");
    *a = NULL;
    *b = NULL;
    ft_check_args(ac, av);
    if (ac == 2)
        av = ft_split(av[1], ' ');
    ft_init_Stuck(a, av, ac);
    index_stuck(a);
    push_swap(a, b);
    index_stuck(a);
         
    free_list(a);
    free_list(b);
    free(a);
    free(b);
    if (ac == 2)
        ft_split_free(av);
    return 0;
}
