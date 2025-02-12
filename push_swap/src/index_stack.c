#include "../push_swap.h"

void sort_arr(int *arr,int size)
{
    int i = 0;
    int j = 0;
    int t = 0;
    while(i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if(arr[i] > arr[j])
            {
                
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
            j++;
        }
        i++;
    }
}

void index_stuck(t_list **stuck)
{
    int size = ft_lstsize(*stuck);
    int arr[size];
    int i;
    int j;
    t_list *tmp;
    if(!stuck)
        return;
    tmp = *stuck;
    i = 0;
    j = 0;
    while(tmp)
    {
        arr[i] = tmp->value;
        // if(tmp->is_placing == 0)
        // {
            tmp->place = i;
            tmp->is_placing = 1;
        // }
        tmp = tmp->next;
        i++;
    }
    i = 0;
    // printf("size[%d]\n", size);
    sort_arr(arr, size);  
    while(i < size)
    {
        tmp = ft_lstget(arr[i], *stuck);
        tmp->index = i + 1;
        tmp->list_size = size;
        // printf("arr[%d] = %d | index list[%d] : %d\n",i, arr[i], tmp->value, tmp->index);
        i++;
    }
}


void	assign_index(t_list *stack_a, int stack_size)
{
	t_list	*ptr;
	t_list	*highest;
	int		value;
    printf("I'm here !!!!!!! {%d}", stack_size);
	while (stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->index == 0 && ptr->value >= value)
			{
				value = ptr->value;
				highest = ptr;
			}
			ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size--;
	}
}