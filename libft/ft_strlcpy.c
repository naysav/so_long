/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:04:40 by ralena            #+#    #+#             */
/*   Updated: 2021/11/29 20:04:41 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	result;

	result = 0;
	if (!dst || !src)
		return ((size_t) NULL);
	if (size)
	{
		while (src[result] && (result < (size - 1)))
		{
			dst[result] = src[result];
			result++;
		}
		dst[result] = '\0';
	}
	result = 0;
	while (src[result])
		result++;
	return (result);
}
