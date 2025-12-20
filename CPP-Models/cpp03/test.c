#include <stdio.h>
// #include "libft.h"

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

void ft_lstadd_back(t_list **lst, t_list *new)
{
    if (!lst || !new)
        return;
    if (*lst == NULL)
    {
        *lst = new;
        return;
    }
    t_list *tmp;
    tmp = *lst;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}
void ft_print(t_list *lst)
{
    while (lst)
    {
        printf("%s", (char *)lst->content);
        lst = lst->next;
    }
}
int main()
{
    t_list a = {"sanae", NULL};
    t_list b = {" hbiba ", NULL};
    t_list c = {" manar", NULL};
    t_list *lst = &a;

    ft_lstadd_back(&lst, &b);
    ft_lstadd_back(&lst, &c);

    ft_print(lst);
}