#include <stdio.h>
#include <stdlib.h>
typedef struct Node { //구조체 정의
    int data; // data넣는다
    struct Node *left;// node주소 연결
    struct Node *right;
    int key;
} Node;
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        exit(1); // 메모리 할당실패
    }
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* insert(Node* node, int key) {
    // 트리가 비어있거나, 잎(Leaf) 위치에 도달하면 새 노드 생성
    if (node == NULL) {
        return createNode(key);
    }

    // 현재 노드보다 작으면 왼쪽으로, 크면 오른쪽으로 이동
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }

    return node;
}
Node* search(Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return search(root->left, key);
    }
    return search(root->right, key);
}
void tree(Node* root) {
    if (root != NULL) {
        tree(root->left);
        printf("%d ", root->key);
        tree(root->right);
    }
}


int main() {
    Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // 데이터 탐색
    int searchKey = 40;
    Node* found = search(root, searchKey);

    if (found != NULL)
        printf("탐색 성공: %d\n", found->key);
    else
        printf("탐색 실패", searchKey);

    return 0;
}