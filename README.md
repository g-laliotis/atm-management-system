# ATM Management System

A simple ATM management system written in C that allows users to manage bank accounts.

## Features

- User registration and login (unique usernames)
- Create new accounts (savings, current, fixed01, fixed02, fixed03)
- Update account information (country, phone number)
- Check account details with interest calculations
- Make transactions (deposit/withdraw) - not allowed for fixed accounts
- Remove accounts
- Transfer account ownership

## Interest Rates

- **Savings**: 7% annual (monthly interest)
- **Fixed01** (1 year): 4% annual
- **Fixed02** (2 years): 5% annual
- **Fixed03** (3 years): 8% annual
- **Current**: No interest

## Building and Running

```bash
make
./atm
```

## File Structure

```
.
├── data/
│   ├── records.txt    # Account records
│   └── users.txt      # User credentials
├── src/
│   ├── auth.c         # Authentication functions
│   ├── header.h       # Header file with structures
│   ├── main.c         # Main program and menu
│   └── system.c       # Account management functions
└── Makefile
```

## Sample Users

- Username: Alice, Password: 1234password
- Username: Michel, Password: password1234
