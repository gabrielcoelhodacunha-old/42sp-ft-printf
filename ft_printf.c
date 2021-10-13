#include "ft_printf.h"

int	print_type(const char *format, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	char_count;
	char	*percent;
	char	*aux;
	size_t	aux_len;

	if (!format)
		return (0);
	va_start(args, format);
	char_count = 0;
	while (*format)
	{
		percent = ft_strchr(format, '%');
		aux = ft_substr(format, 0, percent - format);
		ft_putstr_fd(aux, STDOUT_FILENO);
		aux_len = ft_strlen(aux);
		char_count += aux_len;
		format += aux_len;
		if (percent)
			char_count += print_type(++format, args);
		free(aux);
	}
	va_end(args);
	return (char_count);
}

int	print_type(const char *format, va_list args)
{
	switch(*format)
	{
		case 'c':
		case 's':
		case 'p':
		case 'd': case 'i':
		case 'u':
		case 'x':
		case 'X':
		case '%':
		default:
			return (0);
	}
	va_arg(args, int);
}
