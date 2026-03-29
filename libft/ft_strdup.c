#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*ret;
	char	*p;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	p = ret;
	if (p)
	{
		while (*src)
			*p++ = *src++;
		*p = 0;
	}
	return (ret);
}
