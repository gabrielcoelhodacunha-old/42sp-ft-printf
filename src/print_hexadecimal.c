/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:14:01 by gcoelho-          #+#    #+#             */
/*   Updated: 2021/10/29 15:23:41 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	to_upper(unsigned int iteration, char *str);

int	print_hexadecimal(t_ull decimal, size_t *flags, char format)
{
	char	*hexadecimal;
	int		len;

	hexadecimal = ft_uitoa_base(decimal, "0123456789abcdef");
	if (format == 'X')
		ft_striteri(hexadecimal, to_upper);
	len = print_string(hexadecimal, flags, format);
	free(hexadecimal);
	return (len);
}

static void	to_upper(unsigned int iteration, char *str)
{
	(void) iteration;
	*str = ft_toupper(*str);
}
