/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:03:34 by ralena            #+#    #+#             */
/*   Updated: 2021/11/29 20:03:34 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (new != NULL)
	{
		head = *lst;
		if (head == NULL)
			*lst = new;
		else
		{
			while (head->next != NULL)
				head = head->next;
			head->next = new;
		}
	}
}
