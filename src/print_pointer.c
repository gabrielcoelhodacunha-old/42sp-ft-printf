#include "../include/ft_printf.h"

int	print_pointer(void *pointer, size_t *flags)
{
	return (print_hexadecimal((t_ull) pointer, flags, 'p'));
}
