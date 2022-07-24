/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrifi-la <hrifi-la@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:31:48 by Hassan            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/21 17:20:08 by Hassan           ###   ########.fr       */
=======
/*   Updated: 2022/07/23 13:31:58 by hrifi-la         ###   ########.fr       */
>>>>>>> 517f3c78e0989f0c63e1f86072fdc021fa0c9a77
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
<<<<<<< HEAD
#include <unistd.h>
#define BUFFER_SIZE 1
=======
>>>>>>> 517f3c78e0989f0c63e1f86072fdc021fa0c9a77

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s || !s[0])
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save = NULL;
	char		*buffer;
	int			new_save;

	new_save = 0;
	line = NULL;
	//line = malloc(1);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	//line[0] = '\0';
	if (save)
		line = ft_newline(&save, line, &new_save, 0);
	if (new_save)
	{
		free (buffer);
		return (line);
	}
	if (ft_read(&line, &save, &buffer, fd) > 0)
		line = ft_strjoin2(line, "\n");
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
