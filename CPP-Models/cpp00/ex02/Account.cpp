#include "Account.hpp"

int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;

void Account::_displayTimestamp(void)
{
    time_t stime = time(NULL);

    tm *now = localtime(&stime);

    std::cout << "["
              << now->tm_year + 1900
              << std::setfill('0') << std::setw(2) << now->tm_mon
              << std::setfill('0') << std::setw(2) << now->tm_mday
              << "_"
              << std::setfill('0') << std::setw(2) << now->tm_hour
              << std::setfill('0') << std::setw(2) << now->tm_min
              << std::setfill('0') << std::setw(2) << now->tm_sec
              << "] ";
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() 
    << ";deposits:" << _totalNbDeposits << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount 
    << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << "\n";
}

void Account::makeDeposit(int deposit)
{
    _nbDeposits++;
    _totalNbDeposits++;
    _amount += deposit;
    _totalAmount += deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit
    << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << "\n";
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    if (_amount > withdrawal)
    {
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal 
        << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << "\n";
    }
    else
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << "refused\n";
    return true;
}