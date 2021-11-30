/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_without_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:14:01 by gcoelho-          #+#    #+#             */
/*   Updated: 2021/10/29 10:14:01 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
