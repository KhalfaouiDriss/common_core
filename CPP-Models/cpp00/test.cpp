#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{

    time_t stime = time(nullptr);

    tm *now = localtime(&stime);

    cout << "[" 
    << now->tm_year + 1900 
    << setfill('0') << setw(2) << now->tm_mon 
    << setfill('0') << setw(2) << now->tm_mday 
    << "_" 
    << setfill('0') << setw(2) << now->tm_hour 
    << setfill('0') << setw(2) << now->tm_min 
    << setfill('0') << setw(2) << now->tm_sec
    << "] ";
}