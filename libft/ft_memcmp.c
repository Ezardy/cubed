#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = s1;
	str2 = s2;
	if (n--)
	{
		while (n && *str1 == *str2)
		{
			n--;
			str1++;
			str2++;
		}
	}
	else
		str2 = str1;
	return (*str1 - *str2);
}
