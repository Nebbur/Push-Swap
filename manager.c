#include "push.h"

long	ft_closest_to_pivot(t_list *lst, t_data *st)
{
	long	smallest_position;
	long	content_to_return;
	long	distance;

	smallest_position = st->pivot;
	distance = ft_lstdistance(&lst, smallest_position, true);
	if (ft_is_on_the_list(lst, st->pivot) == true)
		return (ft_find_content_through_position(lst, st->pivot));
	while (smallest_position > 0)
	{
		if (ft_is_on_the_list(lst, smallest_position) == true && ft_lstdistance(&lst, smallest_position, true) < distance)
		{
			distance = ft_lstdistance(&lst, smallest_position, true);
			content_to_return = ft_find_content_through_position(lst, smallest_position);
		}
		smallest_position--;
	}

	return (content_to_return);
}

long	ft_closest_to_the_first(t_list *lst, t_data *st)
{
	t_list	*tmp;
	long	closest_content;
	bool	trigger;

	trigger = false;
	tmp = lst;
	closest_content = ft_closest_to_pivot(lst, st);

	while (tmp)
	{
		if (tmp->position <= st->pivot)
		{
			if (ft_lstdistance(&lst, tmp->position, true) <= ft_lstsize(lst) / 2)
			{
				trigger = true;
				if (ft_lstdistance(&lst, tmp->position, true) < ft_lstdistance(&lst, closest_content, false))
					closest_content = tmp->content;
			}
			else
			{
				if ((trigger == true && ft_lst_lastdistance(&lst, tmp->position, true) < ft_lstdistance(&lst, closest_content, false))
					|| (trigger == false && ft_lst_lastdistance(&lst, tmp->position, true) < ft_lst_lastdistance(&lst, closest_content, false)))
				{
					closest_content = tmp->content;
					trigger = false;
				}
			}
		}
		tmp = tmp->next;
	}
	return (closest_content);
}

long	ft_find_content_through_position(t_list *lst, long position)
{
	t_list	*tmp;
	int	cont = 1;

	tmp = lst;
	while (tmp->position != position)
	{
		tmp = tmp->next;
		cont++;
		if (tmp->next == NULL)
			break;
	}
	return (tmp->content);
}

long	ft_find_position_through_content(t_list *lst, long content)
{
	t_list	*tmp;
	long	count;

	count = 1;
	tmp = lst;
	while (tmp->content != content)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
