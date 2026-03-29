char	*ft_strrchr(const char *s, int c)
{
	const char	*r;

	if (c == 0)
	{
		while (*s)
			s++;
		r = s;
	}
	else
	{
		r = 0;
		while (*s)
		{
			if (*s == (char)c)
				r = s;
			s++;
		}
	}
	return ((char *)r);
}
