#include "push.h"

long	ft_atoi(const char *str, bool booleana, t_data *st)
{
	long	sign;
	long	result;

	result = -1;
	sign = 1;
	while (booleana == true && str[++result])
		if (!(str[result] >= 48 && str[result] <= 57) && !(*str == 45 || *str == 43))
				st->error = 2;
	result = 0;
	if (*str == 45)
		sign *= -1;
	if (*str == 45 || *str == 43)
		str++;
	while (*str)
	{
		if (*str >= 48 && *str <= 57)
			result = result * 10 + *str - 48;
		str++;
	}
	if ((result >= 2147483648 && sign == 1) || (result > 2147483648 && sign == -1))
		st->error = 2;
	return (result * sign);
}

void	ft_organize_numbers(t_list **stack_a)
{
	t_list	*stack_tmp;
	t_list	*head;
	t_data	st_tmp;

	st_tmp.index = 0;
	stack_tmp = ft_lstcopy(*stack_a);
	if (stack_tmp == NULL)
		ft_lstclear(stack_a);
	while (ft_lstsize(stack_tmp) > 0)
	{
		head = *stack_a;
		while (head)
		{
			if (head->content == ft_smallest_number(stack_tmp)->content)
				break ;
			head = head->next;
		}
		head->position = ++st_tmp.index;
		ft_lstdelone(&stack_tmp, ft_smallest_number(stack_tmp));
	}
	ft_bigger_number(*stack_a)->position = ++st_tmp.index;
	ft_lstclear(&stack_tmp);
}

int main (int ac, char **ag)
{
	t_list  *stack_a;
	t_list  *stack_b;
	t_data	st;
	int     i;
	int		j;

	stack_a = NULL;
	stack_b = NULL;
	st.error = 1;
	i = 0;
	if (ac < 2)
		return (1);
	while (ag[++i])
	{
		j = -1;
		st.count = 0;
		while (ag[i][++j])
		{
			if (ag[i][j] == 32 || (ag[i][j] >= 9 && ag[i][j] <= 13))
			{
				st.count = 1;
				stack_a = split_args(stack_a, ag[i], ag[i][j], &st);
				break;;
			}
		}
		if(st.count == 0)
			ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(ag[i], true, &st)), ft_atoi(ag[i], false, &st));
	}
	if (st.error == 2)
		ft_exit(stack_a);
	ft_organize_numbers(&stack_a);
	ft_find_pivot(stack_a, &st);
	if (ft_lstsize(*&stack_a) <= 5)
		ft_sort_five(&stack_a, &stack_b);
	else
		ft_plusdecinq(&stack_a, &stack_b, &st);
}
