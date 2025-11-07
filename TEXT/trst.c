
#include "get_next_line.h"
int main()
{
	static char buffer[100];
	int fd = open("test.txt",O_RDONLY);

	char *buffer = get_next_line(fd);
	printf (" ==> %s",buffer);
	free(buffer);

}