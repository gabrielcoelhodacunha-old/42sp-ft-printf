#include "../include/ft_printf.h"

static size_t	determine_len(unsigned int un);
static void		convert(unsigned int un, char *str, size_t len);

char	*ft_itoa_hexadecimal(int n)
{
	unsigned int	un;
	size_t			len;
	char			*str;

	len = 0;
	un = n;
	if (n < 0)
		un *= -1;
	len += determine_len(un);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	convert(un, str, len - 1);
	str[len] = '\0';
	return (str);
}

static void	convert(unsigned int un, char *str, size_t len)
{
	if (un > 15)
		convert(un / 16, str, len - 1);
	if (un < 10)
		str[len] = (un % 10) + '0';
	else
		str[len] = (un % 10) + 'a';
}

static size_t	determine_len(unsigned int un)
{
	size_t len;

	len = 1;
	while (un > 15)
	{
		un /= 16;
		len++;
	}
	return (len);
}
