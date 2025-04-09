#include "minilibx-linux/mlx.h"
void *mlx;
void *win;
int move(int key ,void *t)
{
    if(key == 115)
    {
        // mlx_clear_window(mlx, win);
        mlx_string_put(mlx, win, 50, 50, 105, "1338");
    }
    // if(key == 100)
    // {
    //     mlx_clear_window(mlx, win);
    //     mlx_string_put(mlx, win, 150, 100, 255, "1337");
    // }
    return 0;
}

int main()
{
    void* t;
    int a = 460;
    mlx = mlx_init();
    win = mlx_new_window(mlx, 470, 470, "test");
    void* pic = mlx_xpm_file_to_image(mlx, "dkhalfao.xpm", &a, &a);
    mlx_put_image_to_window(mlx, win, pic, 0, 0);
    mlx_string_put(mlx, win, 50, 50, 255, "1337");
    mlx_key_hook(win, move, t);

    mlx_loop(mlx);
}