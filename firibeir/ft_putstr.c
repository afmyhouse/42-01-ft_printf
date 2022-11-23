/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:33:10 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/19 20:33:12 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	size;

	size = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[size] != '\0')
	{
		ft_putchar(s[size]);
		size++;
	}
	return (size);
}
// #include<stdio.h>
// int main()
// {
// 	int i = ft_printf("  %%   ");
// 	printf("\n%d", i);
// }
