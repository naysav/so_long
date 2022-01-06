/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:02:35 by ralena            #+#    #+#             */
/*   Updated: 2021/11/29 20:15:17 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_info(t_info *info)
{
	info->map = NULL;
	info->rows = 0;
	info->columns = 0;
	info->h_p = 0;
	info->w_p = 0;
	info->collectibles = 0;
	info->player = 0;
	info->exit = 0;
	info->moves = 0;
	prepare_images(info);
	info->status = 0;
	info->is_moved = 0;
}

int	key_hook(int key_code, t_info *info)
{
	if (key_code == ESC)
		close_game(info);
	if (key_code == W)
		press_w(info);
	if (key_code == A)
		press_a(info);
	if (key_code == S)
		press_s(info);
	if (key_code == D)
		press_d(info);
	if (info->is_moved && (key_code == W || key_code == A || key_code == S || \
		key_code == D) && !info->status)
		printf("Moves: %d\n", info->moves);
	info->is_moved = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;
	int		len;

	if (argc != 2)
		printf("Error\nWrong number of arguments\n"), exit(1);
	len = ft_strlen(argv[1]);
	if (argv[1][len - 1] != 'r' || argv[1][len - 2] != 'e'
		|| argv[1][len - 3] != 'b' || argv[1][len - 4] != '.')
		printf("Error\nWrong extention of file\n"), exit(1);
	init_info(&info);
	parse_map(argv, &info);
	check_map(&info);
	info.mlx = mlx_init();
	info.mlx_win = mlx_new_window(info.mlx, info.columns * 32,
			info.rows * 32, "so_long");
	printf("Moves: %d\n", info.moves);
	mlx_hook(info.mlx_win, 2, 0, key_hook, &info);
	mlx_hook(info.mlx_win, 17, 0, close_game, &info);
	mlx_loop_hook(info.mlx, put_to_window, &info);
	mlx_loop(info.mlx);
	return (0);
}
