#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>


int ft_popen(const char *file, char *const argv[], char type)
{
	if (!file || !argv || (type != 'w' && type != 'r'))
    	return -1;

	int fd[2];

	pipe(fd);

	if(type == 'r')
	{
		if(fork() == 0)
		{
			dup2(fd[1], 1);
			close(fd[1]);
			close(fd[0]);
			execvp(file, argv);
			exit(-1);
		}
		close(fd[1]);
		return fd[0];
	}
	if(type == 'w')
	{
		if(fork() == 0)
		{
			dup2(fd[0], 0);
			close(fd[1]);
			close(fd[0]);
			execvp(file, argv);
			exit(-1);
		}
		close(fd[0]);
		return fd[1];
	}
	return -1;
}


int main()
{

	char cmd[] = {"ls"};

	int fp = ft_popen("cat", (char *const[]){"ls", NULL}, 'r');
	char buffer[1000];
	int i = read(fp, buffer, 100);
	buffer[i - 1] = '\0';

	printf("%s\n", buffer);

	return 0;
}
