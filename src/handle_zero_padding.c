#include "../include/ft_printf.h"

void	handle_zero_padding(char **str, int *flags)
{
	char	*old_str;
	char	*zeros;
	int		width;

	if (!flags[ZERO_PADDING])
		return ;
	width = flags[FIELD_WIDTH];
	if (flags[PRECISION_WIDTH])
		width = flags[PRECISION_WIDTH];
	width = ft_strlen(*str) - width;
	old_str = *str;
	zeros = malloc(width + 1);
	if (!zeros)
		return ;
	ft_memset(zeros, '0', width);
	zeros[width] = '\0';
	*str = ft_strjoin(zeros, old_str);
	free(old_str);
}
