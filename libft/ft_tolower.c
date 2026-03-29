static int	ft_isupper(int c);

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		c += 32;
	return (c);
}

static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
