#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

// 노드 생성
Node* createNode(int item) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// 높이 구하는 함수


// 2. 삽입 함수
Node* insert(Node* node, int key) {
    if (node == NULL) return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    
    return node;
}

// 최소값 찾기
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

//삭제 함수
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // 자식이 없거나 하나인 경우
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // 자식이 둘인 경우
        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// 트리 출력 (중위 순회)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice, key;

    while (1) {
        printf("\n--- BST 메뉴 ---\n");
        printf("1. 노드 삽입\n");
        printf("2. 노드 삭제\n");
        printf("3. 트리 높이 확인\n");
        printf("4. 현재 트리 출력 (중위 순회)\n");
        printf("0. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("삽입할 숫자: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("삭제할 숫자: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 3:
                // 높이 계산 호출
                printf("현재 트리의 높이: %d\n", getHeight(root));
                break;
            case 4:
                printf("트리 상태: ");
                inorder(root);
                printf("\n");
                break;
            case 0:
                printf("프로그램을 종료합니다.\n");
                // (실무에서는 여기서 전체 노드 free가 필요함)
                return 0;
            default:
                printf("잘못된 입력입니다.\n");
        }
    }
}