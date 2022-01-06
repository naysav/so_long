/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:04:05 by ralena            #+#    #+#             */
/*   Updated: 2021/11/29 20:04:06 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*string;
	unsigned char	*result;
	size_t			counter;

	if (!n || dest == src)
		return (dest);
	counter = 0;
	string = (unsigned char *)src;
	result = (unsigned char *)dest;
	while (counter < n)
	{
		result[counter] = string[counter];
		counter++;
	}
	return (dest);
}
