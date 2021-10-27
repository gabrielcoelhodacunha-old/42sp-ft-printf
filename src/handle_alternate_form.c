#include "../include/ft_printf.h"

void	handle_alternate_form(char **str, char format)
{
	char	*new_str;

	if (format == 'x')
		new_str = ft_strjoin("0x", *str);
	else if (format == 'X')
		new_str = ft_strjoin("0X", *str);
	else
		new_str = ft_strdup(*str);
	free(*str);
	*str = new_str;
}
