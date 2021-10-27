#include "../include/ft_printf.h"

int	print_unsigned_decimal(t_ull decimal, int *flags)
{
	char	*str;
	int	len;

	str = ft_uitoa_base(decimal, "0123456789");
	len = print_string(str, flags, 'u');
	free(str);
	return (len);
}
