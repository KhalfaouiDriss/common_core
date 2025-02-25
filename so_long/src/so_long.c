
#include "../so_long.h"

void check_file(char *file)
{
    int i = 0;
    int fd;

    fd = open(file, O_RDONLY);
    if(fd < 0)
    {
        ft_printf("%s", "error3\n");
        exit(0);
    }
    while(file[i])
    {
        i++;
    }
    if(file[i- 1] != 'r' || file[i - 2] != 'e' || file[i - 3] != 'b' || file[i - 4] != '.')
    {
        ft_printf("%s", "error2\n");
        exit(0);
    }
    close(fd);
    return;
}

char **init_map(char *file, t_game *game)
{
    int fd;
    char **map;
    char *line;
    int i = 0;
    fd = open(file, O_RDONLY);
    line = get_next_line(fd);
    map = (char **)malloc(ft_strlen(line) + 1);
    while(line)
    {
        map[i] = ft_strdup(line);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    map[i] = NULL;
    free(line);
    game->map = map;
}

int main(int ac, char **av)
{
    t_game game;
    char **map;
    if(ac != 2)
    {
        ft_printf("%s", "error1\n");
        return 0;
    }
    check_file(av[1]);
    init_map(av[1], &game);
    check_map();
    int i = 0;
    while (game.map[i])
    {
        ft_printf("%s", game.map[i]);
        i++;
    }
    return 0;
}
