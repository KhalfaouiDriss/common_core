#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "/usr/include/minilibx-linux/mlx.h"

#define MAP_H 8
#define MAP_W 24
#define WIN_W 640
#define WIN_H 480
#define TILE 64
#define BLACK 0x000000
#define GRAY 0x808080
#define WHITE 0xFFFFFF
#define BLUE 0x0000FF
#define M_PI 3.14159265358979323846

static const int gray = GRAY;
static const int white = WHITE;
static const int blue = BLUE;

static char **getMap()
{
    char **map = malloc(MAP_H * sizeof(char *));
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

int find_player(char **map, float *px, float *py, float *pa)
{
    for (int i = 0; i < MAP_H; i++)
    {
        for (int j = 0; j < MAP_W; j++)
        {
            if (map[i][j] == 'P')
            {
                *px = j * TILE + TILE / 2;
                *py = i * TILE + TILE / 2;
                *pa = 0.0; // النظر نحو الشرق
                return 0;
            }
        }
    }
    return 1;
}

int create_background(void *mlx, void *win)
{
    for (int y = 0; y < WIN_H / 2; y++)
        for (int x = 0; x < WIN_W; x++)
            mlx_pixel_put(mlx, win, x, y, gray);

    for (int y = WIN_H / 2; y < WIN_H; y++)
        for (int x = 0; x < WIN_W; x++)
            mlx_pixel_put(mlx, win, x, y, blue);
    return 0;
}

int render_view(void *mlx, void *win, char **map, float px, float py, float pa)
{
    for (int x = 0; x < WIN_W; x++)
    {
        double rayAngle = (pa - (30.0 * (M_PI / 180.0))) +
                          ((double)x / (double)WIN_W) * (60.0 * (M_PI / 180.0));
        double rayDirX = cos(rayAngle);
        double rayDirY = sin(rayAngle);

        double distanceToWall = 0.0;
        bool hitWall = false;

        while (!hitWall && distanceToWall < 1000.0)
        {
            distanceToWall += 1.0;
            double testX = px + rayDirX * distanceToWall;
            double testY = py + rayDirY * distanceToWall;

            int mapX = (int)(testX / TILE);
            int mapY = (int)(testY / TILE);

            if (mapX < 0 || mapX >= MAP_W || mapY < 0 || mapY >= MAP_H)
            {
                hitWall = true;
                distanceToWall = 1000.0;
            }
            else if (map[mapY][mapX] == '1')
            {
                hitWall = true;
            }
        }

        int lineHeight = (int)(WIN_H / distanceToWall * 64); // scale line height
        int drawStart = -lineHeight / 2 + WIN_H / 2;
        if (drawStart < 0)
            drawStart = 0;
        int drawEnd = lineHeight / 2 + WIN_H / 2;
        if (drawEnd >= WIN_H)
            drawEnd = WIN_H - 1;

        for (int y = drawStart; y < drawEnd; y++)
        {
            if (y >= 0 && y < 10)
                mlx_pixel_put(mlx, win, x, y, BLACK);
            else
                mlx_pixel_put(mlx, win, x, y, white);
        }
    }
    return 0;
}

int main()
{
    void *mlx = mlx_init();
    if (!mlx)
        return 1;

    void *win = mlx_new_window(mlx, WIN_W, WIN_H, "Raycast Test");
    if (!win)
        return 1;

    char **map = getMap();
    float px, py, pa;
    find_player(map, &px, &py, &pa);

    printf("Player: px=%.1f py=%.1f pa=%.1f\n", px, py, pa);

    create_background(mlx, win);
    render_view(mlx, win, map, px, py, pa);

    mlx_loop(mlx);
    return 0;
}
