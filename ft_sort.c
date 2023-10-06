#include "push.h"

// 100 / 4 = 25 || 25 + 25 ||| 50 + 25 ||| \/¬̣ ̣
void ft_until_pivot(t_list **stack_a, t_list **stack_b, t_data *st)
{
	while (ft_smallest_number(*stack_a)->position <= st->pivot)
	{
		if ((*stack_a)->position <= st->pivot)
			pb(stack_b, stack_a);
		else if ((*stack_a)->position > st->pivot && ft_find_position_through_content(*stack_a, ft_closest_to_the_first(*stack_a, st))  <= ft_lstsize(*stack_a) / 2)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
	st->pivot += st->initial_size_a / st->split;
}

void	ft_sort_aa(t_list **stack_a, t_list **stack_b, t_data *st)
{
	while (ft_lstsorted(*stack_a) != 0)
	{
		if (ft_smallest_number(*stack_a)->position == (*stack_a)->position)
			pb(stack_b, stack_a);
		else if (ft_lstdistance(stack_a, ft_smallest_number(*stack_a)->position, true) <= (ft_lstsize(*stack_a) / 2))
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}

	while (ft_lstsize(*stack_a) <= (st->initial_size_a / st->split))
	{
		if (ft_bigger_number(*stack_b)->position == (*stack_b)->position)
			pa(stack_a, stack_b);
		else if (ft_lstdistance(stack_b, ft_bigger_number(*stack_b)->position, true) < (ft_lstsize(*stack_b) / 2))
			rb(stack_b, 1);
		else
			rrb(stack_b, 1);
	}
}

void	ft_sort_b(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsorted(*stack_a) == 0 && (ft_lstsize(*stack_a) + ft_lstsize(*stack_b)) > 5)
	{
		while ((*stack_b)->position != ft_bigger_number(*stack_b)->position || (*stack_b)->position != ft_second_bigger_number(*stack_b)->position)
		{
			if (ft_lstdistance(stack_b, (ft_bigger_number(*stack_b)->position), true) <= ft_lstsize(*stack_b) / 2) // if distancia entre primeiro node e node do biggest number for inferior a lstsize / 2 entao {}
				rb(stack_b, 1);
			else
				rrb(stack_b, 1);
		}
	}
	if (ft_lstsize(*stack_b) == 1 && ft_lstsorted(*stack_a) == 0)
		pa(stack_a, stack_b);
	else
	{
		if (((*stack_b)->position == ft_bigger_number(*stack_b)->position) || 
		((*stack_b)->position == ft_second_bigger_number(*stack_b)->position))
			pa(stack_a, stack_b);
	}
	if ((*stack_a)->next->position < (*stack_a)->position)
		sa(stack_a, 1);
}

void    ft_plusdecinq(t_list **stack_a, t_list **stack_b, t_data *st)
{
	while (st->pivot <= (st->initial_size_a / st->split) * st->split - 1)
		ft_until_pivot(stack_a, stack_b, st);

	ft_sort_aa	(stack_a, stack_b, st);

	while (ft_lstsize(*stack_b) != 0)
		ft_sort_b(stack_a, stack_b);
}
