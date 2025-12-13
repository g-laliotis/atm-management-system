# ATM Management System

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C99](https://img.shields.io/badge/C-C99-blue.svg)](https://en.wikipedia.org/wiki/C99)
[![GitHub](https://img.shields.io/badge/GitHub-Repository-181717?logo=github)](https://github.com/g-laliotis/atm-management-system)
[![GitHub Pages](https://img.shields.io/badge/GitHub-Pages-blue?logo=github)](https://g-laliotis.github.io/atm-management-system/)

A professional ATM management system written in C with advanced features including real-time notifications, password encryption, and enhanced UI.

🌐 **[View Live Demo & Documentation](https://g-laliotis.github.io/atm-management-system/)**

## Features

### Core Features
- User registration and login (unique usernames)
- Create new accounts (savings, current, fixed01, fixed02, fixed03)
- Update account information (country, phone number)
- Check account details with interest calculations
- Make transactions (deposit/withdraw) - not allowed for fixed accounts
- Remove accounts
- Transfer account ownership

### Bonus Features ⭐
- ✅ **Password Encryption** - XOR cipher for secure password storage
- ✅ **Enhanced Terminal UI** - Color-coded messages and professional layout
- ✅ **Real-time Notifications** - Named pipes for instant transfer alerts
- ✅ **Professional Structure** - Organized folders (bin/, obj/, include/, etc.)
- ✅ **Custom Makefile** - Advanced build system with multiple targets
- ✅ **SQLite Support** - Optional database backend with conditional compilation
- ✅ **Code Optimization** - Modular design with separated utilities

## Interest Rates

- **Savings**: 7% annual (monthly interest)
- **Fixed01** (1 year): 4% annual
- **Fixed02** (2 years): 5% annual
- **Fixed03** (3 years): 8% annual
- **Current**: No interest

## Building and Running

```bash
# Build (text files - default)
make

# Build with SQLite database
make sqlite

# Run
make run
# or
./bin/atm

# Clean
make clean

# Show all targets
make help

# Install system-wide (optional)
sudo make install
```

## Project Structure

```
.
├── bin/              # Compiled binaries
├── obj/              # Object files
├── include/          # Header files
│   └── header.h
├── src/              # Source code
│   ├── main.c        # Main program and menu
│   ├── auth.c        # Authentication with encryption
│   ├── system.c      # Account management
│   ├── utils.c       # UI and notification utilities
│   └── db.c          # Database layer (SQLite optional)
├── data/             # Data storage
│   ├── records.txt   # Account records
│   ├── users.txt     # User credentials (encrypted)
│   └── atm.db        # SQLite database (when using make sqlite)
├── logs/             # Application logs
├── docs/             # Documentation
│   ├── FEATURES.md   # Additional features documentation
│   └── index.html    # GitHub Pages
├── CHANGELOG.md      # Version history
├── CONTRIBUTING.md   # Contribution guidelines
├── DEVELOPMENT.md    # Development summary
├── LICENSE           # MIT License
├── Makefile          # Build configuration
└── README.md         # Project documentation

```

## Sample Users

- Username: Alice, Password: 1234password
- Username: Michel, Password: password1234

## Real-time Notifications Demo

Open two terminals:

**Terminal 1:**
```bash
./bin/atm
# Login as Alice
# Transfer account to Michel
```

**Terminal 2:**
```bash
./bin/atm
# Login as Michel
# You'll see instant notification when Alice transfers!
```

## Technical Details

- **Language**: C (C99 standard)
- **Threading**: POSIX threads for notifications
- **IPC**: Named pipes (FIFOs)
- **Encryption**: XOR cipher
- **Build System**: GNU Make
- **Optional DB**: SQLite3

## Security

- Passwords are encrypted using XOR cipher before storage
- User authentication validates encrypted credentials
- Account operations require ownership verification

## Development

Compiled with strict warnings:
```bash
gcc -Wall -Wextra -std=c99 -pthread
```

No warnings, clean compilation.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Author

**Giorgos Laliotis**
- GitHub: [@g-laliotis](https://github.com/g-laliotis)
- Project: [atm-management-system](https://github.com/g-laliotis/atm-management-system)
