/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:10:16 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/04/09 10:46:17 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_cell(t_game *game, char cell, int x, int y)
{
	if (cell == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->empty, x * 64, y
			* 64);
	else if (cell == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall, x * 64, y
			* 64);
	else if (cell == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collect, x * 64, y
			* 64);
	else if (cell == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit, x * 64, y
			* 64);
	else if (cell == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player, x * 64, y
			* 64);
}

void	render_game(t_game *game)
{
	char	**map;
	int		y;
	int		x;

	map = game->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			render_cell(game, map[y][x], x, y);
			x++;
		}
		y++;
	}
}

int	find_move(t_game *game, int keycode, int *dx, int *dy)
{
	int	qu;

	qu = 0;
	*dx = 0;
	*dy = 0;
	if (keycode == 65307)
		exit_game(game);
	if (keycode == 119)
		*dx = -1;
	else if (keycode == 115)
		*dx = 1;
	else if (keycode == 97)
		*dy = -1;
	else if (keycode == 100)
		*dy = 1;
	if (keycode == 97 || keycode == 119 || keycode == 115 || keycode == 100)
		qu = 1;
	return (qu);
}

void	reinit_game(t_game *game, int *new_x, int *new_y)
{
	if (game->map[*new_x][*new_y] == 'C')
		game->collectible_count--;
	if (game->collectible_count == 0)
		game->exit = game->exit_o;
	if (game->is_exit)
		game->map[game->player_x][game->player_y] = 'E';
	else
		game->map[game->player_x][game->player_y] = '0';
	if (game->map[*new_x][*new_y] == 'E')
	{
		if (game->collectible_count == 0)
			exit_game(game);
		game->is_exit = 1;
	}
	else
		game->is_exit = 0;
	game->player_x = *new_x;
	game->player_y = *new_y;
	game->map[*new_x][*new_y] = 'P';
}

int	move_player(int keycode, t_game *game)
{
	int	dx;
	int	dy;
	int	new_x;
	int	new_y;
	int	qu;

	if (keycode > 0)
		qu = find_move(game, keycode, &dx, &dy);
	else
		return (0);
	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (game->map[new_x][new_y] == '1')
		return (0);
	if (qu)
		ft_printf("Move : %d\n", ++game->move_count);
	reinit_game(game, &new_x, &new_y);
	render_game(game);
	return (0);
}
