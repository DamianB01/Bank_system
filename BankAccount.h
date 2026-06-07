// plik nagłówkowy
#pragma once
#include <string>

// Klasa reprezentująca konto bankowe
class BankAccount {
private:
    int account_number;    // numer konta
    std::string name;   // nazwa konta
    double balance;    // saldo

public:

    BankAccount(int account_number, const std::string& name, double initialBalance);    // konstruktor (tworzy konto z podanym numerem, nazwa i saldem)

    void deposit(double amount);   // Wplaca podana kwote na konto (musi byc dodatnia)
    void withdraw(double amount);   // Wyplaca podana kwote z konta (niemozliwa wyplata powyzej salda)
    void getInfo() const;     // Wypisuje informacje o koncie: numer, wlasciciel, saldo

    int getAccountNumber() const;
    const std::string& getName() const;

    ~BankAccount() = default;    // destruktor
};