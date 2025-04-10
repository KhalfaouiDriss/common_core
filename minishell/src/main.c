#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

char	**ft_split(char const *s, char c);
void ft_echo(char **args);

void ft_env(char **args)
{
    char **env;
    int i;

    i = 0;
    if (args[0] && strcmp(args[0], "env") == 0)
    {
        env[i] = getenv("HOME");
        while (env[i])
        {
            env[i] = getenv("HOME");
            printf("%s\n", env[i]);
            i++;
        }
    }
}

void ft_cd(char **args)
{
    if (args[0] && strcmp(args[0], "cd") == 0)
    {
        chdir(args[1]);
    }
}

void ft_pwd(char **args)
{
    char *dir;
    if (strcmp(args[0], "pwd") == 0)
    {
        dir = getcwd(NULL, 0);
        printf("%s\n", dir);
    }
}

char **simple_cmd(char *str)
{
    char **args;
    
    args = ft_split(str, ' ');
    if(!args)
        return (NULL);
    ft_echo(args);
    ft_pwd(args);
    ft_cd(args);
    ft_env(args);
    return args;

}
void ft_echo(char **args)
{
    int i;

    i = 1;
    if (strcmp(args[0], "echo") == 0)
    {
        if(strcmp(args[1], "-n") == 0)
        {
            i++;
        }
        while (args[i])
        {
            if(args[i+1])
                printf("%s ", args[i]);
            else
                printf("%s", args[i]);
            i++;
        }
        if(strcmp(args[1], "-n"))
            printf("\n");
    }
}

int main(void)
{
    char *input;
    char **args;

    while (1)
    {
        input = readline("minishell$ ");
        if (!input)
            break;
        add_history(input);

        args = simple_cmd(input);

        free(input);
    }

    return 0;
}
