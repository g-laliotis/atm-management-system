# Contributing to ATM Management System

Thank you for your interest in contributing to the ATM Management System! This document provides guidelines for contributing to this project.

## Code of Conduct

By participating in this project, you agree to maintain a respectful and inclusive environment for all contributors.

## How to Contribute

### Reporting Issues

1. Check existing issues to avoid duplicates
2. Use the issue template if available
3. Provide clear description and steps to reproduce
4. Include system information (OS, compiler version)

### Submitting Changes

1. Fork the repository
2. Create a feature branch: `git checkout -b feature/your-feature`
3. Make your changes following the coding standards
4. Test your changes thoroughly
5. Commit with clear messages: `git commit -m "Add: feature description"`
6. Push to your fork: `git push origin feature/your-feature`
7. Submit a pull request

## Development Setup

```bash
git clone https://github.com/g-laliotis/atm-management-system.git
cd atm-management-system
make          # Build with text file storage
make sqlite   # Build with SQLite database (requires libsqlite3-dev)
make test     # Run comprehensive test suite
make run      # Run the application
```

## Coding Standards

- Follow C99 standard
- Use consistent indentation (4 spaces)
- Add comments for complex logic
- Ensure no compilation warnings with `-Wall -Wextra`
- **Run test suite**: `make test` must pass 100%
- Test all functionality before submitting
- Maintain modular code structure (separate concerns)
- Use meaningful variable and function names
- Handle errors gracefully with user-friendly messages

## Testing

### Automated Testing
- **Always run the test suite**: `make test`
- **Wait for CI workflows**: All GitHub Actions must pass
- Ensure all tests pass before submitting PR
- Add new tests for new functionality
- Test suite covers:
  - Password encryption/decryption
  - User registration and authentication
  - Account creation and management
  - Interest calculations
  - File operations and data validation
  - Notification system

### CI/CD Testing
- GitHub Actions automatically test on Ubuntu and macOS
- Both text file and SQLite builds are verified
- Security analysis runs automatically
- All workflows must pass before merge

### Manual Testing
- Test all features manually
- Verify no memory leaks
- Test edge cases and error conditions
- Test real-time notifications with multiple terminals
- Ensure backward compatibility
- Test both text file and SQLite modes

## Commit Message Format

Use clear, descriptive commit messages:
- `Add: new feature description`
- `Fix: bug description`
- `Update: modification description`
- `Remove: removal description`

## Pull Request Guidelines

- Provide clear description of changes
- Reference related issues
- **Ensure all tests pass**: `make test` must show 100% success
- **Wait for CI checks**: All GitHub Actions workflows must pass
- Update documentation if needed (README.md, FEATURES.md, etc.)
- Update CHANGELOG.md with your changes
- Keep changes focused and atomic
- Test both compilation modes (`make` and `make sqlite`)

## CI/CD Workflows

The project uses GitHub Actions for automation:

### Continuous Integration (CI)
- Runs on every push and pull request
- Tests on Ubuntu and macOS
- Builds both text file and SQLite versions
- Runs comprehensive test suite
- Checks for compilation warnings

### Security Analysis (CodeQL)
- Weekly automated security scans
- Runs on push/PR for security checks
- GitHub CodeQL analysis for vulnerabilities

### Automated Releases
- Triggers on version tags (v*)
- Creates release binaries automatically
- Generates release notes
- Uploads release assets

## Questions?

Feel free to open an issue for questions or discussions about contributing.