#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	const void			*r;

	r = 0;
	str = s;
	if (n)
	{
		while (n && !r)
		{
			if (*str == (unsigned char)c)
				r = str;
			str++;
			n--;
		}
	}
	return ((void *)r);
}
