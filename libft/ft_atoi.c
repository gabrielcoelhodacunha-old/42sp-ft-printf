/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:35:14 by gcoelho-          #+#    #+#             */
/*   Updated: 2021/09/10 18:35:14 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c);
static void	remove_whitespaces(const char **nptr);
static int	determine_sign(const char **nptr);

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	nbr;

	remove_whitespaces(&nptr);
	sign = determine_sign(&nptr);
	nbr = 0;
	while (ft_isdigit(*nptr)
		&& nbr >= INT_MIN && nbr <= INT_MAX)
		nbr = nbr * 10 + (*(nptr++) - '0');
	nbr *= sign;
	if (nbr < INT_MIN)
		return (0);
	if (nbr > INT_MAX)
		return (-1);
	return (nbr);
}

static int	determine_sign(const char **nptr)
{
	int	sign;

	sign = 1;
	if (**nptr == '-')
		sign = -1;
	if (**nptr == '-' || **nptr == '+')
		(*nptr)++;
	return (sign);
}

static void	remove_whitespaces(const char **nptr)
{
	while (ft_isspace(**nptr))
		(*nptr)++;
}

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}
