#include "Account.hpp"

using namespace std;

int Account::_nbAccounts = 0;

// int Account::getNbAccounts(void)
// {
//     return _nbAccounts;
// }

int main()
{
    Account tt;
    tt._nbAccounts = 5;
    Account tt2;

    cout << tt._nbAccounts << endl;
    cout << tt2._nbAccounts << endl;

}