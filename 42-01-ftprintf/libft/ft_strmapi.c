/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:18:28 by antoda-s          #+#    #+#             */
/*   Updated: 2022/11/17 13:49:38 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p_s;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	p_s = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!p_s)
		return (NULL);
	while (i < (int)ft_strlen(s))
	{
		p_s[i] = f(i, s[i]);
		i++;
	}
	p_s[i] = '\0';
	return (p_s);
}
