/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:11:44 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/04/09 10:27:25 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initial_imgs(t_game *game)
{
	int	a;

	game->exit_c = mlx_xpm_file_to_image(game->mlx, "assets/exit_c.xpm", &a,
			&a);
	game->player = mlx_xpm_file_to_image(game->mlx, "assets/player_f.xpm", &a,
			&a);
	game->wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &a, &a);
	game->exit_o = mlx_xpm_file_to_image(game->mlx, "assets/exit_o.xpm", &a,
			&a);
	game->collect = mlx_xpm_file_to_image(game->mlx, "assets/collect.xpm", &a,
			&a);
	game->empty = mlx_xpm_file_to_image(game->mlx, "assets/empty.xpm", &a, &a);
	game->exit = game->exit_c;
	if (!game->player || !game->wall || !game->empty || !game->collect
		|| !game->exit_c || !game->exit_o)
	{
		ft_printf("Error: Failed to load images\n");
		exit_game(game);
	}
}
