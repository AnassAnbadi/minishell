# 🐚 Minishell

A minimal Unix shell implementation written in C, recreating the behavior of bash with essential features and built-in commands.

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Shell Script](https://img.shields.io/badge/shell_script-%23121011.svg?style=for-the-badge&logo=gnu-bash&logoColor=white)
![42](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)

## 📋 Table of Contents

- [About](#about)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Built-in Commands](#built-in-commands)
- [Project Structure](#project-structure)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## 🎯 About

Minishell is a simplified shell implementation that mimics the behavior of bash. This project is part of the 42 School curriculum and focuses on understanding:

- Process creation and management
- File descriptor handling
- Signal processing
- Command parsing and execution
- Environment variable management
- Built-in command implementation

## ✨ Features

### Core Functionality
- ✅ **Command Execution** - Execute system commands and programs
- ✅ **Built-in Commands** - Implementation of essential shell built-ins
- ✅ **Environment Variables** - Full environment variable support
- ✅ **Signal Handling** - Proper handling of Ctrl+C, Ctrl+D, and Ctrl+\\
- ✅ **Command History** - Navigate through command history
- ✅ **Pipes** - Support for command piping (`|`)
- ✅ **Redirections** - Input/output redirection (`<`, `>`, `>>`)
- ✅ **Quote Handling** - Support for single and double quotes
- ✅ **Variable Expansion** - Environment variable expansion (`$VAR`)

### Advanced Features
- 🔄 **Logical Operators** - Support for `&&` and `||`
- 🔄 **Wildcards** - Basic wildcard expansion (`*`)
- 🔄 **Here Documents** - Support for `<<` operator

## 🚀 Installation

### Prerequisites
- GCC compiler
- Make
- Unix-like operating system (Linux, macOS)

### Build Instructions

1. **Clone the repository**
   ```bash
   git clone https://github.com/AnassAnbadi/minishell.git
   cd minishell
   ```

2. **Compile the project**
   ```bash
   make
   ```

3. **Run minishell**
   ```bash
   ./minishell
   ```

### Makefile Targets

- `make` or `make all` - Compile the project
- `make clean` - Remove object files
- `make fclean` - Remove object files and executable
- `make re` - Recompile the entire project

## 🖥️ Usage

After compilation, start minishell:

```bash
./minishell
```

You'll see the minishell prompt:
```
minishell$ 
```

### Basic Commands

```bash
minishell$ ls -la
minishell$ pwd
minishell$ echo "Hello, World!"
minishell$ cat file.txt
```

### Using Pipes

```bash
minishell$ ls -la | grep minishell
minishell$ cat file.txt | wc -l
```

### Redirections

```bash
minishell$ echo "Hello" > output.txt
minishell$ cat < input.txt
minishell$ ls >> log.txt
```

### Environment Variables

```bash
minishell$ echo $HOME
minishell$ export MY_VAR="Hello World"
minishell$ echo $MY_VAR
```

## 🔧 Built-in Commands

| Command | Description | Usage |
|---------|-------------|-------|
| `echo` | Display text | `echo [-n] [text...]` |
| `cd` | Change directory | `cd [directory]` |
| `pwd` | Print working directory | `pwd` |
| `export` | Set environment variables | `export [VAR=value]` |
| `unset` | Unset environment variables | `unset [VAR]` |
| `env` | Display environment variables | `env` |
| `exit` | Exit the shell | `exit [status]` |

### Built-in Command Examples

```bash
# Echo with newline suppression
minishell$ echo -n "Hello World"

# Change directory
minishell$ cd /home/user
minishell$ cd ..
minishell$ cd

# Export and unset variables
minishell$ export PATH="/usr/local/bin:$PATH"
minishell$ export DEBUG=1
minishell$ unset DEBUG

# Exit with status code
minishell$ exit 0
```

## 📁 Project Structure

```
minishell/
├── builtins/           # Built-in command implementations
│   ├── echo.c
│   ├── cd.c
│   ├── pwd.c
│   ├── export.c
│   ├── unset.c
│   ├── env.c
│   └── exit.c
├── environ/            # Environment variable management
│   ├── env_utils.c
│   └── env_operations.c
├── execution/          # Command execution logic
│   ├── executor.c
│   ├── pipes.c
│   └── redirections.c
├── libft/              # Custom C library
│   └── [libft files]
├── parsing/            # Command parsing and tokenization
│   ├── lexer.c
│   ├── parser.c
│   └── expander.c
├── tools/              # Utility functions
│   ├── utils.c
│   └── cleanup.c
├── main.c              # Main program entry point
├── minishell.h         # Header file with declarations
├── Makefile            # Build configuration
└── README.md           # Project documentation
```

## 💡 Examples

### Complex Command Examples

```bash
# Multiple pipes
minishell$ ls -la | grep "\.c$" | wc -l

# Redirections with pipes
minishell$ cat file.txt | grep "pattern" > results.txt

# Environment variable expansion
minishell$ echo "Current user: $USER, Home: $HOME"

# Command substitution with quotes
minishell$ echo 'Single quotes preserve $HOME'
minishell$ echo "Double quotes expand $HOME"

# Logical operators
minishell$ ls file.txt && echo "File exists"
minishell$ ls nonexistent.txt || echo "File not found"
```

### Error Handling

Minishell handles various error conditions gracefully:

```bash
# Command not found
minishell$ nonexistentcommand
minishell: nonexistentcommand: command not found

# Permission denied
minishell$ ./no_permission_file
minishell: ./no_permission_file: Permission denied

# Syntax errors
minishell$ ls |
minishell: syntax error near unexpected token 'newline'
```

## 🧪 Testing

To test minishell functionality:

1. **Basic Commands**
   ```bash
   ./minishell
   minishell$ echo "Testing basic functionality"
   minishell$ pwd
   minishell$ ls
   ```

2. **Built-ins**
   ```bash
   minishell$ export TEST_VAR="Hello"
   minishell$ echo $TEST_VAR
   minishell$ unset TEST_VAR
   minishell$ env | grep TEST_VAR
   ```

3. **Pipes and Redirections**
   ```bash
   minishell$ echo "test" | cat
   minishell$ echo "output" > test.txt
   minishell$ cat test.txt
   ```

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📝 Notes

- This project follows the 42 School coding standards (Norminette)
- Memory leaks are handled and prevented using proper cleanup
- Signal handling ensures graceful termination
- Error messages match bash behavior for compatibility

## 🏆 42 Project Information

- **Project**: minishell
- **Language**: C
- **Allowed functions**: Limited set of system calls and library functions
- **Forbidden**: Using other shells or command interpreters

## 📄 License

This project is part of the 42 School curriculum. Feel free to use it for educational purposes.

---

**Made with  by [AnassAnbadi](https://github.com/AnassAnbadi)**

*"The shell is the user's interface to the operating system"*
```

This comprehensive README provides:

1. **Clear project overview** with badges and description
2. **Detailed feature list** with checkmarks for implemented features
3. **Step-by-step installation** instructions
4. **Usage examples** for different shell features
5. **Built-in commands documentation** with examples
6. **Project structure** explanation
7. **Testing guidelines** and examples
8. **Contributing guidelines** for collaboration
9. **42 School context** and requirements

The documentation is well-structured, visually appealing with emojis and formatting, and provides everything someone would need to understand, build, and use your minishell project.

