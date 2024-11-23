#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *save;
	char *help = NULL;
	char *buff = NULL;
	char *res = NULL;
	ssize_t i;

	if(fd < 0 || BUFFER_SIZE < 0)
		return NULL;
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if(!buff)
		return NULL;
	i = 1;
	if(i > 0 && !ft_strchr(save, '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		if(!buff)
		{
			free(buff);
			return NULL;
		}
		help = save;
		if(!save)
			save = ft_strdup(buff);
		else
			save = ft_strjoin(save, buff);
		free(help);
		help = NULL;
	}

	if(ft_strchr(save, '\n'))
	{
		res = ft_substr(save, 0, (ft_strchr(save, '\n') - save) + 1);
		help = ft_strdup(ft_strchr(save, '\n') + 1);
		free(save);
		save = help;
	}
	else if(*save && save)
	{
		res = ft_strdup(save);
		free(save);
		save = NULL;
	}
	free(buff);
	return res;
}

int main(void) 
{
	char *line;
	int fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	while(line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}