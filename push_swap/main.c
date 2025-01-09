#include "push_swap.h"


typedef struct s_stuck_node
{
	int					value;
	char				*data;
	struct s_stuck_node	*next;
	struct s_stuck_node	*prev;

}						t_stuck_node;

void fill_stuck(t_stuck_node a, char **arr)
{
    t_stuck_node *new_a;
    int i = 0;
    a = new_a;
    while (arr[i])
    {
        new_a->data = arr[i];
        new_a->next = NULL;
        new_a->prev = ;

    }
    
}


int main(int ac, char **av)
{
    t_stuck_node *a = NULL;
    t_stuck_node *b = NULL;

    if(ac == 1 || (ac == 2 && !av[1][0]))
    {
        return(1);
    }
    else if(ac == 2)
    {
        av = ft_split(av[1], ' ');
    }
    a = malloc(sizeof(t_stuck_node));
    b = malloc(sizeof(t_stuck_node));

    fill_stuck(a, av)
    if(!a || !b)
    {
        return 0;
    }

    printf("%s\n", av[1]);

    free(a);
    free(b);
}