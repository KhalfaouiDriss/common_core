#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
    int             value;
    int             index;
    int             list_size;
    struct s_list   *next;
}               t_list;

t_list *ft_lstnew(int content);
void ft_lstadd_front(t_list **head, t_list *new);
int ft_lstsize(t_list *head);
t_list *ft_lstlast(t_list *head);
void ft_lstadd_back(t_list **head, t_list *new);
t_list *ft_lstget(int val, t_list *head);
void ft_printlst(t_list *head);
void fill_stuck(t_list **stuck, char **ar);
void free_list(t_list **head);
int	is_digit(char *num);
void	ft_split_free(char **str);
int	ft_rpt_num(char **as);
int	ft_check_args(int ac, char **av);
void ft_error(char *msg);
void push_swap(t_list **stuck_a, t_list **stuck_b);
void index_stuck(t_list **stuck);
void ft_init_Stuck(t_list **a, char **av, int ac);
void sort_arr(int *arr,int size);
int is_sort(t_list **stuck);
void swap_to_b(t_list **stuck_a, t_list **stuck_b);
void pb(t_list **stuck_a, t_list **stuck_b, int index);
void del_node(int content, t_list **stuck);
t_list *ft_lstget_index(int val, t_list *head);

#include "libft/libft.h"
#endif
