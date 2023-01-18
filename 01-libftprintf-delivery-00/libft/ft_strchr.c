/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:27:02 by antoda-s          #+#    #+#             */
/*   Updated: 2022/11/30 14:39:16 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	*ft_strchr(const char *s, int c)
{
	unsigned char	*p_s;

	p_s = (unsigned char *)s;
	while (*p_s && *p_s != (unsigned char)c)
		p_s++;
	if (c == '\0' || *p_s == (unsigned char)c)
		return ((char *)p_s);
	return (NULL);
}
*/
char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (unsigned char)c)
		s++;
	if (c == '\0' || *s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
