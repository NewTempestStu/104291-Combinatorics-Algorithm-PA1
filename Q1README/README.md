# 104291-Combinatorics-Algorithm-PA1-Q1

## Introduction

This C program is designed to efficiently generate and display all possible subsets of an \(n\)-set, which is a set of the first \(n\) positive integers \(\{1, 2, ..., n\}\). The subsets are sorted first by their size (ascending order) and then lexicographically within subsets of the same size. This README guides you through the requirements, building, running, and understanding the program's output.

## Requirements

- **Operating System**: Linux or any Unix-like OS. Windows is also allowed.
- **Compiler**: GCC (GNU Compiler Collection) must be installed on your machine to compile the program.

## Setup Instructions

1. **Installation of GCC**: If GCC is not already installed, you can install it using your distribution's package manager. For example, on Ubuntu, you can install GCC by running `sudo apt-get install gcc` in the terminal. And for windows you can install MinGW.

2. **Downloading the Program**: Ensure that you have both the `order.c` source file and the `Makefile` in the same directory on your local machine. You can pull from github by the following url: `https://github.com/NewTempestStu/104291-Combinatorics-Algorithm-PA1`

## Compilation

This program comes with a Makefile for easy compilation. Here's how to use it:

1. **Open a Terminal**: Navigate to the directory containing your program files.

2. **Compile the Program**: Run the command `make` in your terminal. For Windows you should navigate to your `/bin` directory of MinGW and rename `mingw32-make` as `make.exe` first. This command instructs the make utility to compile the program according to the rules defined in the `Makefile`. It should generate an executable named `order` (`order.exe` for Windows).

## Running the Program

After compiling the program with `make`, run the executable by typing `./order` on Unix-like systems or `order` on Windows in your terminal or command prompt. The program presents a menu with several options:

1. **Generate and print all subsets/rank**: This option prompts you for the size of the set \(n\) and prints all subsets of the \(n\)-set along with their ranks.
2. **Find and print the rank of a given subset**: For a subset you provide, this option will print its rank within the sorted list of subsets.
3. **Find and print a subset given its rank**: Given a rank, this option displays the corresponding subset.
4. **Find and print the successor of a given subset**: This will print the immediate successor of a provided subset in the sorted list.
5. **Exit**: Terminates the program.

## Input

Depending on your selection, the program will prompt for further input:

- For generating subsets or finding a subset's rank, enter the size of the set \(n\).
- To find a subset's rank or its successor, you need to enter the size of the the set \(n\), the size of the subset and its elements.
- To find a subset by its rank, you need to enter the size of the the set \(n\) and the rank.

## Output

The program outputs depend on the selected option:

- **Generating subsets**: Lists all subsets along with their ranks, each enclosed in braces `{}` and separated by commas.
- **Finding a rank**: Shows the rank of the provided subset.
- **Finding a subset by rank**: Displays the subset corresponding to the provided rank.
- **Finding a successor**: Outputs the successor of the given subset.

## Example Usage and Output

```plaintext
Menu:
1. Generate and print all subsets/rank
2. Find and print the rank of a given subset
3. Find and print a subset given its rank
4. Find and print the successor of a given subset
5. Exit
Enter your choice: 1
Enter the size of the set (n): 3
Rank 0: {}
Rank 1: {1}
Rank 2: {2}
Rank 3: {3}
Rank 4: {1, 2}
Rank 5: {1, 3}
Rank 6: {2, 3}
Rank 7: {1, 2, 3}
```

## Cleaning Up

To remove the compiled executable and tidy up your directory, use the `make clean` command. This is compatible with both Windows and Unix-like systems, ensuring a clean workspace regardless of the operating system.

## Understanding the Output

- The output starts with the empty set `{}`, followed by subsets of increasing size.
- Subsets of the same size are sorted lexicographically. Each subset's rank indicates its position in this sorted list, starting from 0 for the empty set.

## License

- This project is licensed under the MIT License. See the LICENSE file in the project directory for more details.

## Contact Information

- For any questions, suggestions, or feedback, please contact `guan09236@gtiit.edu.cn`. Your input is highly appreciated and will help improve this program.

## Contributions

- Contributions to this project are welcome. If you'd like to contribute, please fork the repository and submit a pull request, or contact the email address above directly.