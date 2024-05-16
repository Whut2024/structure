//
// Created by 20213 on 2024/5/14.
//

#ifndef STRUCTURE_B_TREE_H
#define STRUCTURE_B_TREE_H

#include <stdlib.h>
#include <stdio.h>

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


/**
 * 递归打印树
 * @param root 根节点
 */
void printTree(Node *root) {
    if (root == NULL) return;

    for (int i = 1; i <= root->keyNum; ++i) {
        printf("%d ", root->keys[i]);
    }

    printf("\n");

    for (int i = 0; i < root->childrenNum; ++i) {
        printTree(root->children[i]);
    }
}

void freeTree(Node *root) {
    if (root == NULL) return;

    for (int i = 0; i < root->childrenNum; ++i) {
        freeTree(root->children[i]);
    }

    for (int i = 0; i < root->keyNum; ++i) {
        freeTree(root);
    }
}

// 初始化B树节点
Node *initNode(int level) {
    Node *node = (Node *) malloc(sizeof(Node));

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
int findSuitIndex(Node *node, int data) {
    if (node == NULL) return 0;

    int left = 1, right = node->keyNum;
    int middle, resIndex = 0;
    while (left <= right) {
        middle = (left + right) >> 1;
        if (node->keys[middle] >= data) {
            resIndex = middle;
            right = middle - 1;
        } else left = middle + 1;
    }

    return resIndex ? resIndex : left;
}

// 找到合适插入的叶子节点
Node *findSuitLeaf(Node *node, int data) {
    if (node == NULL) return NULL;

    // 判断子节点情况
    if (!node->childrenNum) {
        return node;
    } else {
        int suitIndex = findSuitIndex(node, data);
        return findSuitLeaf(node->children[suitIndex - 1], data);
    }
}

/**
 * 插入数据
 * @param node 数据准备插入的节点
 * @param data 要插入的数据
 * @param root 树的根节点
 */
void addData(Node *node, int data, Node **root) {


    // 合适插入位置
    int suitIndex = findSuitIndex(node, data);

    // 迈开步子, 腾出位置
    for (int i = node->keyNum; i > suitIndex; i--) node->keys[i] = node->keys[i - 1];

    // 插入
    node->keys[suitIndex] = data;
    node->keyNum++;

    // 分裂情况
    int level = node->level;

    // 直接结束
    if (node->keyNum < node->level) return;

    Node *left = initNode(level);
    Node *right = initNode(level);

    // 分裂点
    int middle = level / 2 + level % 2;
    // 新左右子节点数据注入(注入keys数据)
    for (int i = 1; i < middle; ++i) {
        addData(left, node->keys[i], root);
    }
    for (int i = middle + 1; i <= level; ++i) {
        addData(right, node->keys[i], root);
    }

    // 新左右子节点的子节点数据注入
    // 新左右子节点的子节点的父节点数据注入
    for (int i = 0; i < middle; ++i) {
        left->children[i] = node->children[i];
        if (node->children[i] != NULL) {
            left->childrenNum++;
            node->children[i]->father = left;
        }
    }
    for (int i = middle; i < node->childrenNum; ++i) {
        right->children[i - middle] = node->children[i];
        if (node->children[i] != NULL) {
            right->childrenNum++;
            node->children[i]->father = right;
        }
    }


    // 上浮中间节点
    if (node->father == NULL) {
        // 当前节点为根节点
        Node *newFather = initNode(level);

        newFather->children[0] = left;
        newFather->children[1] = right;
        left->father = newFather;
        right->father = newFather;

        newFather->childrenNum = 2;
        addData(newFather, node->keys[middle], root);

        // 重置根节点
        *root = newFather;
    } else {
        // 当前节点不为根节点
        Node *father = node->father;

        // 确定节点上浮的索引位置
        suitIndex = findSuitIndex(father, node->keys[middle]);
        father->children[suitIndex - 1] = left;

        // 左右子节点确认
        if (father->children[suitIndex] != NULL) {
            for (int i = father->childrenNum; i > suitIndex; i--) {
                father->children[i] = father->children[i - 1];
            }
        }
        father->children[suitIndex] = right;

        // 父节点 子节点对接
        left->father = father;
        right->father = father;

        father->childrenNum++;

        addData(father, node->keys[middle], root);
    }

    // 清除多余内存
    free(node);
}

/**
 * 依据根节点和要插入的数据进行插入
 * @param root 根节点
 * @param data 插入数据
 */
void insert(Node **root, int data) {
    Node *node = findSuitLeaf(*root, data);
    addData(node, data, root);
}


void deleteKeyOnLeaf(Node* node, int toDeletedIndex) {
    // 删除
    for (int i = toDeletedIndex; i < node->keyNum; ++i) {
        node->keys[i] = node->keys[i + 1];
    }
    node->keyNum--;


    // 关键字充足
    if (node->keyNum >= (node->level / 2 + node->level % 2)) return;
    

}

// 删除节点


#endif //STRUCTURE_B_TREE_H
