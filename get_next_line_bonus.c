/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:59:38 by khelegbe          #+#    #+#             */
/*   Updated: 2021/01/17 03:21:58 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void		read_file(int fd, char **rem, int *bytes_readed, char **buff)
{
	char			*copy;

	if ((*bytes_readed = read(fd, *buff, BUFFER_SIZE)) == -1)
	{
		free(*buff);
		return ;
	}
	(*buff)[*bytes_readed] = '\0';
	copy = *rem;
	*rem = ft_strjoin(*rem, *buff);
	free(copy);
}

static void		ft_alloc_rem(t_rem **rem, char **buff)
{
	if (!*rem)
	{
		*rem = malloc(sizeof(t_rem));
		(*rem)->str = malloc(sizeof(char));
		(*rem)->str[0] = '\0';
	}
	*buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
}

int				get_next_line(int fd, char **line)
{
	char			*buff;
	static t_rem	*rem[1024];
	int				bytes_readed;

	bytes_readed = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	ft_alloc_rem(&rem[fd], &buff);
	if (!buff || !rem[fd])
		return (-1);
	while (!ft_is_new_line(rem[fd]->str) && bytes_readed != 0)
	{
		read_file(fd, &rem[fd]->str, &bytes_readed, &buff);
		if (bytes_readed == -1)
			return (-1);
	}
	free(buff);
	*line = ft_get_new_line(rem[fd]->str);
	rem[fd]->str = ft_get_the_rest(rem[fd]->str);
	if (bytes_readed == 0)
	{
		free(rem[fd]->str);
		return (0);
	}
	return (1);
}
