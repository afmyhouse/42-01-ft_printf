/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_low.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:32:29 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/19 20:32:31 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_low(unsigned long long n)
{
	char	*hex_down;
	int		size;

	size = 0;
	hex_down = "0123456789abcdef";
	if (n < 16)
	{
		size += write (1, hex_down + n, 1);
	}
	if (n >= 16)
	{	
		size += ft_puthexa_low (n / 16);
		size += ft_puthexa_low (n % 16);
	}
	return (size);
}
