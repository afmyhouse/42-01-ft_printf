/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:48:42 by nmoreira          #+#    #+#             */
/*   Updated: 2022/11/19 13:48:48 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenptr(unsigned long long nbr)
{
	int	i;

	i = 0;
	while (nbr)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

void	ft_writeptr(unsigned long long nbr)
{
	char	c;

	if (nbr >= 16)
	{
		ft_writeptr(nbr / 16);
		ft_writeptr(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
		{
			c = nbr + 48;
			write(1, &c, 1);
		}
		else
		{
			c = (nbr - 10) + 'a';
			write(1, &c, 1);
		}
	}
}

int	ft_printptr(void *ptr)
{
	int					len;
	unsigned long long	nbr;

	len = 0;
	nbr = (unsigned long long)ptr;
	if (!ptr)
		len += write (1, "(nil)", 5);
	else
	{
		write(1, "0x", 2);
		ft_writeptr(nbr);
		len += ft_lenptr(nbr) + 2;
	}
	return (len);
}
