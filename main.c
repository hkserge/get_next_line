/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:41:37 by khelegbe          #+#    #+#             */
/*   Updated: 2020/12/20 16:21:49 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	char *line;
	int file;
	int res;
	int i;

	if (argc > 1)
	{
		file = open(argv[1], O_RDONLY);
	}
	else
	{
		file = STDIN_FILENO;
	}
	res = 1;
	line = NULL;
	i = 1;
	while (res > 0)
	{
		res = get_next_line(file, &line);
		if (res != -1)
		{
			printf(res ? "appel n : %d -> %s\n" : "appel n : %d -> %s", i, line);
			free(line);
			i++;
		}
		else
		{
			printf("error -1");
			return (0);
		}
	}
	return (0);
}
