/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:33:01 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/19 20:33:56 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert(unsigned long long n)
{
	char	*point;
	int		size;

	point = "0123456789abcdef";
	size = 0;
	if (n < 16)
	{
		size += write(1, point + n, 1);
	}
	if (n >= 16)
	{
		size += convert (n / 16);
		size += convert (n % 16);
	}
	return (size);
}

int	ft_putpoint(unsigned long long n)
{
	if (!n)
		return (write(1, "(nil)", 5));
	else
	{
		write (1, "0x", 2);
		return (convert(n) + 2);
	}
}
