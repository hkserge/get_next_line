/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:59:38 by khelegbe          #+#    #+#             */
/*   Updated: 2021/01/24 15:00:48 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_file(int fd, char **remaining, int *bytes_readed, char **buff)
{
	char			*copy;

	if ((*bytes_readed = read(fd, *buff, BUFFER_SIZE)) == -1)
	{
		free(*buff);
		return ;
	}
	(*buff)[*bytes_readed] = '\0';
	copy = *remaining;
	*remaining = ft_strjoin(*remaining, *buff);
	free(copy);
}

int		get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*remaining;
	int				bytes_readed;

	bytes_readed = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	while (!ft_is_new_line(remaining) && bytes_readed != 0)
	{
		read_file(fd, &remaining, &bytes_readed, &buff);
		if (bytes_readed == -1)
			return (-1);
	}
	free(buff);
	*line = ft_get_new_line(remaining);
	remaining = ft_get_the_rest(remaining);
	if (bytes_readed == 0)
		return (0);
	return (1);
}
