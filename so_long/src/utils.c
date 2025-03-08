#include "../so_long.h"

void ft_error(t_game *game)
{
    int i;

    i = 0;
    while (game->map[i])
    {
        free(game->map[i]);
        i++;
    }
    free(game->map);
    exit(0);
}

t_count find_player(t_game *game)
{
    t_count count;

    count.i = 0;
    while (game->map[count.i])
    {
        count.j = 0;
        while (game->map[count.i][count.j])
        {
            if (game->map[count.i][count.j] == 'P')
                return count;
            count.j++;
        }
        count.i++;
    }
    return count;
}

char **map_dup(char **o_map)
{
    int i = 0;
    char **map;

    while (o_map[i])
        i++;
    
    map = malloc((i + 1) * sizeof(char *));
    if (!map)
        return NULL;
    
    i = 0;
    while (o_map[i])
    {
        map[i] = ft_strdup(o_map[i]);
        i++;
    }
    map[i] = NULL;
    return (map);
}

void flood_fill(char **map, int x, int y)
{
    if (map[x][y] == '1' || map[x][y] == 'V')
        return;

    map[x][y] = 'V';

    flood_fill(map, x + 1, y);
    flood_fill(map, x - 1, y);
    flood_fill(map, x, y + 1);
    flood_fill(map, x, y - 1);
}