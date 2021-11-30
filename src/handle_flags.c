/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:14:01 by gcoelho-          #+#    #+#             */
/*   Updated: 2021/10/29 13:30:44 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_flags(char **str, size_t *flags, char format)
{
	if (!flags)
		return ;
	handle_precision(str, flags, format);
	handle_alternate_form(str, flags, format);
	handle_signed(str, flags);
	handle_blank(str, flags);
	handle_width(str, flags, format);
}
