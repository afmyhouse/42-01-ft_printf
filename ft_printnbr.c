/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:47:32 by antoda-s          #+#    #+#             */
/*   Updated: 2022/11/23 16:47:33 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenint(int nbr)
{
	int	len;

	len = 0;
	if (nbr < 0)
		len++;
	if (nbr == 0)
		len = 1;
	while (nbr)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	unsigned int	len;
	long int		unbr;
	char			*str;

	unbr = nbr;
	len = ft_lenint(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (unbr < 0)
	{
		str[0] = '-';
		unbr = -unbr;
	}
	if (unbr == 0)
		str[0] = '0';
	str[len] = '\0';
	while (unbr)
	{
		str[len - 1] = unbr % 10 + 48;
		len--;
		unbr = unbr / 10;
	}
	return (str);
}

int	ft_printnbr(int nbr)
{
	int		len;
	char	*str;

	len = 0;
	if (nbr == 0)
		len = write(1, "0", 1);
	else
	{
		str = ft_itoa(nbr);
		len = ft_printstr(str);
		free(str);
		str = NULL;
	}
	return (len);
}
