/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:32:44 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/19 20:32:47 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int			size;
	long long	nb;

	size = 0;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		size += ft_putchar('-');
	}
	if (nb < 10)
	{
		size += ft_putchar(nb + '0');
	}
	else
	{
		size += ft_putnbr(nb / 10);
		size += ft_putnbr(nb % 10);
	}
	return (size);
}
