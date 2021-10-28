#include "../include/ft_printf.h"

void	set_flags(char format, size_t *flags)
{
	if (ft_strchr("p", format))
		flags[ALTERNATE_FORM] = 1;
	if ((!ft_strchr("di", format) && flags[BLANK])
		|| (ft_strchr("di", format) && flags[SIGNED]))
		flags[BLANK] = 0;
	if (ft_strchr("diuxX", format) && flags[PRECISION_WIDTH])
		flags[ZERO_PADDING] = 1;
	if (flags[NEGATIVE_WIDTH])
		flags[ZERO_PADDING] = 0;
}
