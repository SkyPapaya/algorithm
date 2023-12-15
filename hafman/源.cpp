#include <stdio.h>
#include <stdlib.h>

// �������ڵ�ṹ
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// �����½ڵ�
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ���������Ҷ������
int countLeaves(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1; // Ҷ���
    }
    return countLeaves(root->left) + countLeaves(root->right);
}

// ��������������
int countNodes(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// ��������ĸ߶�
int treeHeight(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

// ��������������������
void swapSubtrees(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // �ݹ齻����������
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    swapSubtrees(root->left);
    swapSubtrees(root->right);
}

int main() {
    // ����������
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // ���������Ҷ������
    printf("Ҷ������: %d\n", countLeaves(root));

    // ��������������
    printf("�������: %d\n", countNodes(root));

    // ��������ĸ߶�
    printf("�������ĸ߶�: %d\n", treeHeight(root));

    // ��������������������
    swapSubtrees(root);

    // �ͷŽڵ��ڴ�
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
    