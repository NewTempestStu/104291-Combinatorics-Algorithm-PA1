# 104291-Combinatorics-Algorithm-PA1-Q2

## Introduction

This Python script allows users to generate, analyze, and manipulate 2-colored permutations of a set. It provides functionalities for generating all 2-colored permutations of a specified length, finding the successor of a given permutation, determining the rank of a permutation, and finding a permutation by its rank.

## Features

- **Generate All 2-Colored Permutations**: Outputs all possible permutations of a set with each element colored in two possible colors (0 or 1) along with their ranks.
- **Find Successor**: Given a permutation, finds and displays the next permutation in lexicographical order.
- **Permutation Rank**: Calculates and returns the rank of a specified permutation.
- **Find Permutation by Rank**: Retrieves and displays a permutation based on its rank in the order of all permutations.

## Prerequisites

- Python 3.6 or higher

## Installation

No additional libraries are required beyond the Python Standard Library. Simply download the script to your local machine.

## How to Run

Navigate to the directory containing the script and run it using Python. For example:

```bash
python3 main.py
```

Once the script is running, you will be presented with a menu of options:

```plaintext
Menu:
1. Generate all 2-colored permutations of length n and display their ranks
2. Find the successor of a given 2-colored permutation
3. Find a permutation given its rank
4. Find the rank of a given permutation
5. Exit
```

## Using the Script

- **Option 1**: Enter '1' to generate all 2-colored permutations. You will be prompted to enter the size of the permutation set (n). The script will then display all permutations along with their ranks.
- **Option 2**: Enter '2' to find the successor of a permutation. You will need to provide the size of the permutation followed by the permutation itself in the format `(value,color)`.
- **Option 3**: Enter '3' if you want to find a permutation by its rank. You will need to specify the size of the permutations and then the rank.
- **Option 4**: Enter '4' to calculate the rank of a given permutation. Similar to option 2, you will provide the permutation details.
- **Option 5**: Enter '5' to exit the program.

## Example Usage

```plaintext
Enter your choice: 1
Enter the size of the permutation (n): 3
Rank: 0 - (1,0) (2,0) (3,0)
Rank: 1 - (1,0) (2,0) (3,1)
...
```

## License

- This project is licensed under the MIT License. See the LICENSE file in the project directory for more details.

## Contact Information

- For any questions, suggestions, or feedback, please contact `guan09236@gtiit.edu.cn`. Your input is highly appreciated and will help improve this program.

## Contributions

- Contributions to this project are welcome. If you'd like to contribute, please fork the repository and submit a pull request, or contact the email address above directly.
