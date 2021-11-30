/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:14:01 by gcoelho-          #+#    #+#             */
/*   Updated: 2021/10/29 15:03:26 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, size_t *flags)
{
	char	str[2];
	int		len;

	str[0] = c;
	str[1] = '\0';
	len = 1;
	if (!c && flags[NEGATIVE_WIDTH])
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		len += print_string(str, flags, 'c');
	}
	else if (!c)
	{
		len += print_string(str, flags, 'c');
		ft_putchar_fd(c, STDOUT_FILENO);
	}
	else
		len = print_string(str, flags, 'c');
	return (len);
}
