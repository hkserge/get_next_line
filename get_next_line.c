/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:59:38 by khelegbe          #+#    #+#             */
/*   Updated: 2020/12/29 17:12:13 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == src || !n)
		return (dest);
	i = 0;
	if (dest > src)
	{
		while (n > 0)
		{
			((char*)dest)[n - 1] = ((char*)src)[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			((char*)dest)[i] = ((char*)src)[i];
			i++;
		}
	}
	return (dest);
}

int		get_next_line(int fd, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	char	new_line[100];
	int		bytes_readed;
	unsigned int i;

	bytes_readed = read(fd, buff, BUFFER_SIZE);
	buff[bytes_readed] = '\0';
	printf("%s\n", buff);
	i = 0;
	while (buff[i] != '\n')
		i++;
	ft_memmove(new_line, buff, i);
	new_line[i] = '\0';
	printf("%s\n", new_line);
	(void)fd;
	(void)*line;
	return (0);
}
