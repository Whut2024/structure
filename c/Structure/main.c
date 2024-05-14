#include <stdio.h>
#include "./B-Tree/b-tree.h"

int main() {
    Node *root = initNode(5);
    for (int i = 1; i < 11; ++i) {
        insert(&root, i);
    }
    printTree(root);
    return 0;
}
