#include <mlx.h>
#include <stdlib.h>

int main()
{
    void *mlx;
    void *win;

    // 1. تهيئة MiniLibX
    mlx = mlx_init();
    if (!mlx)
    {
        return 1;
    }

    // 2. إنشاء نافذة
    win = mlx_new_window(mlx, 800, 600, "MiniLibX Test");
    if (!win)
    {
        free(mlx);
        return 1;
    }

    // 3. تشغيل الحلقة الرئيسية للـ MiniLibX
    mlx_loop(mlx);

    return 0;
}
