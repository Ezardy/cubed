#include "libft/libft.h"

int	get_map_width(char **map)
{
	int	i;
	int	len;
	int	max;

	i = 0;
	max = 0;
	if (map)
	{
		while (map[i])
		{
			len = ft_strlen(map[i]);
			if (len > max)
				max = len;
			i++;
		}
	}
	return (max);
}

int	get_map_height(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
			i++;
	}
	return (i);
}
