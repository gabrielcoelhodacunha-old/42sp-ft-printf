#include "../include/ft_printf.h"

void	handle_flags(char **str, int *flags, char format)
{
	if (!flags)
		return ;
	handle_alternate_form(str, flags, format);
}
