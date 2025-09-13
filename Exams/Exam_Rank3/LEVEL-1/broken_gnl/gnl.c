#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFFER_SIZE 10000

int ft_strlen(const char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
    
}

char    *ft_strdup(const char *str)
{
    char    *copy;
    int        i;

    copy = (char *)malloc(sizeof(char) * strlen(str) + 1);
    if (copy == NULL)
        return (NULL);
    i = 0;
    while (str[i] != '\0')
    {
        copy[i] = str[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}

char    *ft_substr(const char *str, unsigned int start, size_t n)
{
        size_t  i;
        char    *dest;
        size_t  size;

        if (!str)
                return (NULL);
        size = ft_strlen(str);
        if (start >= size)
                return (ft_strdup(""));
        if (start + n > size)
                n = size - start;
        dest = malloc(n + 1);
        if (!dest)
                return (NULL);
        i = 0;
        while (str[start] && i < n)
        {
                dest[i] = str[start];
                i++;
                start++;
        }
        dest[i] = '\0';
        return (dest);
}

char *gnl(int fd)
{
    static char *buffer = NULL;
    char *line;
    int i;
    int j;
    static int pos = 0;

    if(!buffer)
    {
        buffer = (char *)malloc(BUFFER_SIZE + 1);
        i = read(fd, buffer, BUFFER_SIZE);
        buffer[i] = '\0';
    }
    j = pos;
    while(buffer[pos] != '\n' && buffer[pos])
        pos++;
    if(!buffer[pos + 1])
    {
        free(buffer);
        return NULL;
    }
    pos++;
    // printf(" pos : %d || j : %d  || i = %d\n", pos, j, i);
    line = ft_substr(buffer, j, pos - j);
    return line;
}

int main()
{
    int fd = open("file.txt", O_RDONLY);
    char *line = gnl(fd);
    while (line)
    {
        printf("line : %s", line);
        free(line);
        line = gnl(fd);
    }
}