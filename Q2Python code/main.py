from itertools import permutations, chain
import math

def print_permutation(perm):
    print(' '.join(f"({x[0]},{x[1]})" for x in perm))

def generate_all_2_colored_permutations(n):
    base_perm = list(permutations(range(1, n+1)))
    for perm in base_perm:
        for colors in range(1 << n):
            yield [(perm[i], (colors >> i) & 1) for i in range(n)]

def find_successor(perm):
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
    n = len(perm)
    perms = list(chain.from_iterable(
        [[(p[i], (c >> i) & 1) for i in range(n)] for c in range(1 << n)]
        for p in permutations(range(1, n + 1))
    ))
    return perms.index(perm)

def find_permutation_by_rank(n, rank):
    perms = list(chain.from_iterable(
        [[(p[i], (c >> i) & 1) for i in range(n)] for c in range(1 << n)]
        for p in permutations(range(1, n + 1))
    ))
    if rank >= len(perms):
        return None
    return perms[rank]

def get_valid_permutation_input(n):
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
