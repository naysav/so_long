/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:04:54 by ralena            #+#    #+#             */
/*   Updated: 2021/11/29 20:04:54 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		len_trimstr;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == '\0')
		return (ft_strdup(""));
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len_trimstr = 0;
	while (s1[len_trimstr])
		len_trimstr++;
	while (ft_strchr(set, s1[len_trimstr]) && len_trimstr)
		len_trimstr--;
	len_trimstr++;
	result = ft_substr(s1, 0, len_trimstr);
	return (result);
}
