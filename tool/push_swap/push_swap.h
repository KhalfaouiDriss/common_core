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
    int				target_place;
	int				cost_a;
	int				cost_b;
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
void	ft_split_free(char **str);
int	ft_rpt_num(char **as);
int	ft_check_args(int ac, char **av);
void push_swap(t_list **stuck_a, t_list **stuck_b);
void index_stuck(t_list **stuck);
void ft_init_Stuck(t_list **a, char **av, int ac);
void	assign_index(t_list *stack_a, int stack_size);
void sort_arr(int *arr,int size);
void swap_to_b(t_list **stuck_a, t_list **stuck_b);
void del_node(int content, t_list **stuck);
t_list *ft_lstget_index(int val, t_list *head);
int	push(t_list **stack_to, t_list **stack_from);
int pa(t_list **stuck_a, t_list **stuck_b);
int pb(t_list **stuck_a, t_list **stuck_b);
int	rotate(t_list **stack);
int ra(t_list **stuck);
int rb(t_list **stuck);
int rr(t_list **stack_a, t_list **stack_b);
int	swap(t_list **stack);
int	sa(t_list **stack_a);
int	sb(t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int	rrr(t_list **stack_a, t_list **stack_b);

// --------------- sort_stack ----------------------

void sort_stack(t_list **stack_a, t_list **stack_b);
void	push_to_b(t_list **stack_a, t_list **stack_b);
void ft_sort_three(t_list **stack_a);

// ---------------- positions ----------------------

static void	get_position(t_list **stack);
int	low_index_position(t_list **stack);
void target_position(t_list **stack_a, t_list **stack_b);
static int	get_target(t_list **a, int b_idx, int target_idx, int target_pos);

// ------------------- cost ------------------------

void	cost_stack(t_list **stack_a, t_list **stack_b);

// ------------------- Moves ----------------------

static void	rev_rotate_both(t_list **a, t_list **b, int *cost_a, int *cost_b);
static void	rotate_both(t_list **a, t_list **b, int *cost_a, int *cost_b);
static void	rotate_a(t_list **a, int *cost);
static void	rotate_b(t_list **b, int *cost);
void	move(t_list **a, t_list **b, int cost_a, int cost_b);
void	best_moves(t_list **stack_a, t_list **stack_b);

// ---------------- utils fct ----------------------

void ft_error(char *msg);
int is_sorted(t_list **stack);
int	is_digit(char *num);
t_list *ft_get_max(t_list **stack);
int	nb_abs(int nb);
int ft_count_args(char **args);


    #include "libft/libft.h"
#endif
