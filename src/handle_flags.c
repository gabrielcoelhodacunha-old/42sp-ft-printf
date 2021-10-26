#include "ft_printf.h"

void	initialize_flags(int *flags)
{
	int	flag;

	flag = -1;
	while (++flag < NUMBER_OF_FLAGS)
		flags[flag] = 0;
}
