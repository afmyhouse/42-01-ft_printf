/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:32:37 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/19 20:32:39 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_up(unsigned long long n)
{
	char	*hex_up;
	int		size;

	hex_up = "0123456789ABCDEF";
	size = 0;
	if (n < 16)
	{
		size += write(1, hex_up + n, 1);
	}
	if (n >= 16)
	{
		size += ft_puthexa_up (n / 16);
		size += ft_puthexa_up (n % 16);
	}
	return (size);
}
