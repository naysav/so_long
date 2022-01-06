/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:04:31 by ralena            #+#    #+#             */
/*   Updated: 2021/11/29 20:04:32 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		counter;
	char	*result;

	counter = 0;
	while (s[counter])
		counter++;
	result = (char *)malloc(sizeof(*s) * (counter + 1));
	if (result)
	{
		counter = 0;
		while (s[counter])
		{
			result[counter] = s[counter];
			counter++;
		}
		result[counter] = s[counter];
	}
	return (result);
}
