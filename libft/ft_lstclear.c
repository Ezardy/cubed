#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cur;
	t_list	*next;

	if (lst && del)
	{
		cur = *lst;
		while (cur)
		{
			next = cur->next;
			ft_lstdelone(cur, del);
			cur = next;
		}
		*lst = 0;
	}
}
