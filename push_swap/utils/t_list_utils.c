#include "../push_swap.h"

t_list *ft_lstnew(int content)
{
    t_list *new;

    new = (t_list *)malloc(sizeof(*new));
    if (!new)
        return NULL;
    
    new->value = content;
    new->index = 1;
    new->next = NULL;

    return new;
}

void ft_lstadd_front(t_list **head, t_list *new)
{
    new->next = *head;
    *head = new;
}

int ft_lstsize(t_list *head)
{
    int i = 0;
    t_list *tmp = head;
    while (tmp)
    {
        i++;
        tmp = tmp->next;
    }
    return i;
}

t_list *ft_lstlast(t_list *head)
{
    t_list *tmp = head;
    if (!tmp)
        return NULL;

    while (tmp->next)
        tmp = tmp->next;
    
    return tmp;
}

void ft_lstadd_back(t_list **head, t_list *new)
{
    t_list *tmp;
    if (*head)
    {
        tmp = ft_lstlast(*head);
        tmp->next = new;
        new->next = NULL;
    }
    else
    {
        *head = new;
        new->next = NULL;
    }
}

t_list *ft_lstget(int val, t_list *head)
{
    t_list *tmp = head;
    while (tmp)
    {
        if (tmp->value == val)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

t_list *ft_lstget_index(int val, t_list *head)
{
    t_list *tmp = head;
    while (tmp)
    {
        if (tmp->index == val)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}


void ft_printlst(t_list *head)
{
    t_list *tmp = head;
    // printf("size[%d]", tmp->list_size);
    ft_putstr_fd(" [", 1);
    while (tmp)
    {
        ft_putnbr_fd(tmp->value, 1);
        ft_putstr_fd(" -> ", 1);
        ft_putnbr_fd(tmp->index, 1);
        ft_putstr_fd(" -> ", 1);
        ft_putnbr_fd(tmp->place, 1);
        if (tmp->next)
            ft_putstr_fd("] \n [", 1);
        tmp = tmp->next;
    }
}

void del_node(int content, t_list **stuck)
{
    t_list *tmp = *stuck;
    t_list *prev = NULL;

    while (tmp)
    {
        if (tmp->index == content) 
        {
            if (prev == NULL) 
                *stuck = tmp->next;
            else 
                prev->next = tmp->next;
            free(tmp); 
            return; 
        }
        prev = tmp;
        tmp = tmp->next;
    }
}


void free_list(t_list **head)
{
    t_list *current = *head;
    t_list *next_node;

    while (current)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *head = NULL;
}