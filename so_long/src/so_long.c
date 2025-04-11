/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:10:10 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/04/09 11:00:22 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_count(t_count *count)
{
	count->i = 0;
	count->j = 0;
	count->h = 0;
	count->w = 0;
}

int	exit_game(t_game *game)
{
	if (game->map)
		ft_error(game);
	if (game->mlx)
		destroy_all_imgs(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	exit(0);
}

void	so_long(t_game *game)
{
	initial_imgs(game);
	render_game(game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 2, 1, move_player, game);
	mlx_loop(game->mlx);
}

int	check_map_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5 || filename[len - 1] != 'r' || filename[len - 2] != 'e'
		|| filename[len - 3] != 'b' || filename[len - 4] != '.')
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

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
		(ft_printf("Error: Failed to initialize MLX\n"), exit_game(&game));
		return (1);
	}
	game.win = mlx_new_window(game.mlx, game.map_width * 64, game.map_height
			* 64, "So Long!");
	if (!game.win)
	{
		ft_printf("Error: Failed to create window\n");
		exit_game(&game);
		return (1);
	}
	so_long(&game);
	return (0);
}
