#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = 0;
	if (count == 0 || 18446744073709551615ul / count >= size)
	{
		mem = malloc(count * size);
		if (mem)
			ft_memset(mem, 0, count * size);
	}
	return (mem);
}
