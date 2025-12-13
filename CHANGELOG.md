# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.0.0] - 2024-12-07

### Added
- Initial ATM Management System implementation
- User registration and login with unique username validation
- Account creation for multiple types (savings, current, fixed01/02/03)
- Account management (update country/phone, check details, list accounts)
- Transaction system (deposit/withdraw) with fixed account restrictions
- Interest rate calculations for all account types
- Account removal with ownership validation
- Transfer ownership between users
- Password encryption using XOR cipher
- Enhanced terminal UI with colors and professional layout
- Real-time notifications via named pipes (FIFO)
- Professional project structure (include/, obj/, bin/, logs/)
- SQLite database support with conditional compilation (`make sqlite`)
- Comprehensive Makefile with multiple targets
- Complete documentation and GitHub Pages
- Dual storage modes: text files (default) and SQLite database
- MIT License

### Security
- XOR cipher encryption for password storage
- Ownership verification for all account operations
- No plaintext passwords in data files

### Technical
- C99 standard compliance
- POSIX threads for notifications
- Named pipes for inter-process communication
- Zero compilation warnings with strict flags
- Modular code design with separated utilities