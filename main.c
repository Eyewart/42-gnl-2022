//main to test get_next_line();

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int     main(void)
{


	int	fd =  open("41_no_nl", O_RDONLY);
	char	*line;
	int	i = 0;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
		i++;
	}

//printf("\n%p\n", get_next_line(fd));


//const char *filename = "test.txt";
//int fd;
//  fd = 0;
//  fd = open(filename, O_RDONLY);
//  char *result;
//  if (fd) 
//  { // succès
//    // utilisation du fichier
//      result = get_next_line(fd);
//      printf("line1: %s\n", result);
//      free (result);
//      result = get_next_line(fd);
//      printf("line2: %s\n", result);
//      free (result);
//      result = get_next_line(fd);
//      printf("line3: %s\n", result);
//      free (result);
//      result = get_next_line(fd);
//      printf("line4: %s\n", result);
//      free (result);
//      //printf("line: %s\n", get_next_line(fd));
//      //printf("line: %s\n", get_next_line(fd));

//  } 
//  else 
//  { // échec
//    printf("file didn't open");
//  }
//  return 0;





}
