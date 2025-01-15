#include "../push_swap.h"

void pb(t_list **stuck_a, t_list **stuck_b, int index)
{
    t_list *tmp;

    tmp = ft_lstget_index(index, *stuck_a);
    if (!tmp)
        return;

    ft_lstadd_front(stuck_b, tmp);
    del_node(index, stuck_a);
}
