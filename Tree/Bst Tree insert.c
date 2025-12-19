#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

// 생성 함수
Node* createNode(int item) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// 삽입 함수 재귀
Node* insert(Node* node, int key) {
    // 트리가 비어있거나, 리프로드에 도달했을 때
    if (node == NULL) 
        return createNode(key);

    // 중복된 값X
    if (key == node->key)
        return node;

    // 왼쪽으로 이동
    if (key < node->key)
        node->left = insert(node->left, key);
    
    // 오른쪽으로 이동
    else if (key > node->key)
        node->right = insert(node->right, key);

    // 노드 포인터 반환
    return node;
}

//  정렬 확인 중위 순회
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);       // 왼쪽
        printf("%d -> ", root->key); // 루트(출력)
        inorder(root->right);      // 오른쪽
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

    printf(" 트리 삽입 결과\n");
    inorder(root);
    printf("End\n");

    return 0;
}