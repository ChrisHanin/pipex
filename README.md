*This project has been created as part of the 42 curriculum by chanin.*

# pipex

## Description
pipex is a Unix pipeline recreation project in C.

The goal is to reproduce shell-like behavior for command chaining with pipes and redirections, using low-level system calls such as fork, pipe, dup2, execve, and waitpid.

Core objectives:
- Process creation and execution
- File descriptor redirection
- Command path resolution via PATH
- Multi-command pipeline logic (bonus)

## Instructions
### Prerequisites
- Linux environment
- cc
- make

### Build mandatory
```bash
make
```

### Build bonus
```bash
make bonus
```

### Run mandatory
```bash
./pipex infile "cmd1" "cmd2" outfile
```

Example:
```bash
./pipex infile "grep hello" "wc -l" outfile
```

### Run bonus
```bash
./pipex_bonus infile "cmd1" "cmd2" "cmd3" ... outfile
```

Here_doc mode (bonus, if implemented):
```bash
./pipex_bonus here_doc LIMITER "cmd1" "cmd2" outfile
```

### Clean
```bash
make clean
make fclean
make re
```

## Resources
### Documentation
- pipe(2): https://man7.org/linux/man-pages/man2/pipe.2.html
- fork(2): https://man7.org/linux/man-pages/man2/fork.2.html
- dup2(2): https://man7.org/linux/man-pages/man2/dup.2.html
- execve(2): https://man7.org/linux/man-pages/man2/execve.2.html
- waitpid(2): https://man7.org/linux/man-pages/man2/waitpid.2.html
- access(2): https://man7.org/linux/man-pages/man2/access.2.html

### Learning references
- Shell pipelines overview: https://www.gnu.org/software/bash/manual/
- Process and FD model basics: https://man7.org/linux/man-pages/man7/unix.7.html

### AI Usage
AI tools were used for:
- README writing and structure
- Documentation readability checks
- Review note organization

AI was used as documentation support, not as a replacement for implementation understanding or validation.
