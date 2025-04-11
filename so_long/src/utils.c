/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:10:22 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/04/07 13:11:14 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	destroy_all_imgs(t_game *game)
{
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->exit_c)
		mlx_destroy_image(game->mlx, game->exit_c);
	if (game->exit_o)
		mlx_destroy_image(game->mlx, game->exit_o);
	if (game->collect)
		mlx_destroy_image(game->mlx, game->collect);
	if (game->empty)
		mlx_destroy_image(game->mlx, game->empty);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**map_dup(char **o_map)
{
	int		i;
	char	**map;

	i = 0;
	while (o_map[i])
		i++;
	map = malloc((i + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (o_map[i])
	{
		map[i] = ft_strdup(o_map[i]);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	flood_fill(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	map[x][y] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}
