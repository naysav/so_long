/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:02:42 by ralena            #+#    #+#             */
/*   Updated: 2021/11/29 20:02:43 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	prepare_images(t_info *info)
{
	int	r;
	int	c;

	r = 0;
	c = 0;
	info->img_1 = mlx_xpm_file_to_image(info->mlx, "./img/1.xpm", \
		&r, &c);
	info->img_0 = mlx_xpm_file_to_image(info->mlx, "./img/0.xpm", \
		&r, &c);
	info->img_c = mlx_xpm_file_to_image(info->mlx, "./img/C.xpm", \
		&r, &c);
	info->img_e = mlx_xpm_file_to_image(info->mlx, "./img/E.xpm", \
		&r, &c);
	info->img_p = mlx_xpm_file_to_image(info->mlx, "./img/P.xpm", \
		&r, &c);
	info->img_win = mlx_xpm_file_to_image(info->mlx, "./img/win.xpm", \
		&r, &c);
}

int	put_map_to_window(t_info *info, int c, int r)
{
	while (r < info->rows)
	{
		c = 0;
		while (c < info->columns)
		{
			if (info->map[r][c] == '1')
				mlx_put_image_to_window(info->mlx, info->mlx_win, \
					info->img_1, c * 32, r * 32);
			if (info->map[r][c] == '0')
				mlx_put_image_to_window(info->mlx, info->mlx_win, \
					info->img_0, c * 32, r * 32);
			if (info->map[r][c] == 'C')
				mlx_put_image_to_window(info->mlx, info->mlx_win, \
					info->img_c, c * 32, r * 32);
			if (info->map[r][c] == 'E')
				mlx_put_image_to_window(info->mlx, info->mlx_win, \
					info->img_e, c * 32, r * 32);
			if (info->map[r][c] == 'P')
				mlx_put_image_to_window(info->mlx, info->mlx_win, \
					info->img_p, c * 32, r * 32);
			c++;
		}
		r++;
	}
	return (0);
}

int	put_to_window(t_info *info)
{
	static int	counter;

	mlx_clear_window(info->mlx, info->mlx_win);
	if (info->status == WIN)
	{
		counter++;
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->img_win,
			info->columns * 16 - 48, info->rows * 16 - 48);
		if (counter == 250)
			close_game(info);
	}
	else
		put_map_to_window(info, 0, 0);
	return (0);
}
