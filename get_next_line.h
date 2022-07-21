/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrifi-la <hrifi-la@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:31:53 by Hassan            #+#    #+#             */
/*   Updated: 2022/07/21 19:55:18 by hrifi-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin2(char *s1, char *s2, int lens1, int lens2);
char	*ft_save(char *save, char *buffer, int i);
char	*ft_newline(char **save, char *line, int *new_save, int j);
void	find_end(char **buffer, char **line, char **save, int *endline);
void	ft_read(char **line, char **save, char **buffer, int fd);

#endif