/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hassan <hrifi-la@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:31:48 by Hassan            #+#    #+#             */
/*   Updated: 2022/04/04 18:57:48 by Hassan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
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

	n.b.: if you don't close the file, the cursos reading the file will remain
	at the same place. thus if you call gnl multiple times, it should read the 
	entire file
	*/
}
