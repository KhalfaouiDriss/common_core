#include "push_swap.h"

void fill_stuck(t_list **stuck, char **ar)
{
    t_list *new;
    int i = 0;

    if (!stuck || !ar)
        return;

    while (ar[i])
    {
        new = ft_lstnew(ft_atoi(ar[i]));
        if (new == NULL)
        {
            return;  
        }
        ft_lstadd_back(stuck, new);
        i++;
    }
}