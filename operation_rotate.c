/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboia-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:45:36 by rboia-pe          #+#    #+#             */
/*   Updated: 2023/10/07 20:45:38 by rboia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

/* ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.*/
void	ra(t_list **stack_a, int booleana)
{
	t_list	*last;
	t_list	*first;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last = *stack_a;
	first = *stack_a;
	while (last->next != NULL)
		last = last->next;
	*stack_a = first->next;
	first->next = NULL;
	last->next = first;
	if (booleana != 0)
		write (1, "ra\n", 3);
}

/*rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one. */
void	rb(t_list **stack_b, int booleana)
{
	t_list	*last;
	t_list	*first;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last = *stack_b;
	first = *stack_b;
	while (last->next != NULL)
		last = last->next;
	*stack_b = first->next;
	first->next = NULL;
	last->next = first;
	if (booleana != 0)
		write (1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	write(1, "rr\n", 3);
}
