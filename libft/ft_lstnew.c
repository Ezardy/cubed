#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	result = (t_list *)malloc(sizeof(t_list));
	if (result)
	{
		result->content = content;
		result->next = NULL;
	}
	return (result);
}
