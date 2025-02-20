/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 05:35:36 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/02/20 17:33:03 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	count_digit(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	b;
	char	*res;
	int		c;

	b = n;
	c = count_digit(b);
	res = malloc(c + 1);
	if (!res)
		return (NULL);
	if (b == 0)
		res[0] = '0';
	res[c] = '\0';
	if (b < 0)
	{
		res[0] = '-';
		b *= -1;
	}
	while (b != 0)
	{
		res[--c] = (b % 10) + 48;
		b = b / 10;
	}
	return (res);
}

int	collect_animation(t_game *game)
{
	char	*move_count;

	usleep(10000);
	game->col_frames = (game->col_frames + 1) % 6;
	game->enemy_frames = (game->enemy_frames + 1) % 4;
	move_count = ft_itoa(game->move_count);
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
	mlx_string_put(game->mlx, game->win, 10, 10, 0x00FFFFFF, "move:");
	mlx_string_put(game->mlx, game->win, 50, 10, 0x00FFFFFF, move_count);
	free(move_count);
	return (0);
}
