/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:47:53 by antoda-s          #+#    #+#             */
/*   Updated: 2022/11/23 16:47:55 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenuint(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int nbr)
{
	unsigned int	len;
	char			*str;

	len = ft_lenuint(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (nbr)
	{
		str[len - 1] = nbr % 10 + 48;
		len--;
		nbr = nbr / 10;
	}
	return (str);
}

int	ft_printuint(unsigned int nbr)
{
	unsigned int	len;
	char			*str;

	if (!nbr)
	len = write(1, "0", 1);
	else
	{
		str = ft_uitoa(nbr);
		ft_printstr(str);
		len = ft_lenuint(nbr);
		free(str);
		str = NULL;
	}
	return (len);
}
