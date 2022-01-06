/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:04:29 by ralena            #+#    #+#             */
/*   Updated: 2021/11/29 20:04:30 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*(unsigned char *)s)
	{
		if (*(unsigned char *)s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*(unsigned char *)s == (char)c)
		return ((char *)s);
	return (NULL);
}
