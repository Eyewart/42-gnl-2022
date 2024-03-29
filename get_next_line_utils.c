/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrifi-la <hrifi-la@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:31:42 by Hassan            #+#    #+#             */
/*   Updated: 2022/07/24 15:27:15 by hrifi-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		lens1;
	int		lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = malloc(sizeof(*s1) * (lens1 + lens2 + 1));
	if (str == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (i < lens1)
	{
		str[i] = s1[i];
		i++;
	}
	free(s1);
	while (j < lens2)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_save(char *save, char *buffer, int i)
{
	if (!save || !buffer)
	{
		save = malloc(sizeof(char) * 1);
		save[0] = 0;
	}
	else
	{
		free(save);
		save = malloc(sizeof(char) * 1);
		save[0] = 0;
	}
	save = ft_strjoin2(save, &buffer[i + 1]);
	return (save);
}

char	*ft_newline(char **save, char *line, int *new_save, int j)
{
	int	i;

	i = 0;
	while (save[0][j] != '\0')
	{
		if (save[0][j] == '\n')
		{
			save[0][j] = '\0';
			*new_save = 1;
		}
		else
			j++;
	}
	if (save[0][0] != '\0')
		line = ft_strjoin2(line, *save);
	if (*new_save == 1)
	{
		j++;
		while (save[0][j] != 0)
			save[0][i++] = save[0][j++];
		while (save[0][i] != 0)
			save[0][i++] = 0;
	}
	return (line);
}

void	ft_findend(char **buffer, char **line, char **save, int *endline)
{
	int	i;

	i = 0;
	while (i != BUFFER_SIZE)
	{
		if (buffer[0][i] == '\n')
		{
			buffer[0][i] = '\0';
			*line = ft_strjoin2(*line, *buffer);
			*endline = 1;
			*save = ft_save(*save, *buffer, i);
			break ;
		}
		i++;
	}
}

int	ft_read(char **line, char **save, char **buffer, int fd)
{
	int	ret_value;
	int	endline;

	endline = 0;
	ret_value = read(fd, *buffer, BUFFER_SIZE);
	while (ret_value > 0)
	{
		buffer[0][ret_value] = '\0';
		ft_findend(buffer, line, save, &endline);
		if (endline != 1)
			*line = ft_strjoin2(*line, *buffer);
		else
			break ;
		ret_value = read(fd, *buffer, BUFFER_SIZE);
	}
	return (ret_value);
}
