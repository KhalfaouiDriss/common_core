/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:56:05 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/02/16 23:45:15 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (write(2, "Usage: ./so_long <map.ber>\n", 27));
	if (!check_extension(av))
		return (write(2, "Error: Invalid map extension.\n", 30));
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
	mlx_loop_hook(game.mlx, collect_animation, &game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
