/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:24:28 by antoda-s          #+#    #+#             */
/*   Updated: 2022/11/30 12:21:59 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	len_ptr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start || !len)
	{
		ptr = (char *) malloc (sizeof (char));
		if (!ptr)
			return (NULL);
		*ptr = '\0';
		return (ptr);
	}
	if (ft_strlen(s) - start >= len)
		len_ptr = len + 1;
	else
		len_ptr = ft_strlen(s) - start + 1;
	ptr = (char *) malloc ((len_ptr) * sizeof (char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s + start, len_ptr);
	return (ptr);
}
