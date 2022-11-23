/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:46:35 by antoda-s          #+#    #+#             */
/*   Updated: 2022/11/23 16:46:43 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printformat(va_list args, const char f)
{
	int	plen;

	plen = 0;
	if (f == 'c')
		plen = ft_printchar(va_arg(args, int));
	if (f == 's')
		plen = ft_printstr(va_arg(args, char *));
	if (f == 'p')
		plen = ft_printptr(va_arg(args, void *));
	if (f == 'd' || f == 'i')
		plen = ft_printnbr(va_arg(args, int));
	if (f == 'u')
		plen = ft_printuint(va_arg(args, unsigned int));
	if (f == 'x' || f == 'X')
		plen = ft_printhex(va_arg(args, unsigned int), f);
	if (f == '%')
		plen = ft_printperc(f);
	return (plen);
}

int	ft_printf(const char *str, ...)
{
	int		plen;
	int		i;
	va_list	args;

	plen = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			plen += ft_printformat(args, str[i + 1]);
			i++;
		}
		else
		{
			plen += ft_printchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (plen);
}
