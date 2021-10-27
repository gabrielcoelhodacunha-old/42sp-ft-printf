#include "../include/ft_printf.h"

int	print_signed_decimal(t_ll decimal, int *flags)
{
	char	*decimal_str;
	int		len;

	decimal_str = ft_itoa((int) decimal);
	len = print_string(decimal_str, flags, 'd');
	free(decimal_str);
	return (len);
}
