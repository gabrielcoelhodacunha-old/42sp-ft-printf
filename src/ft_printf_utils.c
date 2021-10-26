#include "../ft_printf.h"

char	*get_format_specifier(const char *format)
{
	return (ft_strchr(format, '%'));
}

int	print_without_format(const char **format, char *format_specifier)
{
	char	*str_without_format;
	size_t	len;

	len = format_specifier - *format;
	if (!format_specifier)
		len = ft_strlen(*format);
	str_without_format = ft_substr(*format, 0, len);
	if (!str_without_format)
		return (-1);
	print_string(str_without_format, NULL, 's');
	(*format) += len;
	free(str_without_format);
	return (len);
}

void	change_width(int *flags, char number)
{
	int	flag;

	if (flags[PRECISION])
		flag = PRECISION_WIDTH;
	else
		flag = FIELD_WIDTH;
	flags[flag] *= 10;
	flags[flag] += number - '0';
}

int	is_type(char c)
{
	return (1 && ft_strchr(TYPES, c));
}

int	is_flag(char c)
{
	return (ft_isdigit(c) || ft_strchr(FLAGS, c));
}

void	check_flags(const char **format, int *flags)
{
	char	*flag;

	while (is_flag(**format))
	{
		flag = ft_strchr(FLAGS, **format);
		if (**format == '0'
			&& (!flags[PRECISION_WIDTH] || !flags[FIELD_WIDTH]))
			flags[ZERO_PADDING]++;
		else if (ft_isdigit(**format))
			change_width(flags, **format);
		else if (flag)
			flags[flag - FLAGS]++;	
		(*format)++;
	}
}

int	print_format(char format, va_list args, int *flags)
{
	if (ft_strchr("c%", format))
		return (print_char(va_arg(args, int), flags));
	/*
	else if (ft_strchr("s", format))
		return (print_string(va_arg(args, char *), flags, format));
	else if (ft_strchr("p", format))
		return (print_pointer(va_arg(args, void *), flags));
	else if (ft_strchr("di", format))
		return (print_signed_decimal(va_arg(args, int), flags));
	else if (ft_strchr("u", format))
		return (print_unsigned_decimal(va_arg(args, int), flags));
	else if (ft_strchr("xX", format))
		return (print_hexadecimal(va_arg(args, int), flags, format));
	*/
	return (-1);
}

int	print_formated(const char **format, va_list args)
{
	int	flags[NUMBER_OF_FLAGS];

	(*format)++;
	initialize_flags(flags);
	check_flags(format, flags);
	return (print_format(*(*format)++, args, flags));
}
