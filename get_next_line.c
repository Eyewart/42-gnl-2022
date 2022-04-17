/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hassan <hrifi-la@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:31:48 by Hassan            #+#    #+#             */
/*   Updated: 2022/04/17 17:08:37 by Hassan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	/* BRAINSTORMING
	gnl() will return one line, no matter the BUFFER_SIZE
	read() will return the number of bytes read and will fill in the string 
	"buf"

	ssize_t read(int fd, void *buf, size_t count);
	-D BUFFER_SIZE=xx;

	strdup(return_value of read() + 1)
	strjoin(buf)
	is there any '/n' in the new created str?
	if yes, stores the rest in > static char *rest

	if return_value == 0, it means EOF, gnl returns NULL

	n.b.: if you don't close the file, the cursor reading the file will remain
	at the same place. thus if you call gnl multiple times, it should read the 
	entire file

	malloc & free!!!
	check leaks!!! > valgrind

	cas particulier
	1- fichier vide
	2- fichier avec 1 ligne
	3- BUFFER_SIZE 0, BUFFER_SIZE négatif, fichier qui n'existe pas
	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_SIZE 101

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_strlink(char *s1, char *s2)
{
	char	*str;
	int		t_size;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	t_size = strlen(s1) + strlen(s2) + 1;
	str = malloc(sizeof(*s1) * t_size);
	if (str == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_save (char *save, char *buffer, int i)
{
	if (!save)
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
	save = ft_strlink(save, &buffer[i+1]);
	return (save);
}

char *ft_newline(char **save, char *line)
{
	int j;
	int new_save;

	j = 0;
	while (save[0][j] != '\0')
	{
		if (save[0][j] == '\n')
		{
			save[0][j] = '\0';
			new_save = 1;
		}
		else	
			j++;
	}
	line = ft_strlink(line, *save);
	if (new_save == 1)
		*save = &(save[0][j+1]);
	return (line);
}

void	ft_to_line(char *buffer, char **line, char **save, int i, int *EOL)
{
	if (buffer[i] == '\n')
	{
		buffer[i] = '\0';
		*line = ft_strlink(*line, buffer);
		*EOL = 1;
		*save = ft_save(*save, buffer, i);
	}
}

char	*get_next_line(int fd)
{
	char *line;
	static char *save;
	char *buffer;
	int i;
	int EOL;
	int ret_value;

	EOL = 0;
	if (!(line = malloc(1)) || !(buffer = malloc(BUFFER_SIZE + 1)))
		return (NULL);
	line[0] = '\0';
	if (save)
		line = ft_newline(&save, buffer);
	while ((ret_value = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret_value] = '\0';
		i = 0;
		while (i++ != BUFFER_SIZE && EOL != 1)
			ft_to_line(buffer, &line, &save, i, &EOL);
		if (EOL != 1)
			line = ft_strlink(line, buffer);
		if (EOL == 1)
			break ;
	}
	return (line);
}