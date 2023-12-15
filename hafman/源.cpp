#include <stdio.h>
#include <stdlib.h>

// 二叉树节点结构
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 创建新节点
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 求二叉树中叶结点个数
int countLeaves(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1; // 叶结点
    }
    return countLeaves(root->left) + countLeaves(root->right);
}

// 求二叉树结点总数
int countNodes(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// 求二叉树的高度
int treeHeight(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

// 交换二叉树的左右子树
void swapSubtrees(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // 递归交换左右子树
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    swapSubtrees(root->left);
    swapSubtrees(root->right);
}

int main() {
    // 创建二叉树
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // 求二叉树中叶结点个数
    printf("叶结点个数: %d\n", countLeaves(root));

    // 求二叉树结点总数
    printf("结点总数: %d\n", countNodes(root));

    // 求二叉树的高度
    printf("二叉树的高度: %d\n", treeHeight(root));

    // 交换二叉树的左右子树
    swapSubtrees(root);

    // 释放节点内存
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
    