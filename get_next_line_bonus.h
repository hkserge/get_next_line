/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:15:04 by khelegbe          #+#    #+#             */
/*   Updated: 2021/01/24 15:15:55 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

int						get_next_line(int fd, char **line);
int						ft_is_new_line(char *str);
char					*ft_get_new_line(char *str);
char					*ft_get_the_rest(char *str);
char					*ft_strjoin(char *s1, char const *s2);

#endif
