/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralena <ralena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:02:10 by ralena            #+#    #+#             */
/*   Updated: 2021/11/29 20:02:13 by ralena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	prepare_memory_we_keep(int buffer_len, int ret_len, char **buffer)
{
	char	*memory;
	int		memory_len;

	memory = (char *)malloc(sizeof(char) * (buffer_len - ret_len + 1));
	if (!memory)
		return ;
	memory_len = buffer_len - ret_len;
	memory[memory_len--] = '\0';
	while (memory_len >= 0)
	{
		memory[memory_len] = (*buffer)[memory_len + ret_len];
		--memory_len;
	}
	free(*buffer);
	*buffer = memory;
}

char	*mal_buffer_and_read(const int fd, char *buffer)
{	
	int	i;

	i = 0;
	buffer = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (i < BUFF_SIZE)
		buffer[i++] = '\0';
	if (read(fd, buffer, BUFF_SIZE) < 0)
		return (NULL);
	buffer[BUFF_SIZE] = '\0';
	return (buffer);
}

int	check_for_next_line(char *buffer)
{
	int	next_line;

	next_line = 0;
	while (buffer[next_line] != '\0')
	{
		if (buffer[next_line] == '\n')
			return (next_line);
		++next_line;
	}
	return (-1);
}

char	*prepare_return(char **buffer, int next_line)
{
	char	*ret;
	int		ret_len;
	int		buffer_len;

	ret = (char *)malloc(sizeof(char) * (next_line + 2));
	if (!ret)
		return (NULL);
	ret_len = 0;
	while (ret_len < next_line + 1)
	{
		ret[ret_len] = (*buffer)[ret_len];
		ret_len++;
	}
	ret[ret_len] = '\0';
	buffer_len = ret_len;
	while ((*buffer)[buffer_len] != '\0')
		++buffer_len;
	prepare_memory_we_keep(buffer_len, ret_len, buffer);
	return (ret);
}
