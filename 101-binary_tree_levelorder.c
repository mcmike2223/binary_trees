#include <stdlib.h>
#include <stdio.h>

typedef struct binary_tree_s
{
    int value;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL) {
        return;
    }

    binary_tree_t **queue = malloc(sizeof(binary_tree_t*) * 1000);
    if (queue == NULL) {
        return;
    }

    int head = 0;
    int tail = 0;

    queue[tail] = (binary_tree_t*)tree;
    tail++;

    while (head < tail) {
        binary_tree_t *node = queue[head];
        head++;

        func(node->value);

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
}
