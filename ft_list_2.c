#include "push.h"

t_list	*ft_prev(t_list *lst, long position)
{
	t_list	*temp;

	if (lst == NULL)
		return (NULL);
	temp = lst;
	while (temp->next != NULL && temp->position != position)
	{
		temp->prev = temp;
		temp = temp->next;
	}
	return(temp);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return ;

	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);		
		*lst = temp;
	}
	*lst = NULL;
}

t_list	*ft_lstcopy(t_list *lst)
{
	t_list	*new;
	t_list	*lst_tmp;

	if (!lst)
		return (NULL);
	new = NULL;
	lst_tmp = lst;
	
	while (lst_tmp)
	{
		ft_lstadd_back(&new, ft_lstnew(lst_tmp->content), lst_tmp->content);
		lst_tmp = lst_tmp->next;
	}
	return (new);
}

//RETURN THE SIZE OF THE LIST
int	ft_lstsize(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_exit(t_list *lst)
{
	ft_lstclear(&lst);
	exit(write(1, "Error\n", 6));
}