#include "../so_long.h"

void initial_imgs(t_game *game)
{
    game->f_player = mlx_xpm_file_to_image(game->mlx, "../assets/player_f.xpm", 32, 32);
    game->b_player = mlx_xpm_file_to_image(game->mlx, "../assets/player_b.xpm", 32, 32);
    game->l_player = mlx_xpm_file_to_image(game->mlx, "../assets/player_l.xpm", 32, 32);
    game->r_player = mlx_xpm_file_to_image(game->mlx, "../assets/player_r.xpm", 32, 32);
    game->wall = mlx_xpm_file_to_image(game->mlx, "../assets/wall.xpm", 32, 32);
    game->exit_c = mlx_xpm_file_to_image(game->mlx, "../assets/exit_c.xpm", 32, 32);
    game->exit_o = mlx_xpm_file_to_image(game->mlx, "../assets/exit_o.xpm", 32, 32);
    game->collect = mlx_xpm_file_to_image(game->mlx, "../assets/collect.xpm", 32, 32);
    game->empty = mlx_xpm_file_to_image(game->mlx, "../assets/empty.xpm", 32, 32);

    if(!game->f_player || !game->b_player || !game->l_player || !game->r_player || !game->wall || !game->empty
        || !game->collect || !game->exit_c || !game->exit_o)
        (ft_printf("error\n"), ft_error(game));
}

void so_long(t_game *game)
{
    initial_imgs(game);
    
}

int main(int ac, char **av)
{
    t_game game;
    int i = 0;

    if (ac != 2)
        return (write(2, "Usage: ./so_long <map.ber>\n", 27));

    if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])) || av[1][0] == '.')
        return (write(2, "Error: Invalid map file\n", 24));

    init_game(&game);
    init_map(av[1], &game);
    check_map(&game);
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, game.map_width * 32, game.map_height* 32, "So Long!");
    so_long(&game);

    i = 0;
    while (game.map[i])
    {
        ft_printf("%s\n", game.map[i]);
        i++;
    }

    ft_printf("w = %d || H = %d\n", game.map_width, game.map_height);
    ft_error(&game);
}
