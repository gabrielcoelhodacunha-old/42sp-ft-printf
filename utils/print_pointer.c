#include "../ft_printf.h"

int	print_pointer(void *pointer, int *flags)
{
	flags[ALTERNATE_FORM] = 1;
	return (print_hexadecimal((int) pointer, flags, 'x'));
}
