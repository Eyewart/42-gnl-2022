//main to test get_next_line();

#include "get_next_line.h"
#include <stdio.h>
#include <limits.h>
int     main(void)
{
const char * filename = "test.txt";

  FILE * fd = fopen(filename, "r");
  if (fd) 
  { // succès
    // utilisation du fichier
	while (get_next_line(fd))
		printf("%s", get_next_line(fd));
  } 
  else 
  { // échec
    fprintf(stderr, "Can't read %s\n", filename);
  }
  return 0;
}

