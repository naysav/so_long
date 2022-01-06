/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:02:44 by ralena            #+#    #+#             */
/*   Updated: 2021/11/29 20:02:45 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	press_w(t_info *info)
{
	if (info->map[info->h_p - 1][info->w_p] == '0')
	{
		info->map[info->h_p - 1][info->w_p] = 'P';
		info->map[info->h_p][info->w_p] = '0';
		info->moves++;
		info->h_p--;
		info->is_moved = 1;
	}
	else if (info->map[info->h_p - 1][info->w_p] == 'C')
	{
		info->map[info->h_p - 1][info->w_p] = 'P';
		info->map[info->h_p][info->w_p] = '0';
		info->collectibles--;
		info->moves++;
		info->h_p--;
		info->is_moved = 1;
	}
	else if (!info->collectibles && !info->status
		&& info->map[info->h_p - 1][info->w_p] == 'E')
		info->status = WIN;
	return (0);
}

int	press_s(t_info *info)
{
	if (info->map[info->h_p + 1][info->w_p] == '0')
	{
		info->map[info->h_p + 1][info->w_p] = 'P';
		info->map[info->h_p][info->w_p] = '0';
		info->moves++;
		info->h_p++;
		info->is_moved = 1;
	}
	else if (info->map[info->h_p + 1][info->w_p] == 'C')
	{
		info->map[info->h_p + 1][info->w_p] = 'P';
		info->map[info->h_p][info->w_p] = '0';
		info->collectibles--;
		info->moves++;
		info->h_p++;
		info->is_moved = 1;
	}
	else if (!info->collectibles && !info->status
		&& info->map[info->h_p + 1][info->w_p] == 'E')
		info->status = WIN;
	return (0);
}

int	press_a(t_info *info)
{
	if (info->map[info->h_p][info->w_p - 1] == '0')
	{
		info->map[info->h_p][info->w_p - 1] = 'P';
		info->map[info->h_p][info->w_p] = '0';
		info->moves++;
		info->w_p--;
		info->is_moved = 1;
	}
	else if (info->map[info->h_p][info->w_p - 1] == 'C')
	{
		info->map[info->h_p][info->w_p - 1] = 'P';
		info->map[info->h_p][info->w_p] = '0';
		info->collectibles--;
		info->moves++;
		info->w_p--;
		info->is_moved = 1;
	}
	else if (!info->collectibles && !info->status
		&& info->map[info->h_p][info->w_p - 1] == 'E')
		info->status = WIN;
	return (0);
}

int	press_d(t_info *info)
{
	if (info->map[info->h_p][info->w_p + 1] == '0')
	{
		info->map[info->h_p][info->w_p + 1] = 'P';
		info->map[info->h_p][info->w_p] = '0';
		info->moves++;
		info->w_p++;
		info->is_moved = 1;
	}
	else if (info->map[info->h_p][info->w_p + 1] == 'C')
	{
		info->map[info->h_p][info->w_p + 1] = 'P';
		info->map[info->h_p][info->w_p] = '0';
		info->collectibles--;
		info->moves++;
		info->w_p++;
		info->is_moved = 1;
	}
	else if (!info->collectibles && !info->status
		&& info->map[info->h_p][info->w_p + 1] == 'E')
		info->status = WIN;
	return (0);
}
