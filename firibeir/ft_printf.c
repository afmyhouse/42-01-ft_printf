/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:31:53 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/19 20:31:55 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char s, va_list ptr, int *size)
{
	if (s == 's')
		*size += ft_putstr (va_arg(ptr, char *));
	if (s == 'c')
		*size += ft_putchar (va_arg(ptr, int));
	if (s == 'd' || s == 'i')
		*size += ft_putnbr(va_arg(ptr, int));
	if (s == 'u')
		*size += ft_putnbr_u(va_arg(ptr, unsigned int));
	if (s == 'x')
		*size += ft_puthexa_low(va_arg(ptr, unsigned int));
	if (s == 'X')
		*size += ft_puthexa_up(va_arg(ptr, unsigned int));
	if (s == '%')
		*size += ft_putchar('%');
	if (s == 'p')
		*size += ft_putpoint(va_arg(ptr, unsigned long long));
	return (*size);
}

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	int		size;

	size = 0;
	va_start(ptr, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			ft_check(*s, ptr, &size);
		}
		else
			size += ft_putchar(*s);
		s++;
	}
	va_end(ptr);
	return (size);
}

/*#include<stdio.h>
int main()
{
	char fmt[] = "%d %s";
	int d;
	d = printf(fmt, 32, "dfdsg");
	fflush(stdout);
	printf("(%d)\n", d);
	fflush(stdout);
	d = ft_printf(fmt, 32, "dfdsg");
	printf("(%d)\n", d);
	fflush(stdout);
	
}*/
