#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

int main() {
    int n;
    scanf("%d", &n);

    Node **nodes = (Node **)malloc(n * sizeof(Node *));
    // node주소를 저장하기위해서 nodes에 저장한다
    // 노드 생성 및 데이터 입력
    // data에 입력 값들저장하고 위에 선언한 nodes를 통해서
    // node들의 주소값을 저장한다
    for (int i = 0; i < n; i++) {
        nodes[i] = (Node *)malloc(sizeof(Node));
        printf("%d", i + 1);
        scanf("%d", &nodes[i]->data);
        nodes[i]->left = NULL;
        nodes[i]->right = NULL;
    }

    // 완전이진트리 우리는 root가 1인 경우에서 인덱스의 위치를 찾아내는방법을
    //배웠기 떄문에 i를 0부터 증가하도록 했다.
    // 최초인 2*0+1 = 1이기때문에 1부터 시작한다.
    for (int i =0; i < n; i++) {
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;
        if (leftIndex < n)
            nodes[i]->left = nodes[leftIndex];
        if (rightIndex < n)
            nodes[i]->right = nodes[rightIndex];
    }

    // 루트 노드
    Node *root = nodes[0];

    // 결과 출력 (전위순회)
    printf("트리의 전위 순회 결과: ");
    void preorder(Node *node) {
        if (node == NULL) return;
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
    preorder(root);

    // 메모리 동적할당을 했었기 때문에 free를 통해서 메모리를 해져해야한다.
    for (int i = 0; i < n; i++) {
        free(nodes[i]);
    }
    free(nodes);

    return 0;
}
