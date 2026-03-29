#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*found;
	size_t		needle_length;

	found = 0;
	needle_length = ft_strlen(needle);
	if (*needle == 0)
		found = haystack;
	if (len)
	{
		while (*haystack && len-- >= needle_length && !found)
		{
			if (!ft_memcmp(haystack, needle, needle_length))
				found = haystack;
			haystack++;
		}
	}
	return ((char *)found);
}
