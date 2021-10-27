#include "../include/ft_printf.h"

int	print_string(char *string, int *flags, char format)
{
	char	*new_str;
	int		len;

	if (!string)
		return (print_string("(null)", flags, format));
	new_str = ft_strdup(string);
	handle_flags(&new_str, flags, format);
	ft_putstr_fd(new_str, STDOUT_FILENO);
	len = ft_strlen(new_str);
	free(new_str);
	return (len);
}
