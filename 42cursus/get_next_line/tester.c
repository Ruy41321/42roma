#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Errore nell'apertura del file");
        return 1;
    }
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}
