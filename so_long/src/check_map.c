#include "../so_long.h"

void check_walls(t_game *game)
{
    t_count count;

    (count.i = 0, count.j = 0, count.h = 0);
    while (game->map[0][count.j])
    {
        if (game->map[0][count.j] != '1')
            ft_printf("Invalid map 1\n"),ft_error(game);
        count.j++;
    }
    count.i = 1;
    while (count.i < game->map_height - 1)
    {
        if (game->map[count.i][0] != '1' || game->map[count.i][game->map_width - 1] != '1')
            ft_printf("Invalid map 2\n"),ft_error(game);
        count.i++;
    }
    count.h = 0;
    while (game->map[game->map_height - 1][count.h])
    {
        if (game->map[game->map_height - 1][count.h] != '1')
            ft_printf("Invalid map 3\n"), ft_error(game);
        count.h++;
    }
}

void check_elements(t_game *game)
{
    char **map = game->map;
    t_count count;
    int width;

    (count.i = 0, count.j = 0, count.h = 0, width = ft_strlen(map[0]));
    while (map[count.i])
    {
        count.j = 0;
        while (map[count.i][count.j])
        {
            if (!ft_strchr("01PCE", map[count.i][count.j]))
                ft_printf("Invalid map 4\n"), ft_error(game);
            if(map[count.i][count.j] == 'C')
                game->collectible_count++;
            count.j++;
        }
        if (count.j != width)
            ft_printf("Invalid map 5\n"), ft_error(game);
        count.i++;
    }
    game->map_height = count.i;
    game->map_width = width;
}

void find_all_element(t_game *game)
{
    char **map;
    t_count count;
    int x;
    
    map = game->map;
    (count.i = 0, count.j = 0, count.h = 0, x = 0);
    while (map[x])
    {
        count.w = 0;
        while (map[x][count.w])
        {
            if (map[x][count.w] == 'P')
                count.i++;
            if (map[x][count.w] == 'C')
                count.j++;
            if (map[x][count.w] == 'E')
                count.h++;
            count.w++;
        }
        x++;
    }
    if(count.i != 1 || count.h != 1 || count.j < 1)
        ft_printf("Invalid map 6\n"), ft_error(game);
    game->collectible_count = count.j;
}

void check_coins_place(t_game *game, int x, int y)
{
    char **map;
    int (i), (j);

    map = map_dup(game->map);
    if (!map)
        ft_printf("Invalid map\n"), ft_error(game);
    flood_fill(map, x, y);
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'C' || map[i][j] == 'E') 
                ft_printf("Invalid map 7\n"), ft_error(game);
            j++;
        }
        i++;
    }
    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

void check_map(t_game *game)
{
    t_count player_index;
    check_elements(game);
    check_walls(game);
    find_all_element(game);
    player_index = find_player(game);
    game->player_x = player_index.i;
    game->player_y = player_index.j;
    check_coins_place(game, player_index.i, player_index.j);
}