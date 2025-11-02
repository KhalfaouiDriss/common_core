// Minimal MLX raycasting example (Linux / MiniLibX)
// Build (Linux, 42's minilibx):
//   gcc -O2 -std=c11 mlx_raycast.c -I/usr/include/minilibx-linux \
//       -L/usr/include/minilibx-linux -lmlx -lXext -lX11 -lm -o mlx_raycast
// Or: make mlx (with the provided Makefile)

#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "mlx.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define MAP_W 24
#define MAP_H 24
#define WIN_W 800
#define WIN_H 600

static const char *mapData =
"########################"
"#..............##......#"
"#..##...........#......#"
"#...............#......#"
"#.......##......#......#"
"#...............#......#"
"#...............#......#"
"#..##...........#......#"
"#..##...........#......#"
"#...............#......#"
"#...............#......#"
"#...............#......#"
"#...............#......#"
"#......##.............##"
"#......##.............##"
"#...............#......#"
"#...............#......#"
"#...............#......#"
"#...............#......#"
"#...............#......#"
"#...............#......#"
"#......................#"
"#......................#"
"########################";

static inline char map_at(int x, int y) {
    if (x < 0 || x >= MAP_W || y < 0 || y >= MAP_H) return '#';
    return mapData[y * MAP_W + x];
}

typedef struct s_app {
    void *mlx;
    void *win;
    void *img;
    char *data;
    int bpp;
    int line_len;
    int endian;
    // player
    double px, py; // position
    double pa;     // angle (radians)
    double fov;    // field of view (radians)
    // timing
    struct timespec last_ts;
    // input
    bool key_w, key_a, key_s, key_d;
} t_app;

static inline void put_pixel(t_app *app, int x, int y, unsigned int color) {
    if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H) return;
    char *dst = app->data + (y * app->line_len + x * (app->bpp / 8));
    *(unsigned int*)dst = color;
}

static inline unsigned int shade_color(unsigned int color, double factor) {
    if (factor < 0.0) factor = 0.0;
    if (factor > 1.0) factor = 1.0;
    unsigned int r = ((color >> 16) & 0xFF) * factor;
    unsigned int g = ((color >> 8) & 0xFF) * factor;
    unsigned int b = (color & 0xFF) * factor;
    return (r << 16) | (g << 8) | b;
}

static void draw_vline(t_app *app, int x, int y0, int y1, unsigned int color) {
    if (y0 < 0) y0 = 0;
    if (y1 >= WIN_H) y1 = WIN_H - 1;
    for (int y = y0; y <= y1; ++y) put_pixel(app, x, y, color);
}

static void clear_background(t_app *app) {
    // ceiling
    for (int y = 0; y < WIN_H / 2; ++y) {
        for (int x = 0; x < WIN_W; ++x) put_pixel(app, x, y, 0x202533);
    }
    // floor
    for (int y = WIN_H / 2; y < WIN_H; ++y) {
        double t = (double)(y - WIN_H / 2) / (WIN_H / 2);
        unsigned int base = 0x3a3a3a; // base grey
        unsigned int col = shade_color(base, 0.6 + 0.4 * (1.0 - t));
        for (int x = 0; x < WIN_W; ++x) put_pixel(app, x, y, col);
    }
}

static void render(t_app *app) {
    clear_background(app);

    // Precompute direction and camera plane for FOV
    double dirX = cos(app->pa);
    double dirY = sin(app->pa);
    double planeScale = tan(app->fov / 2.0);
    double planeX = -dirY * planeScale;
    double planeY =  dirX * planeScale;

    for (int sx = 0; sx < WIN_W; ++sx) {
        double camX = 2.0 * sx / (double)WIN_W - 1.0; // -1..1 across screen
        double rayDirX = dirX + planeX * camX;
        double rayDirY = dirY + planeY * camX;

        // DDA setup
        int mapX = (int)app->px;
        int mapY = (int)app->py;

        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1.0 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1.0 / rayDirY);

        int stepX, stepY;
        double sideDistX, sideDistY;

        if (rayDirX < 0) { stepX = -1; sideDistX = (app->px - mapX) * deltaDistX; }
        else { stepX = 1; sideDistX = (mapX + 1.0 - app->px) * deltaDistX; }
        if (rayDirY < 0) { stepY = -1; sideDistY = (app->py - mapY) * deltaDistY; }
        else { stepY = 1; sideDistY = (mapY + 1.0 - app->py) * deltaDistY; }

        int hit = 0; int side = 0; // side: 0 X, 1 Y
        while (!hit) {
            if (sideDistX < sideDistY) { sideDistX += deltaDistX; mapX += stepX; side = 0; }
            else { sideDistY += deltaDistY; mapY += stepY; side = 1; }
            if (mapX < 0 || mapX >= MAP_W || mapY < 0 || mapY >= MAP_H) { hit = 1; break; }
            if (map_at(mapX, mapY) == '#') hit = 1;
        }

        double perpDist;
        if (side == 0) perpDist = ((mapX - app->px) + (1 - stepX) / 2.0) / (rayDirX == 0 ? 1e-9 : rayDirX);
        else perpDist = ((mapY - app->py) + (1 - stepY) / 2.0) / (rayDirY == 0 ? 1e-9 : rayDirY);
        if (perpDist < 1e-4) perpDist = 1e-4;

        int lineH = (int)(WIN_H / perpDist);
        int y0 = -lineH / 2 + WIN_H / 2;
        int y1 = lineH / 2 + WIN_H / 2;

        // Wall color with distance + side shading
        double shade = 1.0 / (1.0 + perpDist * 0.2);
        if (side == 1) shade *= 0.7; // darker on Y sides
        unsigned int col = shade_color(0x9ad2ff, shade);
        if (((mapX + mapY) & 1) == 1) col = shade_color(0xffc39a, shade);

        draw_vline(app, sx, y0, y1, col);
    }
}

