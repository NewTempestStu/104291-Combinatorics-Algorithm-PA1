#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tnode {
    int val;
    struct tnode *left;
    struct tnode *right;
} tnode;

// Function to create a new tree node
tnode* new_node(int val) {
    tnode* node = (tnode*)malloc(sizeof(tnode));
    if (node != NULL) {
        node->val = val;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

// Function to insert a new value into a BST
tnode* insert(tnode* node, int val) {
    // Return a new node if the tree is empty
    if (node == NULL) return new_node(val);

    // Otherwise, recursively insert into the left or right subtree
    if (val < node->val) {
        node->left = insert(node->left, val);
    } else if (val > node->val) {
        node->right = insert(node->right, val);
    }

    // Return the (unchanged) node pointer
    return node;
}

// Function to free the memory of a BST
void free_tree(tnode* node) {
    if (node == NULL) return;
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

int _print_t(tnode *tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[20];
    int width = 5;

    if (!tree) return 0;

    sprintf(b, "(%03d)", tree->val);

    int left  = _print_t(tree->left,  1, offset,                depth + 1, s);
    int right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
    for (int i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[depth - 1][offset - width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';
    }
#else
    for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }
#endif

    return left + width + right;
}

void print_t(tnode *tree)
{
    char s[20][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(tree, 0, 0, 0, s);

    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}

// Function to print an array of integers
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to generate all permutations of a set of keys
void permute_and_print(int *array, int start, int end) {
    if (start == end) {
        tnode* root = NULL;
        for (int i = 0; i <= end; i++) {
            root = insert(root, array[i]);
        }
        print_t(root);
        free_tree(root);
        return;
    }

    for (int i = start; i <= end; i++) {
        // Swap the current index with the start
        int temp = array[start];
        array[start] = array[i];
        array[i] = temp;

        // Recursively permute the rest of the array
        permute_and_print(array, start + 1, end);

        // Swap back
        temp = array[start];
        array[start] = array[i];
        array[i] = temp;
    }
}

int main() {
    int numberOfKeys;
    printf("Enter the number of keys: ");
    scanf("%d", &numberOfKeys);
    
    int* keys = (int*)malloc(numberOfKeys * sizeof(int));
    if (keys == NULL) {
        perror("Failed to allocate memory for keys");
        return EXIT_FAILURE;
    }

    printf("Enter the keys: ");
    for (int i = 0; i < numberOfKeys; ++i) {
        scanf("%d", &keys[i]);
    }

    permute_and_print(keys, 0, numberOfKeys - 1); // Generate all BSTs and print them

    free(keys); // Don't forget to free the allocated memory
    return 0;
}
