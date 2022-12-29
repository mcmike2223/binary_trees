#include <stdlib.h>
#include <stdio.h>

typedef struct binary_tree_s
{
    int value;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (tree == NULL) {
        return 0;
    }

    int is_complete = 1;
    binary_tree_t **queue = malloc(sizeof(binary_tree_t*) * 1000);
    if (queue == NULL) {
        return 0;
    }

    int head = 0;
    int tail = 0;

    queue[tail] = (binary_tree_t*)tree;
    tail++;

    while (head < tail) {
        binary_tree_t *node = queue[head];
        head++;

        if (node->left == NULL && node->right != NULL) {
            is_complete = 0;
            break;
        }

        if (node->left != NULL) {
            queue[tail] = node->left;
            tail++;
        }
        if (node->right != NULL) {
            queue[tail] = node->right;
            tail++;
        }
    }

    free(queue);

    return is_complete;
}
