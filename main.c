
#include "get_next_line.h"

 int main()
 {
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 78dce3a (get_next_linr_1337)
	int fd = open("test.txt",'r');
	char *buffer = get_next_line(fd);
	printf("[%s]",buffer);
	free(buffer);
<<<<<<< HEAD
=======
=======
	int fd = open("get_next_line.c",'r');
	char *buffer;

	buffer = get_next_line(fd);
	while (buffer)
	{
		printf ("%s",buffer);
		buffer = get_next_line(fd);
	}

>>>>>>> 39e5e24 (get_next_line)
>>>>>>> 78dce3a (get_next_linr_1337)
 }