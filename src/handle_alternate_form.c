#include "../include/ft_printf.h"

void	handle_alternate_form(char **str, char format)
{
	char	*old_str;

	old_str = *str;
	if (format == 'x')
		*str = ft_strjoin("0x", old_str);
	else if (format == 'X')
		*str = ft_strjoin("0X", old_str);
	else
		*str = ft_strdup(old_str);
	free(old_str);
}
