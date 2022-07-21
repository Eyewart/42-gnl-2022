/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hassan <hrifi-la@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:31:48 by Hassan            #+#    #+#             */
/*   Updated: 2022/07/17 13:36:28 by Hassan           ###   ########.fr       */
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
	if yes, stores the rest in > static char *rest<

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
#define BUFFER_SIZE 10000

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_strjoin2(char *s1, char *s2)
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
	if (!save || !buffer)
	{
		save = malloc(sizeof(char) * 1);
		save[0] = 0;
		printf("hey\n");			
	}
	else 
	{
		free(save);
		save = malloc(sizeof(char) * 1);
		save[0] = 0;
	}
	save = ft_strjoin2(save, &buffer[i+1]);
	return (save);
}

/*char *ft_add_line (char *line, char **save)
				buffer[i] = '\0';
				line = ft_strjoin2(line, buffer);
				EOL = 1;
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
				save = ft_strjoin2(save, &buffer[i+1]);*/

char *ft_newline(char **save, char *line, int *new_save)
{
	int j;
	int i;

	j = 0;
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
	}	return (line);
}

char	*get_next_line(int fd)
{
	char *line;
	static char *save;
	char *buffer;
	int i;
	int j;
	int EOL = 0;
	int ret_value;
	int new_save = 0;

	if (!(line = malloc(1)) || !(buffer = malloc(BUFFER_SIZE + 1)))
		return (NULL);
	line[0] = '\0';
	if (save)
		line = ft_newline(&save, line, &new_save);
	if (new_save)
	{
		free (buffer);
		return (line);
	}
	while ((ret_value = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret_value] = '\0';
		i = 0;
		while (i != BUFFER_SIZE)
		{
			if (buffer[i] == '\n')
			{
				buffer[i] = '\0';
				line = ft_strjoin2(line, buffer);
				EOL = 1;
				save = ft_save(save, buffer, i);
				break;
			}
			i++;
		}
		if (EOL != 1)
			line = ft_strjoin2(line, buffer);
		if (EOL == 1)
			break ;
	}
	free (buffer); // sinon leaks
	return (line);
}