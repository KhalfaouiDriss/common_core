#include <stdio.h>
#include <math.h>

int main(void)
{
    int map[5][5] = {
        {1,1,1,1,1},
        {1,0,0,0,1},
        {1,0,0,0,1},
        {1,0,0,0,1},
        {1,1,1,1,1}
    };

    double posX = 2.5, posY = 2.5;  
    double rayDirX = 1.0, rayDirY = 0.0;

    int mapX = (int)posX;
    int mapY = (int)posY;

    double deltaDistX = 1;
    double deltaDistY = 1;

    double sideDistX, sideDistY;
    int stepX, stepY;

    if (rayDirX < 0)
    {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
    }
    else
    {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
    }
    stepY = 0;
    sideDistY = INFINITY;
    int hit = 0;
    while (hit == 0)
    {
        if (sideDistX < sideDistY)
        {
            sideDistX += deltaDistX;
            mapX += stepX;
        }
        if (map[mapY][mapX] == 1)
        {
            hit = 1;
            printf("Hit wall at cell (%d, %d)\n", mapX, mapY);
        }
    }
    return 0;
}