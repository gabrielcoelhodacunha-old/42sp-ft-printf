#include "../include/ft_printf.h"

int	print_string(char *string, int *flags, char format)
{
	(void) flags;
	(void) format;
	if (!string)
		return (print_string("(null)", flags, format));
	ft_putstr_fd(string, STDOUT_FILENO);
	return (ft_strlen(string));
}
