#include "push.h"

static void	ft_sort_three(t_list **stack_a, t_list **stack_b);
static void	ft_sort_four(t_list **stack_a, t_list **stack_b);

void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a)->position != ft_smallest_number(*stack_a)->position
		&& (*stack_a)->position != (ft_smallest_number(*stack_a)->position + 1))
	{
		if ((*stack_a)->next->next->next->next->position == ft_smallest_number(*stack_a)->position)
			rra(stack_a, 1);
		else if (ft_lstlast(*stack_a, 0, false)->position == ft_smallest_number(*stack_a)->position)
			rra(stack_a, 1);
		else
			ra(stack_a, 1);
	}
	pb(stack_b, stack_a);
	ft_sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
	if (ft_lstsorted(*stack_a) != 0)
		sa(stack_a, 1);
}

static void	ft_sort_four(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstlast(*stack_a, 1, false)->position == ft_smallest_number(*stack_a)->position)
		rra(stack_a, 1);
	else
		while ((*stack_a)->position != ft_smallest_number(*stack_a)->position)
			ra(stack_a, 1);

	pb(stack_b, stack_a);
	ft_sort_three(stack_a, stack_b);
	pa(stack_a, stack_b);
}

static void	ft_sort_three(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsorted(*stack_a) == 1)
	{
		if ((*stack_a)->position == ft_smallest_number(*stack_a)->position &&
			(*stack_a)->next->position == ft_bigger_number(*stack_a)->position)
			sa(stack_a, 1);  // 2 movs "1 3 2"
		if ((*stack_a)->position == ft_bigger_number(*stack_a)->position &&
			(*stack_a)->next->next->position == ft_smallest_number(*stack_a)->position)
			sa(stack_a, 1); // 3 2 1
		if ((*stack_a)->position == ft_bigger_number(*stack_a)->position &&
			(*stack_a)->next->position == ft_smallest_number(*stack_a)->position)
			ra(stack_a, 1); // 3 1 2
		if ((*stack_a)->next->position == ft_bigger_number(*stack_a)->position &&
			(*stack_a)->next->next->position == ft_smallest_number(*stack_a)->position)
			rra(stack_a, 1); // 2 3 1
		if ((*stack_a)->next->position == ft_smallest_number(*stack_a)->position &&
			(*stack_a)->next->next->position == ft_bigger_number(*stack_a)->position)
			sa(stack_a, 1); // 2 1 3  ---------------
	}
	if (ft_lstsorted(*stack_a) == 0 && ft_lstsize(*stack_b) == 1)
	{
		pa(stack_a, stack_b);
		if ((*stack_a)->position == ft_bigger_number(*stack_a)->position)
			ra(stack_a, 1); // 4 1 2 3
	}
}
