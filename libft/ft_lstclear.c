/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:03:42 by ralena            #+#    #+#             */
/*   Updated: 2021/11/29 20:03:42 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temporare;

	if (lst && del)
	{
		while (*lst)
		{
			temporare = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = temporare;
		}
	}
}
