/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:49:09 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/02/19 18:55:11 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	mov_up(t_game *game)
{
	game->flage = 2;
	if (game->map[game->player_x - 1][game->player_y] == '1')
		return ;
	if (game->map[game->player_x - 1][game->player_y] == 'E')
	{
		if (game->collectible_count == 0)
			(you_win(), exit_game(game, 1));
		game->new_x = game->player_x - 1;
		game->new_y = game->player_y;
	}
	if (game->map[game->new_x][game->new_y] == 'P')
		game->map[game->player_x][game->player_y] = 'E';
	else
		game->map[game->player_x][game->player_y] = '0';
	game->player_x--;
	if (game->map[game->player_x][game->player_y] == 'C')
		game->collectible_count--;
	game->map[game->player_x][game->player_y] = 'P';
	game->move_count++;
	ft_printf("Move: %d\n", game->move_count);
}

void	mov_down(t_game *game)
{
	game->flage = 1;
	if (game->map[game->player_x + 1][game->player_y] == '1')
		return ;
	if (game->map[game->player_x + 1][game->player_y] == 'E')
	{
		if (game->collectible_count == 0)
			(you_win(), exit_game(game, 1));
		game->new_x = game->player_x + 1;
		game->new_y = game->player_y;
	}
	if (game->map[game->new_x][game->new_y] == 'P')
		game->map[game->player_x][game->player_y] = 'E';
	else
		game->map[game->player_x][game->player_y] = '0';
	game->player_x++;
	if (game->map[game->player_x][game->player_y] == 'C')
		game->collectible_count--;
	game->map[game->player_x][game->player_y] = 'P';
	game->move_count++;
	ft_printf("Move: %d\n", game->move_count);
}

void	mov_left(t_game *game)
{
	game->flage = 3;
	if (game->map[game->player_x][game->player_y - 1] == '1')
		return ;
	if (game->map[game->player_x][game->player_y - 1] == 'E')
	{
		if (game->collectible_count == 0)
			(you_win(), exit_game(game, 1));
		game->new_x = game->player_x;
		game->new_y = game->player_y - 1;
	}
	if (game->map[game->new_x][game->new_y] == 'P')
		game->map[game->player_x][game->player_y] = 'E';
	else
		game->map[game->player_x][game->player_y] = '0';
	game->player_y--;
	if (game->map[game->player_x][game->player_y] == 'C')
		game->collectible_count--;
	game->map[game->player_x][game->player_y] = 'P';
	game->move_count++;
	ft_printf("Move: %d\n", game->move_count);
}

void	mov_right(t_game *game)
{
	game->flage = 4;
	if (game->map[game->player_x][game->player_y + 1] == '1')
		return ;
	if (game->map[game->player_x][game->player_y + 1] == 'E')
	{
		if (game->collectible_count == 0)
			(you_win(), exit_game(game, 1));
		game->new_x = game->player_x;
		game->new_y = game->player_y + 1;
	}
	if (game->map[game->new_x][game->new_y] == 'P')
		game->map[game->player_x][game->player_y] = 'E';
	else
		game->map[game->player_x][game->player_y] = '0';
	game->player_y++;
	if (game->map[game->player_x][game->player_y] == 'C')
		game->collectible_count--;
	game->map[game->player_x][game->player_y] = 'P';
	game->move_count++;
	ft_printf("Move: %d\n", game->move_count);
}

int	key_hook(int keycode, t_game *game)
{
	int (new_x), (new_y);
	if (keycode == 65307)
		exit_game(game, 1);
	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == 119 || keycode == 65362)
		mov_up(game);
	else if (keycode == 115 || keycode == 65364)
		mov_down(game);
	else if (keycode == 97 || keycode == 65361)
		mov_left(game);
	else if (keycode == 100 || keycode == 65363)
		mov_right(game);
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
	return (0);
}
