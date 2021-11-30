/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:14:01 by gcoelho-          #+#    #+#             */
/*   Updated: 2021/10/29 10:14:01 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_format_specifier(const char *format);

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
		if (format_specifier == format)
			len = print_formated(&format, args);
		else
			len = print_without_format(&format, format_specifier);
		if (len < 0)
			return (-1);
		char_count += len;
	}
	va_end(args);
	return (char_count);
}

static char	*get_format_specifier(const char *format)
{
	return (ft_strchr(format, '%'));
}
