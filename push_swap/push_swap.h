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
    int             place;
    int             is_placing;
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
int is_sorted(t_list **stack);
void swap_to_b(t_list **stuck_a, t_list **stuck_b);
void del_node(int content, t_list **stuck);
t_list *ft_lstget_index(int val, t_list *head);
int	push(t_list **stack_to, t_list **stack_from);
int pa(t_list **stuck_a, t_list **stuck_b);
int pb(t_list **stuck_a, t_list **stuck_b);
int	rotate(t_list **stack);
int ra(t_list **stuck);
int rb(t_list **stuck);
int	swap(t_list **stack);
int	sa(t_list **stack_a);
int	sb(t_list **stack_b);

#include "libft/libft.h"
#endif
