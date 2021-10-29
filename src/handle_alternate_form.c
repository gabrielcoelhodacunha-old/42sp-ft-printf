#include "../include/ft_printf.h"

void	handle_alternate_form(char **str, size_t *flags, char format)
{
	char	*old_str;

	if (!flags[ALTERNATE_FORM]
		|| (ft_strchr("xX", format) && **str == '0'))
		return ;
	old_str = *str;
	if (ft_strchr("px", format))
		*str = ft_strjoin("0x", old_str);
	else if (format == 'X')
		*str = ft_strjoin("0X", old_str);
	else
		*str = ft_strdup(old_str);
	free(old_str);
}
