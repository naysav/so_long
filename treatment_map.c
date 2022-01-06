/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:02:47 by ralena            #+#    #+#             */
/*   Updated: 2021/11/29 20:13:56 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(char **argv, t_info *info)
{
	int		fd;
	int		counter;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printf("Error\nFile \"%s\" not opened\n", argv[1]), close(fd), exit(1);
	while (get_next_line(fd) != NULL)
		info->rows++;
	close(fd);
	if (info->rows == 0)
		printf("Error\nFile \"%s\" is empty\n", argv[1]), close(fd), exit(1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printf("Error\nFile \"%s\" not opened\n", argv[1]), close(fd), exit(1);
	counter = 0;
	info->map = (char **)malloc(sizeof(char *) * info->rows);
	while (counter < info->rows)
	{
		info->map[counter] = get_next_line(fd);
		if (info->map[counter][ft_strlen(info->map[counter]) - 1] == '\n')
			info->map[counter] = ft_substr(info->map[counter], 0,
					ft_strlen(info->map[counter]) - 1);
		counter++;
	}
	close(fd);
}

void	treat_character(t_info *info, char character, int h_p, int w_p)
{
	if (character == 'C')
		info->collectibles++;
	if (character == 'P')
	{
		info->h_p = h_p;
		info->w_p = w_p;
		info->player++;
	}
	if (character == 'E')
		info->exit++;
	if (!ft_strchr("01CEP", character))
		printf("Error\nWrong character in map\n"),
		clean_map(info), exit(1);
}

void	check_map(t_info *info)
{
	int	col;
	int	counter;

	counter = 0;
	info->columns = ft_strlen(info->map[counter]);
	while (counter < info->rows)
	{	
		col = 0;
		if (info->columns != (int)ft_strlen(info->map[counter]))
			printf("Error\nWrong size of map\n"),
			clean_map(info), exit(1);
		while (info->map[counter][col])
		{
			if (((counter == 0 || counter + 1 == info->rows)
					&& info->map[counter][col] != '1')
					|| info->map[counter][0] != '1'
					|| info->map[counter][info->columns - 1] != '1')
				printf("Error\nWrong wall in map\n"), clean_map(info), exit(1);
			treat_character(info, info->map[counter][col], counter, col), col++;
		}
		info->columns = ft_strlen(info->map[counter]), counter++;
	}
	if (info->player != 1 || info->exit == 0 || info->collectibles == 0)
		printf("Error\nWrong number of game parameters\n"),
		clean_map(info), exit(1);
}
