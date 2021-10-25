#include "../ft_printf.h"

int	print_string(char *string, int *flags)
{
	ft_putstr_fd(string, STDOUT_FILENO);
	return (ft_strlen(string));
}
