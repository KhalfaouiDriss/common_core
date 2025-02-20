/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 01:52:36 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/02/19 18:53:36 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/usr/include/minilibx-linux/mlx.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
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
	void	*b_player;
	void	*r_player;
	void	*l_player;
	void	*exit;
	void	*nc_exit;
	void	*collect;
	int		move_count;
	int		collectible_count;
	int		new_x;
	int		new_y;
	int		width;
	int		flage;
}			t_game;

// Function prototypes
void		parse_map(const char *filename, t_game *game);
void		render_map(t_game *game);
int			key_hook(int keycode, t_game *game);
void		find_player_pos(t_game *game);
int			is_rectangular(char **map);
void		map_valide(t_game *game);
int			is_path_valid(t_game game);
char		**duplicate_map(t_game game);
void		flood_fill(char **map, int x, int y);
void		free_map(char **map);
int			exit_game(t_game *game, int flag);
void		size_map(t_game *game);
void		loading_textures(t_game *game);
void		init_game(t_game *game);
void		init_image(t_game *game);
void		render_exit(t_game *game, int x, int y);
void		render_player(t_game *game, int x, int y);
void		clean_screen(t_game *game);
void		width_map(t_game *game, const char *filename);
void		loading_textures(t_game *game);
void		you_win(void);

#endif