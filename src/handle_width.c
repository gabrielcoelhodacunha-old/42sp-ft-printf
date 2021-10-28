#include "../include/ft_printf.h"

void	handle_width(char **str, size_t *flags, char format)
{
	char	*old_str;
	char	*width_adjustment;
	size_t	width;
	size_t	len;

	(void) format;
	len = ft_strlen(*str);
	if (!len)
		len = 1;
	if ((!flags[FIELD_WIDTH] && !flags[PRECISION_WIDTH])
		|| flags[FIELD_WIDTH] <= len)
		return ;
	old_str = *str;
	width = flags[FIELD_WIDTH] - len;
	width_adjustment = malloc(width + 1);
	if (!width_adjustment)
	{
		free(*str);
		*str = NULL;
		return ;
	}
	width_adjustment[width] = '\0';
	if (flags[ZERO_PADDING])
		ft_memset(width_adjustment, '0', width);
	else
		ft_memset(width_adjustment, ' ', width);
	if (flags[NEGATIVE_WIDTH])
		*str = ft_strjoin(old_str, width_adjustment);
	else
		*str = ft_strjoin(width_adjustment, old_str);
	free(width_adjustment);
	free(old_str);
}
