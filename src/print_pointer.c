#include "../include/ft_printf.h"

int	print_pointer(void *pointer, int *flags)
{
	return (print_hexadecimal((t_ull) pointer, flags, 'x'));
}
