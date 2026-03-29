#include "libft.h"

static int	ft_isspace(unsigned char c);

int	ft_atoi(const char *str)
{
	int		num;
	char	sign;

	num = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = 1 - 2 * (*str == '-');
		str++;
	}
	while (ft_isdigit(*str))
		num = num * 10 + (*str++ - '0') * sign;
	return (num);
}

static int	ft_isspace(unsigned char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ');
}
