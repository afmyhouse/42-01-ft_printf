/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:36:41 by nmoreira          #+#    #+#             */
/*   Updated: 2022/11/19 13:36:47 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenhex(unsigned int nbr)
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

void	ft_writehex(unsigned int nbr, const char f)
{
	char	c;

	if (nbr >= 16)
	{
		ft_writehex(nbr / 16, f);
		ft_writehex(nbr % 16, f);
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
			if (f == 'x')
				c = (nbr - 10) + 'a';
			if (f == 'X')
				c = (nbr - 10) + 'A';
			write(1, &c, 1);
		}
	}
}

int	ft_printhex(unsigned int nbr, const char f)
{
	int	len;

	len = 0;
	if (!nbr)
		len = write(1, "0", 1);
	else
	{
		ft_writehex(nbr, f);
		len += ft_lenhex(nbr);
	}
	return (len);
}
