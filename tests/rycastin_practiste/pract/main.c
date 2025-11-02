#include "/usr/include/minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>


static char **getMap()
{
    char **map = malloc(8 * sizeof(char *));
    map[0] = "111111111111111111111111";
    map[1] = "100110000000000010000001";
    map[2] = "100110000000000010000001";
    map[3] = "100000000000001010000001";
    map[4] = "10000000000P000000000001";
    map[5] = "100000100000000010000001";
    map[6] = "100000000000000010000001";
    map[7] = "111111111111111111111111";
    return map;
}

void drow_sq(void *mlx, void *win, int i, int j, int color)
{
    int x = 15 * j, y = 15 * i;

    int e = 0 , r = 0;

    while (e < 15)
    {
        r = 0;
        while (r < 15)
        {
            mlx_pixel_put(mlx, win, x + r, y + e, color);
            r++;
        }
        e++;
    }
    
}

void rander_map(void *mlx, void *win, char **map)
{
    int i = 0, j = 0;

    while (i < 8)
    {
        j = 0;
        while (j < 24)
        {
            if(map[i][j] == '1')
                drow_sq(mlx, win, i, j, 0X638391);
            else
                drow_sq(mlx, win, i, j, 0xFFFFFF);
                
            j++;
        }
        i++;
    }
    
}



void render_player(void *mlx, void *win, int color)
{
    double px = 8.0, py = 5.0;

    int i = 0, z = 0;
    while (i < 5)
    {
        z = 0;
        while (z < 5)
        {
            mlx_pixel_put(mlx, win, px * 15 + i, py * 15 + z, color);
            z++;
        }
        i++;
    }
    

}

void events(void *mlx, void *win)
{
}

int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 640, 420, "test");
    char **map = getMap();
    rander_map(mlx, win, map);
    render_player(mlx, win, 0x3F25);
    events(mlx, win);
    mlx_loop(mlx);
}