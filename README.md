# Customer Account Manager (Chapter 11 – Challenges 7 & 8)

A C++ console application that manages a list of up to ten customer accounts using structures and menu-driven interaction. This program demonstrates the use of user-defined data types, input validation, and array handling for record storage.

## Overview
- Defines a structure `Account` containing fields for customer details:
  - `name`, `address`, `city`, `state`, `zip`, `phone`, `email`, `accBal`, and `lastPayDate`.
- Provides a menu interface with the following options:
  1. Enter New Customer Account  
  2. Update Existing Account  
  3. Display All Accounts  
  4. Search Accounts by Name  
  5. Exit the Program
- Allows users to repeatedly perform actions until they choose to exit.

## Core Logic
- `getAcc(Account customers[], int size)`  
  Prompts for all customer fields with validation. Prevents negative account balances and empty string entries.
- `updateAcc(Account customers[], int size)`  
  Locates a customer by name, displays current information, and allows individual field updates.
- `displayAcc(Account customers[], int size)`  
  Displays all records in a formatted table with aligned columns and currency formatting for balances.
- `searchAcc(Account customers[], int size)`  
  Performs a case-insensitive search to locate accounts by partial or full name.
- Input handling uses `getline()` for string data to allow spaces in names and addresses.

## Input Validation
- Rejects empty name, address, and city fields.  
- Ensures account balance is not negative.  
- Reprompts until valid data is entered.

## Build & Run
- Visual Studio (Windows): open the solution or create a Console App and add the source file, then **Build → Run**.
- g++ (CLI):
  ```bash
  g++ -std=c++11 -O2 -o CustomerAccountManager nazarioCPP211.cpp
  ./CustomerAccountManager
