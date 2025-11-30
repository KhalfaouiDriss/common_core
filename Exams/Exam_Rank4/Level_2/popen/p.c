#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>


int ft_popen(const char *file, char *const argv[], char type)
{
	int fd[2];

	if (!file || !argv || (type != 'w' && type != 'r'))
		return -1;
	pipe(fd);
	if (type == 'r')
	{
		if (fork() == 0)
		{
			dup2(fd[1], 1);
			close(fd[0]);
			close(fd[1]);
			execvp(file, argv);
			exit(-1);
		}
		close(fd[1]);
		return (fd[0]);
	}
	if (type == 'w')
	{
		if (fork() == 0)
		{
			dup2(fd[0], 0);
			close(fd[1]);
			close(fd[0]);
			execvp(file, argv);
			exit(-1);
		}
		close(fd[0]);
		return (fd[1]);
	}
	return (-1);
}


int main(int ac, char **av)
{
    int fd = ft_popen(av[1], &av[1], 'w');
    if (fd == -1)
    {
        perror("ft_popen");
        return 1;
    }

    char buffer[256];
    int n;

    while ((n = read(fd, buffer, sizeof(buffer)-1)) > 0)
    {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(fd);
    return 0;
}
