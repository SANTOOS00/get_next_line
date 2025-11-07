
#include "get_next_line.h"

 int main()
 {
	int fd = open("test.txt",'r');
	char *buffer = get_next_line(fd);
	printf("[%s]",buffer);
	free(buffer);
 }