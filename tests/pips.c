#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


int main(int ac, char **av)
{
    int fd[2];
    pipe(fd);

    int file = open("file", O_RDONLY, 644);
    dup2(file, 0);
    char buff[100];
    int i = read(0, buff, 100);

    buff[i] = '\0';
    printf("%s\n", buff);
}