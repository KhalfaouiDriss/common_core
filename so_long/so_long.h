#ifndef SO_LONG
# define SO_LONG 

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "minilibx-linux/mlx.h"
#include "includes/get_next_line/get_next_line.h"
#include "includes/ft_printf/ft_printf.h"
#include "includes/libft/libft.h"   

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
	void	*f_player;
	void	*b_player;
	void	*r_player;
	void	*l_player;
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
    int i;
    int j;
    int h;
    int w;
} t_count;


void	init_game(t_game *game);
void height_map(char *file, t_game *game);
void init_map(char *file, t_game *game);
// 
void check_map(t_game *game);
void check_elements(t_game *game);
void check_coins_place(t_game *game, int x, int y);
void find_all_element(t_game *game);
void find_all_element(t_game *game);
void check_walls(t_game *game);
// 
void ft_error(t_game *game);
void flood_fill(char **map, int x, int y);
char **map_dup(char **o_map);
t_count find_player(t_game *game);

#endif