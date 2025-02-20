/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:52:03 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/02/16 18:48:48 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	loading_textures(t_game *game)
{
	int	a;

	a = 32;
	init_image(game);
	game->wall = mlx_xpm_file_to_image(game->mlx, "texture/wall.xpm", &a, &a);
	game->player = mlx_xpm_file_to_image(game->mlx, "texture/player.xpm", &a,
			&a);
	game->b_player = mlx_xpm_file_to_image(game->mlx, "texture/b_player.xpm",
			&a, &a);
	game->r_player = mlx_xpm_file_to_image(game->mlx, "texture/r_player.xpm",
			&a, &a);
	game->l_player = mlx_xpm_file_to_image(game->mlx, "texture/l_player.xpm",
			&a, &a);
	game->collect = mlx_xpm_file_to_image(game->mlx, "texture/collect_f1.xpm",
			&a, &a);
	game->exit = mlx_xpm_file_to_image(game->mlx, "texture/exit.xpm", &a, &a);
	game->nc_exit = mlx_xpm_file_to_image(game->mlx, "texture/nc_exit.xpm", &a,
			&a);
	game->empty = mlx_xpm_file_to_image(game->mlx, "texture/empty.xpm", &a, &a);
	if (!game->wall || !game->player || !game->collect || !game->exit
		|| !game->empty || !game->r_player || !game->l_player || !game->b_player
		|| !game->nc_exit)
		(write(2, "Error: Failed to load textures\n", 30), exit_game(game, 1));
}

void	parse_map(const char *filename, t_game *game)
{
	char	*line;

	int (fd), (i);
	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		(write(2, "Error: Failed to open map file.\n", 32), exit(1));
	width_map(game, filename);
	game->map = malloc(sizeof(char *) * (game->map_width + 1));
	if (!game->map)
		(write(2, "Error: Memory allocation failed.\n", 33), exit(1));
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->map[i] = ft_strdup(line);
		if (game->map[i][ft_strlen(line) - 1] == '\n')
			game->map[i][ft_strlen(line) - 1] = '\0';
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	game->map[i] = NULL;
	close(fd);
}

void	render_exit(t_game *game, int x, int y)
{
	if (game->collectible_count == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->nc_exit, x * 32, y
			* 32);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->exit, x * 32, y
			* 32);
}

void	render_player(t_game *game, int x, int y)
{
	if (game->flage == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->player, x * 32, y
			* 32);
	if (game->flage == 2)
		mlx_put_image_to_window(game->mlx, game->win, game->b_player, x * 32, y
			* 32);
	if (game->flage == 3)
		mlx_put_image_to_window(game->mlx, game->win, game->l_player, x * 32, y
			* 32);
	if (game->flage == 4)
		mlx_put_image_to_window(game->mlx, game->win, game->r_player, x * 32, y
			* 32);
}

void	render_map(t_game *game)
{
	int (y), (x);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, x
					* 32, y * 32);
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->empty, x
					* 32, y * 32);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collect, x
					* 32, y * 32);
			else if (game->map[y][x] == 'E')
				render_exit(game, x, y);
			else if (game->map[y][x] == 'P')
				render_player(game, x, y);
			x++;
		}
		y++;
	}
}
