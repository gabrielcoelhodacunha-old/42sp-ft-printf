/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:35:13 by gcoelho-          #+#    #+#             */
/*   Updated: 2021/09/10 18:35:13 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	size_t				idx;
	const unsigned char	*s1;
	const unsigned char	*s2;

	idx = -1;
	s1 = b1;
	s2 = b2;
	while (++idx < len)
		if (s1[idx] != s2[idx])
			return (s1[idx] - s2[idx]);
	return (0);
}
