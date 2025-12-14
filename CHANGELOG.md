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
- Professional project structure (src/, obj/, bin/, logs/)
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

## [1.1.0] - 2024-12-07

### Added
- Comprehensive test suite (`test_atm.c`) with 8 automated tests
- Professional test reporting with pass/fail statistics
- `make test` target for easy testing
- Test coverage for all core functionality:
  - Password encryption/decryption
  - User registration and authentication
  - Account creation and management
  - Interest calculations
  - File operations and data validation
  - Notification system

### Fixed
- Phone number data type changed from `int` to `long long`
- Phone number display now handles large numbers correctly
- Real-time notification system no longer blocks program execution
- Removed input conflicts between notification thread and main program
- Notifications now display instantly without interrupting menu operations

### Changed
- Updated all documentation to include test suite information
- Enhanced project structure documentation
- Improved notification system for better user experience

### Technical
- Standalone test compilation without main program dependencies
- Non-blocking notification display
- Better data type handling for large numeric values