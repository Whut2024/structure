//
// Created by 20213 on 2024/5/14.
//

#ifndef STRUCTURE_B_TREE_H
#define STRUCTURE_B_TREE_H

#include <stdlib.h>

// B树结构体
typedef struct Node {
    // 关键字数组
    int *keys;

    // 孩子数组
    struct Node **children;

    // 关键字个数
    int keyNum;

    // 孩子个数
    int childrenNum;

    // 父节点
    struct Node *father;

    // 阶数
    int level;
} Node;

// 初始化B树节点
Node *initNode(int level) {
    Node *node = (Node *) malloc(sizeof(Node *));

    node->keys = (int *) malloc(sizeof(int) * (level + 1));
    node->keyNum = 0;

    node->children = (Node **) malloc(sizeof(Node *) * (level + 1));
    node->childrenNum = 0;

    node->father = NULL;
    node->level = level;

    // 初始化值
    for (int i = 0; i < level + 1; ++i) {
        node->keys[i] = 0;
        node->children[i] = NULL;
    }

    return node;
}

// 找到合适插入点索引(大于data最小值)
int findSuitIndex(Node *root, int data) {
    if (root == NULL) return 0;

    int left = 1, right = root->keyNum;
    int middle, resIndex;
    while (left <= right) {
        middle = (left + right) >> 1;
        if (root->keys[middle] >= data) {
            resIndex = middle;
            right = middle - 1;
        } else left = middle + 1;
    }

    return resIndex;
}

// 找到合适插入的叶子节点
Node *findSuitLeaf(Node* root, int data) {
    if (root == NULL) return NULL;

    // 判断子节点情况
    if (!root->childrenNum) {
        return root;
    } else {
        int suitIndex = findSuitIndex(root, data);
        return findSuitLeaf(root->children[suitIndex - 1], data);
    }
}

/**
 * 插入数据
 * @param root 数据准备插入的节点
 * @param data 要插入的数据
 * @param father 插入节点的父节点
 */
void insert(Node* root, int data, Node** father) {
    int suitIndex = findSuitIndex(root, data);

    // 迈开步子, 腾出位置
    for (int i = root->keyNum; i > suitIndex; i--) root->keys[i] = root->keys[i - 1];

    // 插入
    root->keys[suitIndex] = data;
    root->keyNum++;

    // 分裂情况
    int level = root->level;
    if (root->keyNum == root->level) {
        Node* left = initNode(level);
        Node* right = initNode(level);

        // 新子节点转移
        int middle = level / 2 + level % 2;
        for (int i = 1; i < middle; ++i) {
            insert(left, root->keys[i], father);
        }
        for (int i = middle + 1; i <= level; ++i) {
            insert(right, root->keys[i], father);
        }

        // 旧子节点转移
        for (int i = 0; i < middle; ++i) {
            left->children[i] = root->children[i];
            if (root->children[i] != NULL) {
                root->children[i]->father = left;
            }
        }
        for (int i = middle + 1; i < root->childrenNum; ++i) {
            right->children[i - middle - 1] = root->children[i];
            if (root->children[i] != NULL) {
                root->children[i]->father = right;
            }
        }
    }
}


#endif //STRUCTURE_B_TREE_H
