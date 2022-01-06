/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:04:49 by ralena            #+#    #+#             */
/*   Updated: 2021/11/29 20:04:50 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	counter;
	size_t	length;

	if (*little == '\0')
		return ((char *)big);
	length = 0;
	while (little[length])
		length++;
	while (len && *big)
	{
		counter = 0;
		while (counter < length && counter < len
			&& *(unsigned char *)(big + counter)
			== *(unsigned char *)(little + counter))
		{
			if (*(unsigned char *)(little + counter + 1) == '\0')
				return ((char *)(big));
			counter++;
		}
		big++;
		len--;
	}
	return ((char *) NULL);
}
