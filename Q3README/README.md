# 104291-Combinatorics-Algorithm-PA1-Q3

## Introduction

This C program generates all possible binary search trees (BSTs) for a given set of integer keys provided by the user. Each tree is printed in an ASCII representation that illustrates the structure of the BST.

## Requirements

- **Operating System**: Linux or any Unix-like OS. Windows is also allowed.
- **Compiler**: GCC (GNU Compiler Collection) must be installed on your machine to compile the program.

## Setup Instructions

1. **Installation of GCC**: If GCC is not already installed, you can install it using your distribution's package manager. For example, on Ubuntu, you can install GCC by running `sudo apt-get install gcc` in the terminal. And for windows you can install MinGW.

2. **Downloading the Program**: Ensure that you have both the `main.c` source file and the `Makefile` in the same directory on your local machine. You can pull from github by the following url: `https://github.com/NewTempestStu/104291-Combinatorics-Algorithm-PA1`

## Compilation

This program comes with a Makefile for easy compilation. Here's how to use it:

1. **Open a Terminal**: Navigate to the directory containing your program files.

2. **Compile the Program**: Run the command `make` in your terminal. For Windows you should navigate to your `/bin` directory of MinGW and rename `mingw32-make` as `make.exe` first. This command instructs the make utility to compile the program according to the rules defined in the `Makefile`. It should generate an executable named `main` (`main.exe` for Windows).

## Running the Program

Execute the compiled program by entering the following command:

```sh
./main // On Unix-like systems
main  // On Windows. If this fails just enter `./main` as the same in Linux
```

The program will prompt you to input the number of keys and then each key individually.

## Program Output

The output is an ASCII representation of each possible BST generated from the provided keys. Trees are displayed with connections between nodes to represent their structure visually in the terminal.

## Example Usage and Output

```plaintext
Enter the number of keys: 3
Enter the keys: 1 2 3
(001)                                                                           
  +----+                                                                        
     (002)                                                                      
       +----+                                                                   
          (003)                                                                 
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
(001)                                                                           
  +---------+                                                                   
          (003)                                                                 
       +----+                                                                   
     (002)                                                                      
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
     (002)                                                                      
  +----+----+                                                                   
(001)     (003)                                                                 
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
     (002)                                                                      
  +----+----+                                                                   
(001)     (003)                                                                 
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
          (003)                                                                 
       +----+                                                                   
     (002)                                                                      
  +----+                                                                        
(001)                                                                           
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
          (003)                                                                 
  +---------+                                                                   
(001)                                                                           
  +----+                                                                        
     (002)                                                                      
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                

```

The example above shows one of several possible BSTs that could be generated with the keys 1, 2, and 3.

## Cleaning Up

To remove the compiled executable and tidy up your directory, use the `make clean` command. This is compatible with both Windows and Unix-like systems, ensuring a clean workspace regardless of the operating system.

## Understanding the Output

The ASCII art of the BST will reflect the structure of the binary search tree as if drawn horizontally on your terminal.

## Contributions

Contributions are welcome! If you have suggestions or improvements, feel free to fork the repository and submit a pull request.

## License

This project is open-sourced under the MIT License.

## Contact Information

For inquiries or support, please reach out to `guan09236@gtiit.edu.cn`.
