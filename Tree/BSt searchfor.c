#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        exit(1);// 메모리 할당 실패
    }
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//반복문 삽입 함수
void insert(Node** root, int key) {
    Node* newNode = createNode(key);

    // 트리가 비어있으면 루트에 연결
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    Node* current = *root; // 루트 노드 포인터
    Node* parent = NULL;   // 부모 노드 포인터

    //  들어갈 위치 찾기
    while (current != NULL) {
        parent = current; // 현재 노드를 부모로 설정긔고 이동

        if (key < current->key) {
            current = current->left;
        } else if (key > current->key) {
            current = current->right;
        } else {
            // 메모리 해제
            free(newNode);
            return;
        }
    }

    //부모 노드의 자식으로 새 노드 연결
    if (key < parent->key) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

//  반복문 탐색 함수
Node* search(Node* root, int key) {
    Node* current = root;

    // NULL이 아닐 때까지 반복
    while (current != NULL) {
        if (key == current->key) {
            return current; // 0
        } else if (key < current->key) {
            current = current->left; // 왼쪽이동
        } else {
            current = current->right; // 오른쪽이동
        }
    }
    return NULL; // 못 찾음
}

// 출력용 중위 순회 (여기는 재귀 유지)
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main() {// 이중 포인터를 사용하여 root 자체를 변경 가능하게 해야함
    Node* root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    printf("트리 출력 (중위 순회): ");
    inorderTraversal(root);
    printf("\n");

    // 반복문 탐색 테스트
    int searchKey = 60;
    Node* found = search(root, searchKey);

    if (found != NULL)
        printf("탐색 성공: %d\n", found->key);
    else
        printf("탐색 실패\n");

    return 0;
}