#include "../include/ft_printf.h"

void	handle_flags(char **str, size_t *flags, char format)
{
	if (!flags)
		return ;
	handle_precision(str, flags, format);
	handle_alternate_form(str, flags, format);
	handle_width(str, flags, format);
}
