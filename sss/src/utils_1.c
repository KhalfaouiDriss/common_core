/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:00:56 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/03/12 09:49:50 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_fill(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'X')
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
		clean_screen(game);
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
	if (game->collect)
		mlx_destroy_image(game->mlx, game->collect);
}

void	you_win(void)
{
	ft_printf("-----------------------------------------------\n");
	ft_printf("|    🎉🎉🎉  Congratulations!!!!!  🎉🎉🎉     |\n");
	ft_printf("|    You found all collectibles and exit.     |\n");
	ft_printf("|        ✓✓✓✓✓✓✓✓ You won! ✓✓✓✓✓✓✓✓           |\n");
	ft_printf("-----------------------------------------------\n");
}
