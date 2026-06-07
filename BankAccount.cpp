#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(int account_number, const std::string& name, double initialBalance) : account_number(account_number), name(name), balance(initialBalance){
    std::cout << "Account created for " << name << " with account number " << account_number << " and initial balance $" << initialBalance << std::endl;
}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Deposited $" << amount << ". New balance: $" << balance << std::endl;
    } else {
        std::cout << "Deposit amount must be positive." << std::endl;
    }
}

void BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        std::cout << "Withdrew $" << amount << ". New balance: $" << balance << std::endl;
    } else {
        std::cout << "Invalid withdrawal amount." << std::endl;
    }
}

void BankAccount::getInfo() const {
    std::cout << "Account Number: " << account_number << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Balance: " << balance << "$" << std::endl;
}

int BankAccount::getAccountNumber() const {
    return account_number;
}

const std::string& BankAccount::getName() const {
    return name;
}