#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

t_list				*head = NULL;

void	add_node(void *content, char *forma)
{
	t_list	*new_node;
	t_list	*last;

	new_node = malloc(sizeof(t_list));
	new_node->data = content;
	new_node->next = NULL;
	if (!head)
	{
		head = new_node;
	}
	else
	{
		last = head;
		while (last->next)
		{
			last = last->next;
		}
		last->next = new_node;
	}
}

void	print_list(char *forma)
{
	t_list	*current;
	int		i;

	i = 0;
	current = head;
	while (forma[i])
	{
		if (current)
		{
			if (forma[i] == 'd')
			{
				printf("%d -> ", current->data);
			}
			else if (forma[i] == 'c')
			{
				printf("%c -> ", current->data);
			}
			else if (forma[i] == 's')
			{
				printf("%s -> ", current->data);
			}
			else if (forma[i] == 'p')
			{
				printf("%p -> ", current->data);
			}
			else
			{
				printf("forma for argement %d is not correct", i);
				return ;
			}
			current = current->next;
		}
		i++;
	}
	printf("NULL\n");
}

void	free_list(void)
{
	t_list	*current;
	t_list	*next_list;

	current = head;
	while (current)
	{
		next_list = current->next;
		free(current);
		current = next_list;
	}
}

void	del_node(void *content)
{
	t_list	*target;
	t_list	*prev;

	target = head;
	prev = NULL;
	while (target != NULL)
	{
		if (target->data == content)
		{
			if (prev == NULL)
			{
				head = target->next;
			}
			else
			{
				prev->next = target->next;
			}
			free(target);
			return ;
		}
		prev = target;
		target = target->next;
	}
}

int	main(void)
{
	long	n = 5, m = 7, o;

	n = 5, m = 7, o = 99;
	add_node((int *)n, "d");
	add_node("driss", "s");
	add_node((int *)o, "d");
	add_node((int *)(456), "d");
	del_node((void *)o);
	print_list("dsdd");
	free_list();
	return (0);
}


//f(n) = (2n + 2) + n(2n + 2) + 2n^2 
// f(n) = 2n^2 + 2n + 2n^2 + (2n + 2) 
// f(n) = 4n^2 + 4n + 2
// f(n) = 
