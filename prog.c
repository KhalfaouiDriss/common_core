#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int ac, char **av)
{
	char *pass = "C47_X";
	char *flag = "000047";
	if(ac == 2)
	{
		if(strcmp(av[1], pass) == 0)
		{
			printf("password is correct, Flag : %s\n", flag);
		}
		else
		{
			printf("password not correct!\n");
		}
		return 0;
	}
	printf("args not valide\n");
	return 0;
}
