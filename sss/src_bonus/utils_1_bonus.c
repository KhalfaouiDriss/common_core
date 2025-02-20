/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:00:56 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/02/17 03:30:33 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	flood_fill(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'X' || map[x][y] == 'D')
		return ;
	map[x][y] = 'X';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

char	**duplicate_map(t_game game)
{
	int		i;
	char	**copy;

	i = 0;
	copy = malloc(sizeof(char *) * (game.map_width + 1));
	if (!copy)
		return (NULL);
	while (game.map[i])
	{
		copy[i] = ft_strdup(game.map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

int	exit_game(t_game *game, int flag)
{
	free_map(game->map);
	game->map = NULL;
	if (flag != 2)
	{
		mlx_clear_window(game->mlx, game->win);
		clean_screen(game);
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	exit(0);
	return (0);
}

void	clean_screen(t_game *game)
{
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->empty)
		mlx_destroy_image(game->mlx, game->empty);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->b_player)
		mlx_destroy_image(game->mlx, game->b_player);
	if (game->l_player)
		mlx_destroy_image(game->mlx, game->l_player);
	if (game->r_player)
		mlx_destroy_image(game->mlx, game->r_player);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->nc_exit)
		mlx_destroy_image(game->mlx, game->nc_exit);
	clean_screen_helpre(game);
}
