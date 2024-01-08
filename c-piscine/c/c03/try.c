#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv)
{
    char *ptr;

    ptr = ft_strstr(argv[1], argv[2]);
    printf("%s\n", ptr);
    return 1;
}