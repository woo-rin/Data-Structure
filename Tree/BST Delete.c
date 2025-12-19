#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

// 노드 생성 함수
Node* createNode(int item) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// 삭제 함수
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    // 삭제할 키 찾아 이동
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    
    // 3. 키를 찾음
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

        //  자식이 둘인 경우
        // 작은 값 가져오기
        Node* temp = minValueNode(root->right);
        
        // 값 복사
        root->key = temp->key;
        
        // 노드 삭제
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// 순회 출력
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d -> ", root->key);
        inorder(root->right);
    }
}

int main() {
    
    Node* root = createNode(50);
    
    // 왼쪽 서브트리 연결
    root->left = createNode(30);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    
    // 오른쪽 서브트리 연결
    root->right = createNode(70);
    root->right->left = createNode(60);
    root->right->right = createNode(80);

    inorder(root);
    printf("End\n\n");

    // 삭제 테스트
    printf("50 삭제 후:\n");
    root = deleteNode(root, 50);
    
    inorder(root);
    printf("End\n");

    return 0;
}