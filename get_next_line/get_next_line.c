/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:09:15 by dkhalfao          #+#    #+#             */
/*   Updated: 2024/11/20 19:12:11 by dkhalfao         ###   ########.fr       */
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
#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stock = NULL;
	char		*buffer = NULL;
    char        *line = NULL;
    char        *tmp = NULL;
	ssize_t		size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
    size = 1;
    while (size > 0 && !ft_strchr(stock, '\n'))
    {
	    size = read(fd, buffer, BUFFER_SIZE);
        if (size > 0)
        {
            buffer[size] = '\0';
            tmp = stock;
            if (!stock)
                stock = ft_strdup(buffer);
            else
                stock = ft_strjoin(stock, buffer);
            free(buffer);
            buffer = NULL;
            free(tmp);
        }
    }

    if (ft_strchr(stock, '\n'))
    {
        line = ft_substr(stock, 0, (ft_strchr(stock, '\n') - stock) + 1);
        tmp = ft_strdup(ft_strchr(stock, '\n') + 1);
        free(stock);
        stock = NULL;
        if (*tmp == '\0')
        {
            free(tmp);
            tmp = NULL;
        }
        else
        {
            stock = tmp;
            tmp = NULL;
        }
    }
    else
    {
        line = ft_strjoin(line, stock);
        free(stock);
        stock = NULL;
    }
    if (size == 0 && !stock) 
    {
        free(stock);
        stock = NULL;
        free(tmp);
        return (NULL);
    }
    return line;
}

int main()
{
    int fd = open("text.txt", O_RDONLY);

    char *line = get_next_line(fd);

    while(line)
    {
        printf("%s", line);
        free(line);  // تأكد من تحرير الذاكرة بعد الاستخدام
        line = get_next_line(fd);
    }
    free(line);  // تأكد من تحرير الذاكرة في نهاية البرنامج
    close(fd);
}

// int main()
// {
//     int fd = open("text.txt", O_RDONLY);

//     char *line = get_next_line(fd);

//     while(line)
//     {
//         printf("%s", line);
//         free(line);
//         line = get_next_line(fd);
//     }
//     free(line);
//     line = NULL;
//     close(fd);
// }
