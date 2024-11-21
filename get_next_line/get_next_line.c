/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:25:22 by dkhalfao          #+#    #+#             */
/*   Updated: 2024/11/21 12:25:26 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*buffer;
	char		*tmp;
	char		*line;
	int			size;

	size = 1;
	stock = NULL;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	tmp = NULL;
	line = NULL;
	if (!buffer)
		return (NULL);
    if(size > 0 && !ft_strchr(stock, '\n'))
    {
        size = read(fd, buffer, BUFFER_SIZE);
        if(!buffer)
        {
            free(buffer)
            buffer = NULL; 
        }
        buffer[size] = '\0';
        if()
    }
}

int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	char *line;
	line = get_next_line(fd);
	while (line)
	{
		prinf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}