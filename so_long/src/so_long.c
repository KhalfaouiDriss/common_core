#include "../so_long.h"

int	exit_game(t_game *game)
{
	// int	i;

	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
		ft_error(game); 
	}
	return (0);
}


void	so_long(t_game *game)
{
	initial_imgs(game);
	render_game(game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_key_hook(game->win, move_player, game);
	mlx_loop(game->mlx);
}

int	check_map_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || filename[len - 1] != 'r' || filename[len - 2] != 'e'
		|| filename[len - 3] != 'b' || filename[len - 4] != '.')
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;
	// int		i;

	if (ac != 2)
		return (write(2, "Usage: ./so_long <map.ber>\n", 27));
	if (!check_map_file(av[1]))
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
	game.win = mlx_new_window(game.mlx, game.map_width * 64,
		game.map_height * 64, "So Long!");
	if (!game.win)
	{
		ft_printf("Error: Failed to create window\n");
		ft_error(&game);
		return (1);
	}
	so_long(&game);
	ft_error(&game);
	exit_game(&game);
	// for (i = 0; game.map[i]; i++)
	// 	ft_printf("%s\n", game.map[i]);
	// ft_printf("w = %d || h = %d\n", game.map_width, game.map_height);
	return (0);
}