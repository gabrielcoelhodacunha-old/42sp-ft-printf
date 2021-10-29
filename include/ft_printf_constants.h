/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_constants.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:48:08 by gcoelho-          #+#    #+#             */
/*   Updated: 2021/10/29 13:10:46 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CONSTANTS_H
# define FT_PRINTF_CONSTANTS_H
# define FLAGS "-.# +"
# define NUMBER_OF_FLAGS 8

enum {
	NEGATIVE_WIDTH,
	PRECISION,
	ALTERNATE_FORM,
	BLANK,
	SIGNED,
	ZERO_PADDING,
	FIELD_WIDTH,
	PRECISION_WIDTH
} e_flags;

#endif
