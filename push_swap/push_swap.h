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

#include "libft/libft.h"
#endif
