# pipex

This repository contains my implementation of the **pipex** project, developed as part of the 42 School curriculum. The aim of this project is to explore UNIX piping and file redirection by reproducing the behavior of the shell command:

```
< file1 cmd1 | cmd2 > file2
```

The project challenges you to create a C program that mimics this behavior using system calls. The code is written according to the strict Norm requirements of 42 School and is intended for educational and demonstration purposes only.

> **Note:** This project is strictly for educational purposes. Use of this code in academic submissions or by other students is prohibited by the 42 School regulations.

## Table of Contents

- [Overview](#overview)
- [Common Instructions](#common-instructions)
- [Mandatory Part](#mandatory-part)
  - [Program Behavior](#program-behavior)
  - [Requirements](#requirements)
  - [Examples](#examples)
- [Bonus Part](#bonus-part)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
  - [Basic Execution](#basic-execution)
  - [Bonus Features](#bonus-features)
- [Error Handling](#error-handling)
- [Submission and Peer Evaluation](#submission-and-peer-evaluation)
- [Acknowledgments](#acknowledgments)
- [Disclaimer](#disclaimer)
- [License](#license)

## Overview

The **pipex** project requires you to create a program that simulates the following shell behavior:

```
< file1 cmd1 | cmd2 > file2
```

Here, the program takes four command-line arguments:
- **file1:** The input file name.
- **cmd1:** The first command (with its parameters).
- **cmd2:** The second command (with its parameters).
- **file2:** The output file name.

Your program should open `file1`, pass its content through `cmd1`, pipe the output into `cmd2`, and finally write the resulting output to `file2`.

## Common Instructions

- **Language & Norm:** The project must be written in C and adhere strictly to the Norm.
- **Allowed Functions:** Only use the permitted functions, such as:
  - `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `access`, `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`, `wait`, and `waitpid`.
- **Makefile:** Makefile must compile source files with the flags `-Wall`, `-Wextra`, and `-Werror` using `cc` and must include at least the following rules: `NAME`, `all`, `clean`, `fclean`, and `re`. It must not perform unnecessary relinking.

## Mandatory Part

### Program Behavior

The program should be executed as follows:

```bash
./pipex file1 "cmd1" "cmd2" file2
```

It must behave like the shell command:

```
< file1 cmd1 | cmd2 > file2
```

### Requirements

- **Input and Output Files:**  
  - `file1` is the source of input.
  - `file2` is where the final output is written.
- **Commands:**  
  - `cmd1` and `cmd2` are the commands along with their arguments.
- **Robustness:**  
  - The program must handle errors gracefully (e.g., file access errors, command failures, etc.) by printing an error message using `perror` (or equivalent) and exiting appropriately (same behaviour as the shell about exit code and performing of the different commands).
  - All allocated memory must be properly freed to avoid memory leaks.
  - The program must not crash (e.g., segmentation faults or double frees).

### Examples

1. **Basic Usage:**

   ```sh
   $> ./pipex infile "ls -l" "wc -l" outfile
   ```

   This should behave exactly like:

   ```sh
   $> < infile ls -l | wc -l > outfile
   ```

2. **Another Example:**

   ```sh
   $> ./pipex infile "grep a1" "wc -w" outfile
   ```

   Which is equivalent to:

   ```sh
   $> < infile grep a1 | wc -w > outfile
   ```

## Bonus Part

For the bonus part it is required to implement the following bonus features:

### Multiple Pipes:

Extending the program to handle more than two commands. For example:

```sh
$> ./pipex infile "cmd1" "cmd2" "cmd3" ... "cmdn" outfile
```

This should mimic the behavior of:

```sh
$> < infile cmd1 | cmd2 | cmd3 ... | cmdn > outfile
```

### here_doc Support:

If the first argument is here_doc, implement here-document functionality. For example:

```sh
$> ./pipex here_doc LIMITER "cmd" "cmd1" outfile
```

This should behave like:

```sh
$> cmd << LIMITER | cmd1 >> outfile
```

## Project Structure

```
pipex/
├── includes/         # Header files (e.g., pipex.h)
├── srcs/             # C source files implementing the pipex program
├── Makefile          # Makefile with rules: NAME, all, clean, fclean, re and bonus
└── README.md         # This file
```

## Installation

1. **Clone the Repository:**

   ```sh
   git clone https://github.com/marco-ht/pipex.git
   cd pipex
   ```

2. **Build the Project:**

   Use the provided Makefile to compile the source files:

   ```sh
   make
   ```

   This command will produce the executable named pipex (as "make bonus" will produce pipex_bonus).

## Usage

### Basic Execution

To execute the program with two commands, use:

```sh
./pipex file1 "cmd1" "cmd2" file2
```

Example:

```sh
./pipex infile "ls -l" "wc -l" outfile
```

### Bonus Features

**Multiple Pipes:**

```sh
./pipex infile "cmd1" "cmd2" "cmd3" ... "cmdn" outfile
```

**here_doc Support:**

```sh
./pipex here_doc LIMITER "cmd" "cmd1" outfile
```

## Error Handling

- If there is an error opening file1 or file2, executing a command, or any system call fails, the program should output a descriptive error message (using perror) and exit, behaving like the shell.
- For example:
          ./pipex "nonexistingfile" "cat -e" "ls" "outfiles/outfile"
    will still perform "ls" and write its output on outfile as the shell would do (ls doesn't depend on cat -e output to perform so it can go through even if cat -e cannot be executed, exit code will report an error).
- The program must validate the number of arguments and the correctness of each argument (e.g., file existence, valid command format).
- I's required to ensure there are no memory leaks by freeing all allocated memory.

## Acknowledgments

- Many thanks to the 42 community, mentors, and peers for their guidance and support.
- Special thanks to the numerous resources available on UNIX programming, which have greatly assisted in understanding pipes and file redirection.

## Disclaimer

**IMPORTANT**:
This project was developed solely as part of the educational curriculum at 42 School. The code in this repository is published only for demonstration purposes to showcase my programming and system-level development skills.

**Academic Integrity Notice**:
It is strictly prohibited to copy or use this code as your own in academic submissions at 42 School. Any misuse will be considered a violation of 42 School's academic policies.

## License

This repository is licensed under the Creative Commons - NonCommercial-NoDerivatives (CC BY-NC-ND 4.0) license. You are free to share this repository as long as you:

- Provide appropriate credit.
- Do not use it for commercial purposes.
- Do not modify, transform, or build upon the material.

For further details, please refer to the CC BY-NC-ND 4.0 license documentation.

Developed with dedication and in strict adherence to the high standards of 42 School.
