#include "push.h"

bool	ft_is_on_the_list(t_list *lst, long position)
{
	while (lst)
	{
		if (lst->position == position)
			return (true);
		lst = lst->next;
	}
	return (false);
}

void	ft_find_pivot(t_list *lst, t_data *st)
{
	if (ft_lstsize(lst) <= 12)
		st->split = 2;
	if (ft_lstsize(lst) > 12 && ft_lstsize(lst) < 200)
		st->split = 4;
	if (ft_lstsize(lst) > 200)
		st->split = 8;
	st->pivot = ft_lstsize(lst) / st->split;
	st->initial_size_a = ft_lstsize(lst);

	if (ft_lstsize(lst) % 2 == 0)
		st->pivot_aux = 0;
	else
		st->pivot_aux = 1;
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//RETURN 0 IF THE LIST IS SORTED
int	ft_lstsorted(t_list *lst)
{	
	t_list	*temporary;

	if (lst == NULL)
		return (0);
	temporary = lst;
	while (temporary->next != NULL)
	{
		if (temporary->content > temporary->next->content)
			break ;
		temporary = temporary->next;
	}
	if (temporary->next == NULL)
		return (0);
	return (1);
}
