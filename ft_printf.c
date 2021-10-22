#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*format_specifier;
	int		len;
	int		char_count;

	if (!format)
		return (-1);
	va_start(args, format);
	char_count = 0;
	while (*format)
	{
		format_specifier = get_format_specifier(format);
		if (format_specifier)
			len = print_formated(&format, args);
		else
			len = print_without_format(&format, format_specifier);
		if (len == -1)
			return (-1);
		char_count += len;
	}
	va_end(args);
	return (char_count);
}
