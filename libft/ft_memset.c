#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = b;
	while (len)
	{
		*str++ = (unsigned char)c;
		len--;
	}
	return (b);
}
