#include <stdio.h>
#include <stdlib.h>


int is_save(int *pos, int col, int row)
{
    int prev_col = 0;
    int prev_row;

    while (prev_col < col)
    {
        prev_row = pos[prev_col];
        if(row == prev_row || prev_row - prev_col == row - col || prev_row + prev_col == row + col)
            return 0;
        prev_col++;
    }
    return 1;
}
void solve(int *pos, int col, int n)
{
    if(col == n)
    {
        int i = 0;
        while (i < n)
        {
            if(i > 0)
                printf(" ");
            printf("%d", pos[i]);
                i++;
        }
        printf("\n");
        return ;
    }

    int row = 0;
    while (row < n)
    {
        if(is_save(pos, col, row))
        {
            pos[col] = row;
            solve(pos, col + 1, n);
        }
        row++;
    }
    
}

int main(int ac, char **av)
{
    if(ac != 2 || av[1][0] == '-')
        return 1;
    int n = atoi(av[1]);
    int *pos= malloc(sizeof(int) * n);
    if(!pos)
        return 1;
    solve(pos, 0, n);
    free(pos);
}