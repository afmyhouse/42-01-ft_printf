/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:24:38 by antoda-s          #+#    #+#             */
/*   Updated: 2022/12/01 15:51:01 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*p_s;

	p_s = (unsigned char *)s;
	while (*p_s)
		p_s++;
	while (p_s >= (unsigned char *)s && *p_s != (unsigned char)c)
		p_s--;
	if (*p_s == (unsigned char)c)
		return ((char *)p_s);
	return (NULL);
}
