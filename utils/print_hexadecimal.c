#include "../ft_printf.h"

static void	to_upper(unsigned int iteration, char *str);

int	print_hexadecimal(int decimal, int *flags, char format)
{
	char	*hexadecimal;
	int		len;

	hexadecimal = ft_itoa_hexadecimal(decimal);
	if (format == 'X')
		ft_striteri(hexadecimal, to_upper);
	len = print_string(hexadecimal, flags);
	free(hexadecimal);
	return (len);
}

static void	to_upper(unsigned int iteration, char *str)
{
	*str = ft_toupper(str[iteration]);
}
