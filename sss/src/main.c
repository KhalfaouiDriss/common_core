/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:56:05 by sel-abbo          #+#    #+#             */
/*   asdaUpdated: 2025/02/19 18:53:03 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;
	int		i;

	if (ac != 2)
		return (write(2, "Usage: ./so_long <map.ber>\n", 27));
	i = 0;
	while (av[1][i])
		i++;
	if (av[1][i - 1] != 'r' || av[1][i - 2] != 'e' || av[1][i - 3] != 'b'
		|| av[1][i - 4] != '.')
		return (write(2, "Error: Invalid map file\n", 24));
	init_game(&game);
	parse_map(av[1], &game);
	size_map(&game);
	find_player_pos(&game);
	map_valide(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map_width * 32, game.map_height
			* 32, "So Long!");
	loading_textures(&game);
	render_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win,1 7, 0, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
