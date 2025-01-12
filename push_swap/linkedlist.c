#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

t_list	*head = NULL;
t_list	*foot = NULL;

void	add_node(void *content)
{
	t_list	*new_node = malloc(sizeof(t_list));

	if (!new_node)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	new_node->data = content;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (!head) // إذا كانت القائمة فارغة
	{
		head = new_node;
		foot = new_node;
	}
	else
	{
		foot->next = new_node;
		new_node->prev = foot;
		foot = new_node;
	}
}

void	print_list(char *forma)
{
	t_list	*current = head;

	while (current)
	{
		if (*forma == 'd') // طباعة عدد صحيح
			printf("%d -> ", *(int *)(current->data));
		else if (*forma == 's') // طباعة سلسلة نصية
			printf("%s -> ", (char *)(current->data));
		else if (*forma == 'p') // طباعة عنوان المؤشر
			printf("%p -> ", current->data);
		else
		{
			printf("Unsupported format: %c\n", *forma);
			return;
		}
		current = current->next;
		forma++;
	}
	printf("NULL\n");
}

void	free_list(void)
{
	t_list	*current = head;
	t_list	*next_node;

	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	head = NULL;
	foot = NULL;
}

void	del_node(void *content)
{
	t_list	*target = head;

	while (target)
	{
		if (target->data == content) // العثور على العقدة المطلوبة
		{
			if (target->prev)
				target->prev->next = target->next;
			else
				head = target->next;

			if (target->next)
				target->next->prev = target->prev;
			else
				foot = target->prev;

			free(target);
			return;
		}
		target = target->next;
	}
}

int	main(void)
{
	int	*n1 = malloc(sizeof(int));
	int	*n2 = malloc(sizeof(int));
	int	*n3 = malloc(sizeof(int));
	int	*n4 = malloc(sizeof(int));

	if (!n1 || !n2 || !n3 || !n4)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}

	*n1 = 5;
	*n2 = 7;
	*n3 = 99;
	*n4 = 456;

	add_node(n1);
	add_node("driss");
	add_node(n3);
	add_node(n4);

	del_node(n3);
	print_list("dsdd");

	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free_list();

	return 0;
}
