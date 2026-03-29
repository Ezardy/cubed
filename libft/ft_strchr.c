char	*ft_strchr(const char *s, int c)
{
	const char	*r;

	r = 0;
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		r = s;
	return ((char *)r);
}
