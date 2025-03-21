#include "../so_long.h"

void initial_imgs(t_game *game)
{
    int a = 32;

    game->f_player = mlx_xpm_file_to_image(game->mlx, "assets/player_f.xpm", &a, &a);
    game->b_player = mlx_xpm_file_to_image(game->mlx, "assets/player_b.xpm", &a, &a);
    game->l_player = mlx_xpm_file_to_image(game->mlx, "assets/player_l.xpm", &a, &a);
    game->r_player = mlx_xpm_file_to_image(game->mlx, "assets/player_r.xpm", &a, &a);
    game->wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &a, &a);
    game->exit_c = mlx_xpm_file_to_image(game->mlx, "assets/exit_c.xpm", &a, &a);
    game->exit_o = mlx_xpm_file_to_image(game->mlx, "assets/exit_o.xpm", &a, &a);
    game->collect = mlx_xpm_file_to_image(game->mlx, "assets/collect.xpm", &a, &a);
    game->empty = mlx_xpm_file_to_image(game->mlx, "assets/empty.xpm", &a, &a);

    if (!game->f_player || !game->b_player || !game->l_player || !game->r_player ||
        !game->wall || !game->empty || !game->collect || !game->exit_c || !game->exit_o)
    {
        ft_printf("Error: Failed to load images\n");
        ft_error(game);
    }
}

void render_game(t_game *game)
{
    char **map = game->map;
    int y, x;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->empty, x * 64, y * 64);
            else if (map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->wall, x * 64, y * 64);
            else if (map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->collect, x * 64, y * 64);
            else if (map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->exit_c, x * 64, y * 64);
            else if (map[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->f_player, x * 64, y * 64);
            x++;
        }
        y++;
    }
}

int find_move(t_game *game,int keycode, int *dx, int *dy)
{
    int Q;

    Q = 0;
    (*dx = 0, *dy = 0);
    if (keycode == 65307)
        ft_error(game);
    if (keycode == 119) // W
        (*dx = -1, Q = 1);
    else if (keycode == 115) // S
        (*dx = 1, Q = 1);
    else if (keycode == 97) // A
        (*dy = -1, Q =1);
    else if (keycode == 100) // D
        (*dy = 1, Q = 1);
    return Q;
}

void reinit_game(t_game *game, int *new_x, int *new_y)
{
    if (game->map[*new_x][*new_y] == 'C')
        game->collectible_count--;
    if (game->collectible_count == 0)
        game->exit_c = game->exit_o; 
    if (game->is_exit)
        game->map[game->player_x][game->player_y] = 'E';
    else
        game->map[game->player_x][game->player_y] = '0';
    if (game->map[*new_x][*new_y] == 'E')
    {
        if(game->collectible_count == 0)
            ft_error(game);
        game->is_exit = 1;
    }
    else
        game->is_exit = 0;
    (game->player_x = *new_x, game->player_y = *new_y);
    game->map[*new_x][*new_y] = 'P';
}

int move_player(int keycode, t_game *game)
{
    int (dx), (dy), (new_x), (new_y), (Q);

    if(keycode > 0)
        Q = find_move(game, keycode, &dx, &dy);
    else   
        return (0);
    (new_x = game->player_x + dx, new_y = game->player_y + dy);
    if (game->map[new_x][new_y] == '1')
        return (0); 
    if(Q)
        ft_printf("Move : %d\n", ++game->move_count);
    reinit_game(game, &new_x, &new_y);
    render_game(game);
    return (0);
}

int	exit_game(t_game *game)
{
	// game->map = NULL;
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
    ft_error(game);
	return (0);
}

void so_long(t_game *game)
{
    initial_imgs(game);
    render_game(game);
    mlx_hook(game->win, 17, 0, exit_game, game);
    mlx_key_hook(game->win, move_player, game);
    mlx_loop(game->mlx);
}

int main(int ac, char **av)
{
    t_game game;
    int i;

    if (ac != 2)
        return (write(2, "Usage: ./so_long <map.ber>\n", 27));

    if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])) || av[1][0] == '.')
        return (write(2, "Error: Invalid map file\n", 24));

    init_game(&game);
    init_map(av[1], &game);
    check_map(&game);
    
    game.mlx = mlx_init();
    if (!game.mlx)
    {
        ft_printf("Error: Failed to initialize MLX\n");
        ft_error(&game);
        return (1);
    }
    
    game.win = mlx_new_window(game.mlx, game.map_width * 64, game.map_height * 64, "So Long!");
    if (!game.win)
    {
        ft_printf("Error: Failed to create window\n");
        ft_error(&game);
        return (1);
    }

    so_long(&game);

    for (i = 0; game.map[i]; i++)
        ft_printf("%s\n", game.map[i]);

    ft_printf("w = %d || h = %d\n", game.map_width, game.map_height);

    return (0);
}
