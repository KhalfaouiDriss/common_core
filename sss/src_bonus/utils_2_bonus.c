/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 03:27:17 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/02/16 23:55:12 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
	game->width = 0;
	game->flage = 1;
	game->col_frames = 0;
	game->enemy_frames = 0;
}

void	init_image(t_game *game)
{
	game->wall = NULL;
	game->empty = NULL;
	game->player = NULL;
	game->b_player = NULL;
	game->l_player = NULL;
	game->r_player = NULL;
	game->exit = NULL;
	game->nc_exit = NULL;
	game->collect[0] = NULL;
	game->collect[1] = NULL;
	game->collect[2] = NULL;
	game->collect[3] = NULL;
	game->collect[4] = NULL;
	game->collect[5] = NULL;
	game->enemy[0] = NULL;
	game->enemy[1] = NULL;
	game->enemy[2] = NULL;
	game->enemy[3] = NULL;
}

void	width_map(t_game *game, const char *filename)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		game->map_width++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	find_player_pos(t_game *game)
{
	int (x), (y);
	game->player_x = 0;
	game->player_y = 0;
	x = 0;
	while (x < game->map_height)
	{
		y = 0;
		while (y < game->map_width)
		{
			if (game->map[x][y] == 'P')
			{
				game->player_y = y;
				game->player_x = x;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	size_map(t_game *game)
{
	game->map_height = 0;
	while (game->map[game->map_height])
	{
		game->map_width = 0;
		while (game->map[game->map_height][game->map_width])
			game->map_width++;
		game->map_height++;
	}
}
