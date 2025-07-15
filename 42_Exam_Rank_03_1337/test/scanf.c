#include <stdarg.h>
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>

int init_string(char **str)
{
    int i = 0;
    i = read(0, *str, 50);
    *str[i] = '\0';
}

int init_int(int *number)
{
    int g;
    int i, j;

    j = 0;
    while ((i = fgetc(stdin)) != '\n')
    {
        if(isdigit(i))
            j = (j * 10) +( i - '0'); 
        else
            break;
    }
    *number = j;
}

int init_char(int *c)
{
    int i;

    i = fgetc(stdin);
    *c = i;

    return 1;
}

int check_format(va_list list, char format)
{
    char **arg;
    
    if(format == 's')
    {
        init_string(va_arg(list, char **));
    }
    if(format == 'd')
    {
        init_int(va_arg(list, int *));
    }
    if(format == 'c')
        init_char((int *)va_arg(list, int *));
}

int ft_scanf(char *format, ...)
{
    va_list list;
    void **arg;
    int i;
    int ar;

    i = 0;
    ar = 0;
    va_start(list, format);
    while (format[i])
    {
        if(format[i] == '%' && format[i + 1])
            check_format(list, format[i + 1]);
        i++;
    }
    
}

int main()
{
    char *s;
    char h;
    int a;
    int i;

    // scanf("%s %s", s);
    // scanf("%d", &a);
    ft_scanf("%c", &h);
    // ft_scanf("%s %d", s, a);
    printf("%c\n", h);
    return 0;
}
