/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:41:59 by antoda-s          #+#    #+#             */
/*   Updated: 2022/11/21 00:49:50 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lstclear;
	t_list	*lstnext;

	if (!lst)
		return ;
	lstclear = *lst;
	while (lstclear)
	{
		lstnext = (*lstclear).next;
		ft_lstdelone(lstclear, del);
		lstclear = lstnext;
	}
	*lst = NULL;
}
