#include "../include/ft_printf.h"

int	print_pointer(void *pointer, int *flags)
{
	return (print_hexadecimal((unsigned int) pointer, flags, 'x'));
}
