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

void index_stack(t_list *stuck)
{
    int size = ft_lstsize(stuck);
    int arr[size];
    int i;
    int j;
    t_list *tmp;
    if(!stuck)
        return;
    tmp = stuck;
    i = 0;
    j = 0;
    while(tmp)
    {
        arr[i] = tmp->value;
        tmp = tmp->next;
        i++;
    }
    i = 0;
    sort_arr(arr, size);  
    while(i < size)
    {
        tmp = ft_lstget(arr[i], stuck);
        tmp->index = i + 1;
        i++;
    }
}