/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:14:01 by gcoelho-          #+#    #+#             */
/*   Updated: 2021/10/29 15:06:15 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	initialize_flags(size_t *flags);
static int	print_format(char format, va_list args, size_t *flags);

int	print_formated(const char **format, va_list args)
{
	size_t	flags[NUMBER_OF_FLAGS];

	(*format)++;
	initialize_flags(flags);
	get_flags(format, flags);
	set_flags(**format, flags);
	return (print_format(*(*format)++, args, flags));
}

static int	print_format(char format, va_list args, size_t *flags)
{
	if (ft_strchr("c", format))
		return (print_char(va_arg(args, int), flags));
	else if (ft_strchr("s", format))
		return (print_string(va_arg(args, char *), flags, format));
	else if (ft_strchr("p", format))
		return (print_pointer(va_arg(args, void *), flags));
	else if (ft_strchr("di", format))
		return (print_signed_decimal(va_arg(args, int), flags));
	else if (ft_strchr("u", format))
		return (print_unsigned_decimal(va_arg(args, unsigned), flags));
	else if (ft_strchr("xX", format))
		return (print_hexadecimal(va_arg(args, unsigned), flags, format));
	else if (ft_strchr("%", format))
		return (print_char('%', NULL));
	return (-1);
}

static void	initialize_flags(size_t *flags)
{
	int	flag;

	flag = -1;
	while (++flag < NUMBER_OF_FLAGS)
		flags[flag] = 0;
}
