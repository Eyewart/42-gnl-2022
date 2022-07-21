/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrifi-la <hrifi-la@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:31:48 by Hassan            #+#    #+#             */
/*   Updated: 2022/07/21 19:55:10 by hrifi-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;
	char		*buffer;
	int			new_save;

	new_save = 0;
	line = malloc(1);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!line || !buffer)
		return (NULL);
	line[0] = '\0';
	if (save)
		line = ft_newline(&save, line, &new_save, 0);
	if (new_save)
	{
		free (buffer);
		return (line);
	}
	ft_read (&line, &save, &buffer, fd);
	free (buffer);
	system("leaks -q a.out | grep \"leak\"");
	return (line);
}
