#include "push.h"

t_list	*split_args(t_list *lst, char *av, char c, t_data *st)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = ft_split(av, c);
	while (tmp[++i])
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_atoi(tmp[i], true, st)), ft_atoi(av, false, st));	
		free(tmp[i]);
	}
	free(tmp[i]);
	return (lst);
}

static int	ft_count_words(char const *s, char c)
{
	int	nb_words;
	int	trigger;

	nb_words = 0;
	trigger = 0;
	while (*s)
	{
		if (*s != c && trigger == 0)
		{
			nb_words++;
			trigger = 1;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (nb_words);
}

static char	*split_word(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static char	**ft_helper(char const *s, char c, char **result)
{
	int	i;
	int	j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			result[j++] = split_word(s, start, i);
			start = -1;
		}
		i++;
	}
	result[j] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (0);
	result = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (0);
	return (ft_helper(s, c, result));
}