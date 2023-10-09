/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboia-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:42:56 by rboia-pe          #+#    #+#             */
/*   Updated: 2023/10/07 20:43:00 by rboia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_list	*ft_lstlast(t_list *lst, long number, bool booleana)
{
	if (!lst)
		return (NULL);
	if (booleana == true && lst->content == number)
		ft_exit(lst);
	while (lst->next != 0)
	{
		if (booleana == true)
		{
			if (lst->content == number)
				ft_exit(lst);
		}
		lst = lst->next;
	}
	if (booleana == true && lst->content == number)
		ft_exit(lst);
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new, long number)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst, number, true);
	temp->next = new;
}

void	ft_lstadd_front(t_list *lst, t_list *new)
{
	new->next = lst;
	lst = new;
}

t_list	*ft_lstnew(long content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == 0)
		return (NULL);
	new->content = content;
	new->next = 0;
	return (new);
}

//DELETE A NODE FROM THE LIST
void	ft_lstdelone(t_list **lst, t_list *to_del)
{
	t_list	*temp;

	if (!*lst || !lst)
		return ;
	if (*lst == to_del)
	{
		*lst = to_del->next;
		free(to_del);
		return ;
	}
	temp = *lst;
	while (temp->next != to_del && temp->next != NULL)
		temp = temp->next;
	temp->next = to_del->next;
	free(to_del);
}
