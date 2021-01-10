/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:59:38 by khelegbe          #+#    #+#             */
/*   Updated: 2021/01/10 23:30:37 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char			*buff;
	int				bytes_readed;
	static char		*remaining;
	char			*copy;

	bytes_readed = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	while (!ft_is_new_line(remaining) && bytes_readed != 0)
	{
		if ((bytes_readed = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[bytes_readed] = '\0';
		copy = remaining;
		remaining = ft_strjoin(remaining, buff);
		free(copy);
	}
	free(buff);
	*line = ft_get_new_line(remaining);
	remaining = ft_get_the_rest(remaining);
	if (bytes_readed == 0)
		return (0);
	return (1);
}
