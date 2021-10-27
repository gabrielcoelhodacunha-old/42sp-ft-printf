#include "../include/ft_printf.h"

static void	to_upper(unsigned int iteration, char *str);

int	print_hexadecimal(unsigned int decimal, int *flags, char format)
{
	char	*hexadecimal;
	int		len;

	hexadecimal = ft_uitoa_base(decimal, "0123456789abcdef");
	if (format == 'X')
		ft_striteri(hexadecimal, to_upper);
	len = print_string(hexadecimal, flags, format);
	free(hexadecimal);
	return (len);
}

static void	to_upper(unsigned int iteration, char *str)
{
	(void) iteration;
	*str = ft_toupper(*str);
}
