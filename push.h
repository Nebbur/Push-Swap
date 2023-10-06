#ifndef PUSH_H
# define PUSH_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct		s_list
{
    long				content;
	long				position;
    struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_data
{
	long	content;
	long	position;
	long	index;
	long	error;
	long	count;
	long	pivot;
	long	pivot_aux;
	long	split;
	long	initial_size_a;
}				t_data;

/*_____________________Operations_____________________*/

/*_________SWAP_________*/

void    sa(t_list **stack_a, int booleana);
void    sb(t_list **stack_b, int booleana);
void	ss(t_list **stack_a, t_list **stack_b);
/*_________PUSH_________*/

void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_b, t_list **stack_a);
/*_________ROTATE_________*/

void	ra(t_list **stack_a, int booleana);
void	rb(t_list **stack_b, int booleana);
void	rr(t_list **stack_a, t_list **stack_b);
/*_________REVERSE ROTATE_________*/

void	rra (t_list **stack_a, int booleana);
void	rrb (t_list **stack_b, int booleana);
void	rrr (t_list **stack_a, t_list **stack_b);

void    ft_plusdecinq(t_list **stack_a, t_list **stack_b, t_data *st);

//LIST

void	ft_lstadd_back(t_list **lst, t_list *new, long number);
void	ft_lstadd_front(t_list *lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list **lst, t_list *to_del);
int	ft_lstsorted(t_list *lst);
int	ft_lstsize(t_list *lst);
int	ft_lstdistance(t_list **head, int position, bool is_position);
int	ft_lst_lastdistance(t_list **head, int position, bool is_position);
t_list	*ft_lstlast(t_list *lst, long number, bool booleana);
t_list	*ft_lstnew(long content);
t_list	*ft_lstcopy(t_list *lst);
t_list	*ft_smallest_number(t_list *lst);
t_list	*ft_bigger_number(t_list *lst);
t_list	*ft_second_bigger_number(t_list *lst);

//aux
void	ft_find_pivot(t_list *lst, t_data *st);
void	ft_exit(t_list *lst);
long	ft_atoi(const char *str, bool booleana, t_data *st);
long	ft_closest_to_the_first(t_list *lst, t_data *st);
long	ft_closest_to_pivot(t_list *lst, t_data *st);
long	ft_find_position_through_content(t_list *lst, long content);
long	ft_find_content_through_position(t_list *lst, long position);
bool	is_on_the_list(t_list *lst, long position);
bool	ft_is_on_the_list(t_list *lst, long content);
int	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
t_list	*split_args(t_list *lst, char *av, char c, t_data *st);
t_list	*ft_prev(t_list *lst, long position);

//sort
void	ft_sort_a(t_list **stack_a, t_list **stack_b, t_data *st);
void	ft_sort_b(t_list **stack_a, t_list **stack_b);
void	ft_sort_five(t_list **stack_a, t_list **stack_b);

#endif