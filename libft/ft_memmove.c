/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:04:07 by ralena            #+#    #+#             */
/*   Updated: 2021/11/29 20:04:08 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	counter;

	if (!dest && !src)
		return (NULL);
	counter = 0;
	if ((unsigned char *)dest > (unsigned char *)src)
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	else
	{
		while (counter < n)
		{
			((unsigned char *)dest)[counter] = *(unsigned char *)(src++);
			counter++;
		}
	}
	return (dest);
}
