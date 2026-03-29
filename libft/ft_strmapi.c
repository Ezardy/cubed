#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	result = 0;
	if (s && f)
	{
		result = ft_strdup(s);
		if (result)
		{
			i = 0;
			while (result[i])
			{
				result[i] = f(i, result[i]);
				i++;
			}
		}
	}
	return (result);
}