static int key_press(int key, void *param) {
    t_app *a = (t_app*)param;
    if (key == 65307) { // ESC
        mlx_destroy_window(a->mlx, a->win);
        exit(0);
    }
    if (key == 'w' || key == 'W') a->key_w = true;
    if (key == 'a' || key == 'A') a->key_a = true;
    if (key == 's' || key == 'S') a->key_s = true;
    if (key == 'd' || key == 'D') a->key_d = true;
    return 0;
}

static int key_release(int key, void *param) {
    t_app *a = (t_app*)param;
    if (key == 'w' || key == 'W') a->key_w = false;
    if (key == 'a' || key == 'A') a->key_a = false;
    if (key == 's' || key == 'S') a->key_s = false;
    if (key == 'd' || key == 'D') a->key_d = false;
    return 0;
}

static int loop_hook(void *param) {
    t_app *a = (t_app*)param;
    // delta time
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    double dt = (now.tv_sec - a->last_ts.tv_sec) + (now.tv_nsec - a->last_ts.tv_nsec) / 1e9;
    if (dt < 0) dt = 0;
    if (dt > 0.05) dt = 0.05; // clamp to avoid jumps
    a->last_ts = now;

    double moveSpeed = 3.0; // units/sec
    double rotSpeed = 2.0;  // rad/sec

    // rotation first
    if (a->key_a) a->pa -= rotSpeed * dt;
    if (a->key_d) a->pa += rotSpeed * dt;

    double dirX = cos(a->pa), dirY = sin(a->pa);
    // move forward/back
    if (a->key_w) {
        double nx = a->px + dirX * moveSpeed * dt;
        double ny = a->py + dirY * moveSpeed * dt;
        if (map_at((int)nx, (int)a->py) == '.') a->px = nx;
        if (map_at((int)a->px, (int)ny) == '.') a->py = ny;
    }
    if (a->key_s) {
        double nx = a->px - dirX * moveSpeed * dt;
        double ny = a->py - dirY * moveSpeed * dt;
        if (map_at((int)nx, (int)a->py) == '.') a->px = nx;
        if (map_at((int)a->px, (int)ny) == '.') a->py = ny;
    }

    render(a);
    mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
    return 0;
}

int main(void) {
    t_app app;
    memset(&app, 0, sizeof(app));
    app.px = 12.0; app.py = 12.0; app.pa = 0.0; app.fov = M_PI / 3.0;

    app.mlx = mlx_init();
    if (!app.mlx) { fprintf(stderr, "mlx_init failed\n"); return 1; }
    app.win = mlx_new_window(app.mlx, WIN_W, WIN_H, "MLX Raycast");
    app.img = mlx_new_image(app.mlx, WIN_W, WIN_H);
    app.data = mlx_get_data_addr(app.img, &app.bpp, &app.line_len, &app.endian);

    // Initial draw
    clock_gettime(CLOCK_MONOTONIC, &app.last_ts);
    render(&app);
    mlx_put_image_to_window(app.mlx, app.win, app.img, 0, 0);

    // Key press/release hooks (X11: 2=KeyPress, 3=KeyRelease)
    mlx_hook(app.win, 2, 1L<<0, key_press, &app);
    mlx_hook(app.win, 3, 1L<<1, key_release, &app);
    mlx_loop_hook(app.mlx, loop_hook, &app);
    mlx_loop(app.mlx);
    return 0;
}
