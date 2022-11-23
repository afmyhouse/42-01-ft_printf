/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:32:53 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/19 20:32:55 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nb)
{
	int	size;

	size = 0;
	if (nb < 10)
	{
		size += ft_putchar(nb + 48);
	}
	else
	{
		size += ft_putnbr_u(nb / 10);
		size += ft_putnbr_u(nb % 10);
	}
	return (size);
}
