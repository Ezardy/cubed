#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_str;
	const char	*src_str;
	int			sign;
	size_t		offset;
	size_t		i;

	if (len && (dst || src))
	{
		dst_str = dst;
		src_str = src;
		i = 0;
		sign = 1;
		offset = 0;
		if (dst > src)
		{
			offset = len - 1;
			sign = -1;
		}
		while (i < len)
		{
			dst_str[offset + i * sign] = src_str[offset + i * sign];
			i++;
		}
	}
	return (dst);
}
