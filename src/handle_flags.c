#include "../include/ft_printf.h"

void	handle_flags(char **str, int *flags, char format)
{
	if (!flags)
		return ;
	handle_zero_padding(str, flags);
	handle_alternate_form(str, flags, format);
	/*
	handle_negative_width(str, flags, width);
	handle_blank(str, flags);
	handle_signed(str, flags);
	*/
}
