/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:15:23 by khelegbe          #+#    #+#             */
/*   Updated: 2021/01/04 17:46:24 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_new_line(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char    *ft_get_new_line(char *str)
{
    int     i;
    int     j;
    char    *new_line;

    i = 0;
    j = 0;
    while (str[i] != '\n')
        i++;
    new_line = malloc(sizeof(char) * (i + 1));
    if (!new_line)
        return (0);
    new_line[i] = '\0';
    while (str[j] != '\n')
    {
        new_line[j] = str[j];
        j++;
    }
    return (new_line);
}

char    *ft_get_the_rest(char *str)
{
    int     i;
    char    *rest;

    while (str[i] != '\n')
        i++;
    rest = malloc(sizeof(char) * (ft_strlen(str) - (i + 1)));
        if (!rest)
            return(0);
}
