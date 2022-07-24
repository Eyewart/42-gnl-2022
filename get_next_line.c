/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrifi-la <hrifi-la@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:31:48 by Hassan            #+#    #+#             */
/*   Updated: 2022/07/24 15:53:57 by hrifi-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_free_all(char **save, char **line)
{
	free(*save);
	*save = NULL;
	if (ft_strlen(*line) == 0)
	{
		free(*line);
		*line = NULL;
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save = NULL;
	char		*buffer;
	int			new_save;

	new_save = 0;
	line = NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (save)
		line = ft_newline(&save, line, &new_save, 0);
	if (new_save)
	{
		line = ft_strjoin2(line, "\n");
		free (buffer);
		return (line);
	}
	if (ft_read(&line, &save, &buffer, fd) > 0)
		line = ft_strjoin2(line, "\n");
	else
		ft_free_all(&save, &line);
	free (buffer);
	return (line);
}
