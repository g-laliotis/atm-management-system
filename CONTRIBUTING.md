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
make          # Text file storage
make sqlite   # SQLite database (requires libsqlite3-dev)
```

## Coding Standards

- Follow C99 standard
- Use consistent indentation (4 spaces)
- Add comments for complex logic
- Ensure no compilation warnings with `-Wall -Wextra`
- Test all functionality before submitting

## Testing

- Test all features manually
- Verify no memory leaks
- Test edge cases and error conditions
- Ensure backward compatibility

## Commit Message Format

Use clear, descriptive commit messages:
- `Add: new feature description`
- `Fix: bug description`
- `Update: modification description`
- `Remove: removal description`

## Pull Request Guidelines

- Provide clear description of changes
- Reference related issues
- Ensure all tests pass
- Update documentation if needed
- Keep changes focused and atomic

## Questions?

Feel free to open an issue for questions or discussions about contributing.