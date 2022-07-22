/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrifi-la <hrifi-la@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:31:48 by Hassan            #+#    #+#             */
/*   Updated: 2022/07/22 19:40:27 by hrifi-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save = NULL;
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
	if (ft_read(&line, &save, &buffer, fd) > 0)
		line = ft_strjoin2(line, "\n", 0, 0);
	else
	{
		free(save);
		save = NULL;
		if (strlen(line) == 0)
		{
			free(line);
			line = NULL;
		}
	}
	free (buffer);
	return (line);
}
