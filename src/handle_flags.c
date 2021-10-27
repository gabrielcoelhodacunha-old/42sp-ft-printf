#include "../include/ft_printf.h"

void	handle_flags(char **str, int *flags, char format)
{
	if (!flags)
		return ;
	if (flags[ALTERNATE_FORM])
		handle_alternate_form(str, format);
}
