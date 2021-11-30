/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:14:01 by gcoelho-          #+#    #+#             */
/*   Updated: 2021/10/29 10:14:01 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *string, size_t *flags, char format)
{
	char	*new_str;
	int		len;

	if (!string)
		return (print_string("(null)", flags, format));
	new_str = ft_strdup(string);
	handle_flags(&new_str, flags, format);
	if (!new_str)
		return (-1);
	ft_putstr_fd(new_str, STDOUT_FILENO);
	len = ft_strlen(new_str);
	free(new_str);
	return (len);
}
