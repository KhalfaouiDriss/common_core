/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:10:28 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/04/09 10:20:28 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "includes/ft_printf/ft_printf.h"
# include "includes/get_next_line/get_next_line.h"
# include "includes/libft/libft.h"
# include "/usr/include/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	void	*wall;
	void	*empty;
	void	*player;
	void	*exit;
	void	*exit_c;
	void	*exit_o;
	int		is_exit;
	void	*collect;
	int		move_count;
	int		collectible_count;
	int		new_x;
	int		new_y;
	int		height;
	int		flage;
}			t_game;

typedef struct s_count
{
	int		i;
	int		j;
	int		h;
	int		w;
}			t_count;

void		init_game(t_game *game);
void		height_map(char *file, t_game *game);
void		init_map(char *file, t_game *game);

void		check_map(t_game *game);
void		check_elements(t_game *game);
void		check_coins_place(t_game *game, int x, int y);
void		find_all_element(t_game *game);
void		check_walls(t_game *game);

void		ft_error(t_game *game);
void		flood_fill(char **map, int x, int y);
char		**map_dup(char **o_map);
t_count		find_player(t_game *game);
void		free_map(char **map);
int			exit_game(t_game *game);
void		destroy_all_imgs(t_game *game);
void		init_count(t_count *count);

void		initial_imgs(t_game *game);
void		render_game(t_game *game);
int			find_move(t_game *game, int keycode, int *dx, int *dy);
void		reinit_game(t_game *game, int *new_x, int *new_y);
int			move_player(int keycode, t_game *game);

#endif
