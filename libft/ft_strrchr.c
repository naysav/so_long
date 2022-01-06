/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:04:52 by ralena            #+#    #+#             */
/*   Updated: 2021/11/29 20:04:53 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	counter;

	counter = 0;
	while (((unsigned char *)s)[counter])
		counter++;
	if (((unsigned char *)s)[counter] == (char)c)
		return ((char *)(s + counter));
	while (counter >= 0)
	{
		if (((unsigned char *)s)[counter] == (char)c)
			return ((char *)(s + counter));
		counter--;
	}
	return (NULL);
}
