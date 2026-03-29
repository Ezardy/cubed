#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_str;
	const char	*src_str;

	if (dst || src)
	{
		src_str = src;
		dst_str = dst;
		while (n--)
			*dst_str++ = *src_str++;
	}
	return (dst);
}
