#include "ft_printf.h"

int	print_char(char c, int *flags)
{
	flags[0] = 1;
	ft_putchar_fd(c, STDOUT_FILENO);
	return (1);
}
