/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:34:39 by antoda-s          #+#    #+#             */
/*   Updated: 2022/11/29 01:13:55 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t item_qty, size_t item_size)
{
	void	*ptr;

	if (item_qty == 0 || item_size == 0)
	{
		item_qty = 1;
		item_size = 1;
	}
	ptr = (void *)malloc (item_qty * item_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, item_qty * item_size);
	return ((void *)ptr);
}
