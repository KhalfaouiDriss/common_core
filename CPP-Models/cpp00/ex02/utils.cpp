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

Account::Account(void)
{
    _accountIndex = _nbAccounts;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
    
    _nbAccounts++;
    _totalAmount += _amount;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
    
    _nbAccounts++;
    _totalAmount += _amount;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "Accounts:" << getNbAccounts() << ";total:" << getTotalAmount() 
    << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << "\n"; 
}

void Account::makeDeposit(int deposit)
{
    _nbDeposits++;
    _amount += deposit;
    _totalAmount += deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << "\n"; 
}

bool Account::makeWithdrawal(int withdrawal)
{
    if(checkAmount() || _amount < withdrawal)
        return false;
    _nbWithdrawals++;
    _amount -= withdrawal;
    return true;
     _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount  << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << "\n"; 
}

// geters functions 

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

int Account::checkAmount(void) const
{
    if(_amount < 0)
        return 1;
    return 0;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n"; 
}