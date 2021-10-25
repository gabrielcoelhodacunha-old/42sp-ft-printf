#include "../ft_printf.h"

int	print_char(char c, int *flags)
{
	ft_putchar_fd(c, STDOUT_FILENO);
	return (1);
}
