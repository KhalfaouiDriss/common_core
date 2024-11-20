/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:09:15 by dkhalfao          #+#    #+#             */
/*   Updated: 2024/11/19 15:09:18 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// char *_fill_line_buffer(int fd, char *left_c, char *buffer)
// {

// }

// char *_set_line(char *line_buffer)
// {

// }
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*buffer;
	ssize_t		size;
    int i = BUFFER_SIZE;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
    while (buffer[i] != '\n')
    {
	    size += read(fd, buffer, BUFFER_SIZE);
        stock = ft_strjoin(stock, buffer);
        i++;
    }
    free(buffer);
    // if (size == -1 || size == 0)
	// 	return (NULL);
    return stock;
}


int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
    char    *bfr = get_next_line(fd);
    printf("%s", bfr);
}