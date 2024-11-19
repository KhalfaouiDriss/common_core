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

char    *get_next_line(int fd)
{
    static char *stock;
    char    *buffer;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    buffer = (char *)malloc(BUFFER_SIZE + 1);
    if(!buffer)
        return (NULL);
    ssize_t size = read(fd, buffer, BUFFER_SIZE);
    if (size == -1 || size == 0)
        return (NULL);
    if(!ft_strchr(buffer, '/n'))
    {
        stock = ft_strjoin(stock, buffer);
    }
    else
    {
        ft_strlcat(stock, buffer, ft_strchr(buffer, '/n') - &buffer);
    }
    


}

# include <fcntl.h>
# include <limits.h>

int main()
{
    int fd = open("text.txt", O_RDONLY);

}