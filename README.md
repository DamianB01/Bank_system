# Mini Bank System
 
A simple console-based banking system written in C++.
 
## Features
- Create bank accounts  
- Deposit and withdraw funds  
- View account details  
- List all accounts  

## Build & Run
 
```bash
g++ -std=c++20 main.cpp BankAccount.cpp -o bank
./bank
```
 
## How it works
 
After launching the program, a menu is displayed with the following options:
 
- **Create account** — enter your name and initial balance; the system generates a unique 6-digit account number automatically
- **Deposit** — select an account by its number, then enter the amount to deposit
- **Withdraw** — select an account by its number, then enter the amount to withdraw; withdrawal above the available balance is not allowed
- **Get account info** — displays the account number, owner name, and current balance
- **List all accounts** — shows a summary of all accounts (number and owner name)
All data is stored in memory and is lost when the program exits.
