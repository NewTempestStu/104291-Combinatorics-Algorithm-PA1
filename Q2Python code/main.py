from itertools import permutations, chain
import math

def print_permutation(perm):
    """
    Prints a permutation with its associated colors in a readable format.

    Args:
    perm (list of tuples): Each tuple contains an element of the permutation and its color.

    Example:
    Input: [(1,0), (2,1), (3,0)]
    Output: (1,0) (2,1) (3,0)
    """
    print(' '.join(f"({x[0]},{x[1]})" for x in perm))

def generate_all_2_colored_permutations(n):
    """
    Generates all possible 2-colored permutations of size n.

    Args:
    n (int): The size of the set from which permutations are generated.

    Yields:
    list of tuples: Each tuple contains an integer and a binary value representing the color.

    Explanation:
    - Generates permutations of the numbers 1 to n.
    - For each permutation, generates all possible color combinations using binary representation.
    """
    base_perm = list(permutations(range(1, n+1)))
    for perm in base_perm:
        for colors in range(1 << n):  # 2^n color combinations
            yield [(perm[i], (colors >> i) & 1) for i in range(n)]

def find_successor(perm):
    """
    Finds the lexicographical successor of a given permutation.

    Args:
    perm (list of tuples): The current permutation.

    Returns:
    list of tuples: The next permutation in lexicographic order or None if it is the last permutation.

    Explanation:
    - Generates all possible 2-colored permutations.
    - Finds the current permutation in the list and returns the next one.
    """
    n = len(perm)
    all_perms = list(chain.from_iterable(
        [[(p[i], (c >> i) & 1) for i in range(n)] for c in range(1 << n)]
        for p in permutations(range(1, n + 1))
    ))
    try:
        current_index = all_perms.index(perm)
        if current_index == len(all_perms) - 1:
            return None  # This is the last permutation
        return all_perms[current_index + 1]
    except ValueError:
        return None

def permutation_rank(perm):
    """
    Determines the rank of a given permutation among all 2-colored permutations.

    Args:
    perm (list of tuples): The permutation whose rank is to be found.

    Returns:
    int: The rank of the permutation.

    Explanation:
    - Generates all permutations and finds the index of the given permutation.
    """
    n = len(perm)
    perms = list(chain.from_iterable(
        [[(p[i], (c >> i) & 1) for i in range(n)] for c in range(1 << n)]
        for p in permutations(range(1, n + 1))
    ))
    return perms.index(perm)

def find_permutation_by_rank(n, rank):
    """
    Retrieves a permutation by its rank among all 2-colored permutations.

    Args:
    n (int): Size of the permutation.
    rank (int): The rank to find the permutation for.

    Returns:
    list of tuples: The permutation corresponding to the given rank or None if out of bounds.
    """
    perms = list(chain.from_iterable(
        [[(p[i], (c >> i) & 1) for i in range(n)] for c in range(1 << n)]
        for p in permutations(range(1, n + 1))
    ))
    if rank >= len(perms):
        return None
    return perms[rank]

def get_valid_permutation_input(n):
    """
    Gets a valid permutation input from the user, ensuring proper format and values.

    Args:
    n (int): The expected size of the permutation.

    Returns:
    list of tuples: A valid permutation entered by the user.
    """
    while True:
        input_str = input(f"Enter the permutation elements for size {n} (e.g., '1,0 2,1 3,0'): ")
        try:
            perm = [(int(x.split(',')[0]), int(x.split(',')[1])) for x in input_str.split()]
            if len(perm) != n or not all(1 <= p[0] <= n and p[1] in [0, 1] for p in perm):
                raise ValueError("Invalid permutation elements or colors.")
            return perm
        except (ValueError, IndexError):
            print("Invalid input format. Please ensure your input matches the expected format.")

def main():
    """
    Main function to interactively test permutation functionalities.

    Allows the user to:
    - Generate and view all 2-colored permutations along with their ranks.
    - Find the successor of a given permutation.
    - Retrieve a permutation by its rank.
    - Find the rank of a given permutation.
    - Exit the program.
    """
    while True:
        print("\nMenu:")
        print("1. Generate all 2-colored permutations of length n and display their ranks")
        print("2. Find the successor of a given 2-colored permutation")
        print("3. Find a permutation given its rank")
        print("4. Find the rank of a given permutation")
        print("5. Exit")
        choice = input("Enter your choice: ")

        try:
            choice = int(choice)
        except ValueError:
            print("Please enter a valid number.")
            continue

        if choice == 1:
            n = int(input("Enter the size of the permutation (n): "))
            for perm in generate_all_2_colored_permutations(n):
                rank = permutation_rank(perm)
                print(f"Rank: {rank} -", end=' ')
                print_permutation(perm)
        elif choice == 2:
            n = int(input("Enter the size of the permutation: "))
            perm = get_valid_permutation_input(n)
            successor = find_successor(perm)
            if successor:
                print("Successor permutation:")
                print_permutation(successor)
            else:
                print("No successor found.")
        elif choice == 3:
            n = int(input("Enter the size of the permutations (n): "))
            rank = int(input("Enter the rank: "))
            perm = find_permutation_by_rank(n, rank)
            if perm:
                print("Permutation for rank:")
                print_permutation(perm)
            else:
                print("Invalid rank or permutation does not exist.")
        elif choice == 4:
            n = int(input("Enter the size of the permutation: "))
            perm = get_valid_permutation_input(n)
            rank = permutation_rank(perm)
            print(f"The rank of the given permutation is: {rank}")
        elif choice == 5:
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please enter a number between 1 and 5.")

if __name__ == "__main__":
    main()
