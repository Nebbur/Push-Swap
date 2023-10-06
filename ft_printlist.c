#include "push.h"

//PRINT THE ELEMENTS OF LIST A
static void	ft_print_a(t_list *temporary_a, int size)
{
	if (temporary_a != NULL)
	{
		if (temporary_a->position < size)
			printf("\033[0;34m%9ld\033[0m", (long int)temporary_a->content);
		else if (temporary_a->position < size * 2)
			printf("\033[0;32m%9ld\033[0m", (long int)temporary_a->content);
		else if (temporary_a->position < size * 3)
			printf("\033[0;33m%9ld\033[0m", (long int)temporary_a->content);
		else
			printf("\033[0;31m%9ld\033[0m", (long int)temporary_a->content);
	}
	else
		printf(" %9c  ", ' ');
}

//PRINT THE ELEMENTS OF LIST B
static void	ft_print_b(t_list *temporary_b, int size)
{
	if (temporary_b != NULL)
	{
		if (temporary_b->position < size)
			printf("\033[0;34m%11ld\033[0m", (long int)temporary_b->content);
		else if (temporary_b->position < size * 2)
			printf("\033[0;32m%11ld\033[0m", (long int)temporary_b->content);
		else if (temporary_b->position < size * 3)
			printf("\033[0;33m%11ld\033[0m", (long int)temporary_b->content);
		else
			printf("\033[0;31m%11ld\033[0m", (long int)temporary_b->content);
	}
}

//PRINT THE ELEMENTS OF THE LISTS
void	ft_printlist(t_list *stack_a, t_list *stack_b)
{
	int		size;
	t_list	*temporary_a;
	t_list	*temporary_b;

	temporary_a = stack_a;
	temporary_b = stack_b;
	size = (ft_lstsize(stack_a) + ft_lstsize(stack_b)) / 4;
	printf("_____________________________________\n");
	printf("    Stack A	|        Stack B");
	while (temporary_a != NULL || temporary_b != NULL)
	{
		printf("\n");
		ft_print_a(temporary_a, size);
		printf(" 	|  ");
		ft_print_b(temporary_b, size);
		if (temporary_b != NULL)
			temporary_b = temporary_b->next;
		if (temporary_a != NULL)
			temporary_a = temporary_a->next;
	}
	printf("\n_____________________________________\n");
	if (!ft_lstsorted(stack_a))
		printf("\033[0;36m\nSORTED\n\033[0m");
	else
		printf("\033[0;35m\nNOT SORTED\n\033[0m");
}
//-------------------------------------------------------