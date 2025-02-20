/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:36:07 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/02/18 18:48:07 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_rectangular(char **map)
{
	int (width), (i);
	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	i = 0;
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != width)
			return (0);
		i++;
	}
	return (1);
}

int	is_walls(char **map)
{
	int (i), (width), (height);
	width = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_elements(char **map, t_game *game)
{
	int (i), (j), (player), (exit);
	player = 0;
	exit = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player++;
			else if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] == 'C')
				game->collectible_count++;
			j++;
		}
		i++;
	}
	return (player == 1 && exit == 1 && game->collectible_count >= 1);
}

int	is_path_valid(t_game game)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = duplicate_map(game);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, game.player_x, game.player_y);
	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j] != '\0')
		{
			if (map_copy[i][j] == 'C' || map_copy[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	free_map(map_copy);
	return (1);
}

void	map_valide(t_game *game)
{
	int (x), (y);
	y = 0;
	while (y < game->map_height - 1)
	{
		x = 0;
		while (x < game->map_width - 1)
		{
			if (game->map[y][x] != 'P' && game->map[y][x] != 'C'
				&& game->map[y][x] != 'E' && game->map[y][x] != '1'
				&& game->map[y][x] != '0')
				(write(2, "Error: Map invalide (element X)\n", 32),
					exit_game(game, 2));
			x++;
		}
		y++;
	}
	if (!is_rectangular(game->map))
		(write(2, "Error: Map invalide (rectangular)\n", 34), exit_game(game,
				2));
	if (!is_walls(game->map))
		(write(2, "Error: Map invalide (walls)\n", 28), exit_game(game, 2));
	if (!is_elements(game->map, game))
		(write(2, "Error: Map invalide (elements)\n", 31), exit_game(game, 2));
	if (!is_path_valid(*game))
		(write(2, "Error: Map invalide (path)\n", 27), exit_game(game, 2));
}
