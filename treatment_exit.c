/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:02:40 by ralena            #+#    #+#             */
/*   Updated: 2021/11/29 20:02:41 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_info *info)
{
	mlx_destroy_image(info->mlx, info->img_1);
	mlx_destroy_image(info->mlx, info->img_0);
	mlx_destroy_image(info->mlx, info->img_c);
	mlx_destroy_image(info->mlx, info->img_e);
	mlx_destroy_image(info->mlx, info->img_p);
}

void	clean_map(t_info *info)
{
	int	counter;

	counter = 0;
	while (counter < info->rows)
		free(info->map[counter++]);
}

int	close_game(t_info *info)
{
	clean_map(info), destroy_images(info),
	mlx_clear_window(info->mlx, info->mlx_win),
	mlx_destroy_window(info->mlx, info->mlx_win), exit(0);
	return (0);
}
