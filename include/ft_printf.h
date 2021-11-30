/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:14:00 by gcoelho-          #+#    #+#             */
/*   Updated: 2021/11/30 07:47:27 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# include "ft_printf_constants.h"
# include "ft_printf_types.h"

int		ft_printf(const char *format, ...);

int		print_without_format(const char **format, char *format_specifier);
int		print_formated(const char **format, va_list args);

/* CONVERSION HANDLING */
int		print_char(char c, size_t *flags);
int		print_string(char *string, size_t *flags, char format);
int		print_pointer(void *pointer, size_t *flags);
int		print_signed_decimal(t_ll decimal, size_t *flags);
int		print_unsigned_decimal(t_ull decimal, size_t *flags);
int		print_hexadecimal(t_ull decimal, size_t *flags, char format);

/* FLAG HANDLING */
void	get_flags(const char **format, size_t *flags);
void	set_flags(char format, size_t *flags);
void	handle_flags(char **str, size_t *flags, char format);
void	handle_precision(char **str, size_t *flags, char format);
void	handle_width(char **str, size_t *flags, char format);
void	handle_alternate_form(char **str, size_t *flags, char format);
void	handle_signed(char **str, size_t *flags);
void	handle_blank(char **str, size_t *flags);

/* EXTRA */
char	*ft_uitoa_base(t_ull un, char *base);

#endif
