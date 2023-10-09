/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboia-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:43:18 by rboia-pe          #+#    #+#             */
/*   Updated: 2023/10/07 20:43:19 by rboia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	ft_lst_lastdistance(t_list **head, int position, bool is_position)
{
	int		distance;
	t_list	*tmp;
	bool	checkpoint;

	distance = 0;
	tmp = *head;
	checkpoint = false;
	while (tmp)
	{
		if ((is_position == true && tmp->position == position) || 
			(is_position == false && tmp->content == position))
			checkpoint = true;
		if (checkpoint == true)
			distance++;
		tmp = tmp->next;
	}
	return (distance);
}

int	ft_lstdistance(t_list **head, int position, bool is_position)
{
	int		distance;
	t_list	*tmp;

	distance = 0;
	tmp = *head;
	while (tmp && ((is_position == true && tmp->position != position) || 
			(is_position == false && tmp->content != position)))
	{
		tmp = tmp->next;
		distance++;
	}
	return (distance);
}

t_list	*ft_smallest_number(t_list *lst)
{
	t_list	*smallest;

	smallest = lst;
	while (lst)
	{
		if (lst->content < smallest->content)
			smallest = lst;
		lst = lst->next;
	}
	return (smallest);
}

t_list	*ft_2_bigger_number(t_list *lst)
{
	t_list	*bigger;
	t_list	*second_bigger;

	bigger = lst;
	second_bigger = NULL;
	while (lst)
	{
		if (lst->content > bigger->content)
		{
			second_bigger = bigger;
			bigger = lst;
		}
		else if (second_bigger == NULL || lst->content > second_bigger->content)
		{
			second_bigger = lst;
		}
		lst = lst->next;
	}
	return (second_bigger);
}

t_list	*ft_bigger_number(t_list *lst)
{
	t_list	*bigger;

	bigger = lst;
	while (lst)
	{
		if (lst->content > bigger->content)
			bigger = lst;
		lst = lst->next;
	}
	return (bigger);
}
