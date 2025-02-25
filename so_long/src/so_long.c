
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

void init_map(char *file, t_game *game)
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
        if(map[i][ft_strlen(map[i]) - 1] == '\n')
            map[i][ft_strlen(map[i]) - 1] = '\0';
        free(line);
        line = get_next_line(fd);
        i++;
    }
    game->heigth = i - 1;
    game->width = ft_strlen(game->map[i]);
    map[i] = NULL;
    free(line);
    game->map = map;
}

void check_map(t_game *game)
{
    int i = 0;
    int len = ft_strlen(game->map[0]);

    while (game->map[i])
    {
        if(len != ft_strlen(game->map[i]))
        {
            ft_printf("map not valaid");
            free(game);
            exit(0);
        }
        i++;
    }
}

int main(int ac, char **av)
{
    t_game *game;
    char **map;
    if(ac != 2)
    {
        ft_printf("%s", "./so_long <map.ber>\n");
        return 0;
    }
    game = (t_game *)malloc(sizeof(t_game));
    check_file(av[1]);
    init_map(av[1], game);
    check_map(game);
    int i = 0;
    while (game->map[i])
    {
        ft_printf("%s\n", game->map[1]);
        i++;
    }
    return 0;
}
