#include "../include/ft_printf.h"

void	handle_signed(char **str, size_t *flags)
{
	char	*old_str;

	if (!flags[SIGNED] || **str == '-')
		return ;
	old_str = *str;
	*str = ft_strjoin("+", old_str);
	free(old_str);
}
