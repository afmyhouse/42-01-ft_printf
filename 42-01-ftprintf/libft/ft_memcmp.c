/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:49:13 by antoda-s          #+#    #+#             */
/*   Updated: 2022/11/22 11:34:48 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p_str1;
	unsigned char	*p_str2;

	p_str1 = (unsigned char *)s1;
	p_str2 = (unsigned char *)s2;
	while (n--)
	{
		if (*p_str1++ != *p_str2++)
			return (p_str1[-1] - p_str2[-1]);
	}
	return (0);
}
