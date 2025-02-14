#ifndef PUSH_SWAP
#define PUSH_SWAP

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}	t_list;




//-------------------- Public utils ---------------------

void ft_error(char *msg);
void ft_split_free(char **split);
int is_digit(char *num);
int	is_sorted(t_list *stack);

// -------------------- check args -----------------------

int	ft_check_args(int ac, char **av);
// ------------------- t_list_utils  -----------------------

t_list	*get_stack_bottom(t_list *stack);
t_list	*get_stack_before_bottom(t_list *stack);
t_list	*stack_new(int value);
void		stack_add_bottom(t_list **stack, t_list *new);
int			get_stack_size(t_list*stack);
t_list *ft_lstget(int val, t_list *head);
int ft_lstsize(t_list *head);
void ft_printlst(t_list *head);

// ------------------- init_Stuck  -----------------------

t_list	*fill_stack_values(int ac, char **av);

// ------------------- index stuck  ----------------------

void index_stack(t_list *stack);


// ------------------- Operations  -----------------------

void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		sa(t_list **stack_a);
void		sb(t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b);
void		ra(t_list **stack_a);
void		rb(t_list **stack_b);
void		rr(t_list **stack_a, t_list **stack_b);
void		rrr(t_list **stack_a, t_list **stack_b);
void		rra(t_list **stack_a);
void		rrb(t_list **stack_b);

// ------------------- sort  -----------------------

void	sort_three(t_list **stack);






#include "libft/libft.h"

#endif