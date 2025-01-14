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

void ft_printlst(t_list *head)
{
    t_list *tmp = head;
    while (tmp)
    {
        ft_putnbr_fd(tmp->value, 1);
        if (tmp->next)
            ft_putchar_fd(' ', 1);
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