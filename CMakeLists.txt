cmake_minimum_required(VERSION 4.2)
project(bank_system)

set(CMAKE_CXX_STANDARD 20)

add_executable(bank_system main.cpp
        BankAccount.cpp
        BankAccount.h)
