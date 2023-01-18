/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:44:00 by antoda-s          #+#    #+#             */
/*   Updated: 2022/11/21 00:51:17 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lsthead;
	t_list	*lstnew;

	if (!lst)
		return (NULL);
	lstnew = ft_lstnew(f((*lst).content));
	if (!lstnew)
		return (NULL);
	lsthead = lstnew;
	while (lst)
	{
		if ((*lst).next)
		{
			(*lstnew).next = ft_lstnew(f((*(*lst).next).content));
			if (!(*lstnew).next)
			{
				ft_lstdelone(lstnew, del);
				return (NULL);
			}
			lstnew = (*lstnew).next;
		}
		lst = (*lst).next;
	}
	(*lstnew).next = NULL;
	return (lsthead);
}
