#include <iostream>
#include "BankAccount.h"
#include <random>
#include <vector>
#include <limits>

int generate_id();
void menu();
void all_accounts(const std::vector<BankAccount>& accounts);
void create_account(std::vector<BankAccount>& accounts);
BankAccount* find_account(std::vector<BankAccount>& accounts);

int main() {

    std::vector<BankAccount> accounts;     // lista wszystkich kont w systemie

    while (true) {
        menu();
        int action;
        if (!(std::cin >> action)) {     // czyścimy bufor gdy wpisano tekst zamiast cyfry, dzięki czemu nie tworzy się nieskończona pętla
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter a number." << std::endl;
            continue;
        }
        switch (action) {
            case 1: {
                // Wplata - najpierw wybieramy konto, potem podajemy kwote
                BankAccount* account = find_account(accounts);
                if (account) {
                    double amount;
                    std::cout << "Enter amount to deposit: ";
                    std::cin >> amount;
                    account->deposit(amount);
                }
                break;
            }
            case 2: {
                // Wyplata - najpierw wybieramy konto, potem podajemy kwote
                BankAccount* account = find_account(accounts);
                if (account) {
                    double amount;
                    std::cout << "Enter amount to withdraw: ";
                    std::cin >> amount;
                    account->withdraw(amount);
                }
                break;
            }
            case 3: {
                // Wyswietla szczegóły konta o podanym numerze
                BankAccount* account = find_account(accounts);
                if (account) {
                    account->getInfo();
                }
                break;
            }
            case 4: {
                // Tworzymy nowe konto
                create_account(accounts);
                break;
            }
            case 5: {
                // Wypisuje listę wszystkich kont w systemie
                all_accounts(accounts);
                break;
            }
            case 6: {
                std::cout << "Exiting..." << std::endl;
                return 0;
            }
            default: {
                std::cout << "Invalid action. Please try again." << std::endl;
                break;
            }
        }
    }
}

// Generuje losowy 6-cyfrowy numer konta
int generate_id() {
    static std::mt19937 rng(std::random_device{}());
    static std::uniform_int_distribution<int> dist(100000, 999999);
    return dist(rng);
}

// Funkcja wyświetlajaca menu
void menu() {
    std::cout << "Welcome to the Bank Account Management!" << std::endl;
    std::cout << "1. Deposit" << std::endl;
    std::cout << "2. Withdraw" << std::endl;
    std::cout << "3. Get info about your account" << std::endl;
    std::cout << "4. Create account" << std::endl;
    std::cout << "5. List of all accounts" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Select action: " << std::endl;
}

// Funkcja wyświetlająca skróconą liste wszystkich kont (numer + wlasciciel)
void all_accounts(const std::vector<BankAccount>& accounts) {
    if (accounts.empty()) {
        std::cout << "No accounts found." << std::endl;
    } else {
        for (const auto& account : accounts) {
            std::cout << "Account id: " << account.getAccountNumber();
            std::cout << " Name: " << account.getName() << std::endl;
        }
    }
}


// Funkcja tworząca nowe konto i dodająca je do wektora
void create_account(std::vector<BankAccount>& accounts) {
    std::cin.ignore();
    std::cout << "Enter your name: ";
    std::string name;
    std::getline(std::cin, name);
    int account_number = generate_id();
    double initial_balance;
    std::cout << "Enter initial balance: ";
    std::cin >> initial_balance;
    BankAccount new_account(account_number, name, initial_balance);
    accounts.emplace_back(new_account);
}

// Funkcja szuka konta o podanym numerze w wektorze, jeśli go nie ma zwraca pusty wskaźnik, jeśli jest to zwraca wskaźnik do znalezionego konta
BankAccount* find_account(std::vector<BankAccount>& accounts) {
    if (accounts.empty()) {
        std::cout << "No accounts found." << std::endl;
        return nullptr;
    }
    all_accounts(accounts);
    std::cout << "Enter account number: ";
    int account_number;
    std::cin >> account_number;
    for (auto& account : accounts) {
        if (account.getAccountNumber() == account_number) {
            return &account;
        }
    }
    std::cout << "Account not found." << std::endl;
    return nullptr;
}
