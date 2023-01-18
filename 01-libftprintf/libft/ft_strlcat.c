/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:59:06 by antoda-s          #+#    #+#             */
/*   Updated: 2022/11/29 00:57:12 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	char		*d;
	const char	*s;
	size_t		dst_free;
	size_t		dst_busy;

	dst_free = dst_size;
	d = dst;
	s = src;
	while (dst_free-- && *d)
		d++;
	dst_busy = d - dst;
	dst_free = dst_size - dst_busy;
	if (dst_free)
	{
		while (*s && dst_free-- > 1)
			*d++ = *s++;
		*d = '\0';
	}
	return (dst_busy + ft_strlen(src));
}
