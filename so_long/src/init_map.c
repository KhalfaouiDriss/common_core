#include "../so_long.h"

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->move_count = 0;
	game->collectible_count = 0;
	game->new_x = 0;
	game->new_y = 0;
	game->height = 0;
	game->flage = 0;
    game->is_exit = 0;
}

void 
height_map(char *file, t_game *game)
{
    char *line;
    int fd;

    fd = open(file, O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        game->map_height++;
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
}

void init_map(char *file, t_game *game)
{
    char *line;
    int i;
    int fd;

    i = 0;
    fd = open(file, O_RDONLY);
    if(fd < 0)
    {
        ft_putstr_fd("can't open the file", 2);
        exit(0);
    }
    height_map(file, game);
    game->map = malloc(sizeof(char *) * (game->map_height + 1));
    if(!game->map)
        ft_error(game);
    line = get_next_line(fd);
    while (line)
    {
        game->map[i] = ft_strdup(line);
        if(game->map[i][ft_strlen(line) - 1] == '\n')
            game->map[i][ft_strlen(line) - 1] = '\0';
        free(line);
        line = get_next_line(fd);
        i++;
    }
    // free(line);
    game->map[i] = NULL;
    close(fd);
}