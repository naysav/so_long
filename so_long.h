/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:02:38 by ralena            #+#    #+#             */
/*   Updated: 2021/11/29 20:13:10 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

# define BUFFER_SIZE 25

# define SUCCESS 0 
# define ERROR 1

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define WIN 100

typedef struct s_info
{
	char	**map;
	int		rows;
	int		columns;
	int		h_p;
	int		w_p;
	int		collectibles;
	int		player;
	int		exit;
	int		moves;	
	void	*mlx;
	void	*mlx_win;
	void	*img_1;
	void	*img_0;
	void	*img_c;
	void	*img_e;
	void	*img_p;
	void	*img_win;
	int		status;
	int		is_moved;
}	t_info;

void	parse_map(char **argv, t_info *game_info);
void	check_map(t_info *info);

void	prepare_images(t_info *info);
int		put_to_window(t_info *info);

void	init_info(t_info *info);
void	clean_map(t_info *info);
void	destroy_images(t_info *info);
int		close_game(t_info *info);

int		key_hook(int key_code, t_info *info);

int		press_w(t_info *info);
int		press_s(t_info *info);
int		press_a(t_info *info);
int		press_d(t_info *info);
#endif