#include <iostream>

using namespace std;

int main(int ac, char **av)
{
    int i = 1, j;

    if (ac > 1)
    {
        while (i < ac)
        {
            j = 0;
            while (av[i][j])
            {
                av[i][j] = toupper(av[i][j]);
                j++;
            }
            i++;
        }
        i = 1;
        while (i < ac)
        {
            cout << av[i];
            i++;
        }
        cout << "\n";
        return 0;
    }
    cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    return 1;
}