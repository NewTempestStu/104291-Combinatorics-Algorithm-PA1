# 104291-Combinatorics-Algorithm-PA1-Q1

## Introduction

This C program is designed to efficiently generate and display all possible subsets of an \(n\)-set, which is a set of the first \(n\) positive integers \(\{1, 2, ..., n\}\). The subsets are sorted first by their size (ascending order) and then lexicographically within subsets of the same size. This README guides you through the requirements, building, running, and understanding the program's output.

## Requirements

- **Operating System**: Linux or any Unix-like OS.
- **Compiler**: GCC (GNU Compiler Collection) must be installed on your machine to compile the program.

## Setup Instructions

1. **Installation of GCC**: If GCC is not already installed, you can install it using your distribution's package manager. For example, on Ubuntu, you can install GCC by running `sudo apt-get install gcc` in the terminal.

2. **Downloading the Program**: Ensure that you have both the `order.c` source file and the `Makefile` in the same directory on your local machine. You can pull from github by the following url: `https://github.com/NewTempestStu/104291-Combinatorics-Algorithm-PA1-Q1`

## Compilation

This program comes with a Makefile for easy compilation. Here's how to use it:

1. **Open a Terminal**: Navigate to the directory containing your program files.

2. **Compile the Program**: Run the command `make` in your terminal. This command instructs the make utility to compile the program according to the rules defined in the `Makefile`. It should generate an executable named `order`.

## Running the Program

- **Execute the Program**: After compilation, you can run the program by typing `./order` in your terminal.
- **Input**: The program will prompt you to enter a single integer \(n\), which represents the size of the \(n\)-set. Enter a positive integer and press Enter.
- **Output**: The program will print all subsets of the \(n\)-set sorted by size and then lexicographically. Each subset is displayed in braces `{}`, with subset elements separated by commas.

## Example Usage and Output

```
Enter the size of the set (n): 3
{ } {1} {2} {3} {1, 2} {1, 3} {2, 3} {1, 2, 3}
```

## Cleaning Up

- **Remove Executable**: You can clean up the directory by running `make clean`. This command removes the compiled executable, keeping your directory tidy.

## Understanding the Output

- The output begins with the empty set `{ }`, followed by subsets of increasing size.
- Subsets of the same size are sorted lexicographically, which means they appear in numerical order based on their elements.

## License

- This project is licensed under the MIT License. See the LICENSE file in the project directory for more details.

## Contact Information

- For any questions, suggestions, or feedback, please contact `guan09236@gtiit.edu.cn`. Your input is highly appreciated and will help improve this program.

## Contributions

- Contributions to this project are welcome. If you'd like to contribute, please fork the repository and submit a pull request, or contact the email address above directly.