/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:15:23 by khelegbe          #+#    #+#             */
/*   Updated: 2021/01/17 01:40:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

char	*ft_get_new_line(char *str)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	new_line = malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (0);
	new_line[i] = '\0';
	while (str[j] != '\n' && str[j] != '\0')
	{
		new_line[j] = str[j];
		j++;
	}
	return (new_line);
}

char	*ft_get_the_rest(char *str)
{
	size_t			i;
	size_t			j;
	char			*rest;

	i = 0;
	j = 0;
	rest = NULL;
	if (*str == '\0')
	{
		free(str);
		return (0);
	}
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] != '\0')
		rest = malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!rest)
		return (0);
	i++;
	if (str[i] == '\0')
	{
		free(rest);
		free(str);
		return (0);
	}
	while (str[i])
		rest[j++] = str[i++];
	rest[j] = '\0';
	free(str);
	return (rest);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char		*str;
	size_t		len;
	int			i;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!s1 && !s2)
		return (0);
	str = malloc(sizeof(char) * len);
	if (!str)
		return (0);
	while (s1 && *s1)
		str[i++] = *s1++;
	while (s2 && *s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
