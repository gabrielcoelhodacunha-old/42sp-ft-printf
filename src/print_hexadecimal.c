#include "../ft_printf.h"

static void	to_upper(unsigned int iteration, char *str);
static int	handle_flags(int decimal, int *flags, char format);

int	print_hexadecimal(int decimal, int *flags, char format)
{
	char	*hexadecimal;
	int		len;

	hexadecimal = ft_itoa_hexadecimal(decimal);
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
