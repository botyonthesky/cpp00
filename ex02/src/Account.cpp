/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 06:34:14 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/22 12:32:27 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void)
{

}

int Account::getNbAccounts()
{
    return (Account::_nbAccounts);
}

int	Account::getTotalAmount()
{
    return (Account::_totalAmount);
}


int	Account::getNbDeposits()
{
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{    
    return (Account::_totalNbWithdrawals);   
}


void	Account::_displayTimestamp()
{
    std::string real_time;
    std::time_t now = std::time(0);
    
    std::tm* now_time = std::localtime(&now);

    char buffer[100];
    if (std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", now_time))
        std::cout << "[" << buffer << "] ";
    else
        std::cout << "Error on timestamp" << std::endl;
}
Account::Account(int initial_deposit) : _accountIndex(Account::_nbAccounts), _amount(initial_deposit)
{
    _displayTimestamp();
    _nbAccounts++;
    _totalAmount += initial_deposit;
    std::cout << "index:" << _accountIndex << ";"
    << "amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    _nbAccounts--;
    _totalAmount -= _amount;
    std::cout << "index:" << _accountIndex << ";"
    << "amount:" << _amount << ";" << "closed" << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    _nbDeposits++;
    
    std::cout << "index:" << _accountIndex << ";"
    << "p_amount:" << _amount << ";" << "deposits:" 
    << deposit << ";" << "amount:" << _amount + deposit
    << ";" << "nb_deposits:" << _nbDeposits << std::endl;

    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits += _nbDeposits;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    _nbWithdrawals++;
    if (withdrawal > _amount)
    {
        std::cout << "index:" << _accountIndex << ";"
        << "p_amount:" << _amount << ";" << "withdrawal:refused"
        << std::endl;
        return (false);
    }
    else
    {
        std::cout << "index:" << _accountIndex << ";"
        << "p_amount:" << _amount << ";" << "withdrawals:" 
        << withdrawal << ";" << "amount:" << _amount - withdrawal
        << ";" << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals += _nbWithdrawals;
    return (true);
}
void    Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
    << "amount:" << _amount << ":" << "deposits:"
    << _nbDeposits << ";" << "withdrawals:"
    << _nbWithdrawals << std::endl;
}
void	Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";"
    << "total:" << getTotalAmount() << ";" << "deposits:"
    << getNbDeposits() << ";" << "withdrawals:"
    << getNbWithdrawals() << std::endl;

}

