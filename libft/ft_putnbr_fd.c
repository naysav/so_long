/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:04:20 by ralena            #+#    #+#             */
/*   Updated: 2021/11/29 20:04:21 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int c, int fd)
{
	long int	number;

	number = c;
	if (number < 0)
	{
		write(fd, "-", 1);
		number *= -1;
	}
	if (number > 9)
		ft_putnbr_fd((number / 10), fd);
	ft_putchar_fd(('0' + (number % 10)), fd);
}
