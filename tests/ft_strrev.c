
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../libft/libft.h"



int main(int ac, char **av, char **envp)
{
    char **env = ft_split(envp[28] + 5, ':');
    int i = 0;
    
    // dup2()


    while (env[i])
    {
        printf("env : %d -> %s\n",i, env[i]);
        // i++;
    }
}




