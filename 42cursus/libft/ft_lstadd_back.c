#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lst = ft_lstlast(*lst);
	lst->next = new;
}
