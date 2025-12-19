#include <stdio.h>
#include <stdlib.h>

// 1. 노드 구조체 정의
typedef struct Node {
    int data;               // 데이터 저장
    struct Node* next;      // 다음 노드를 가리키는 포인터
} Node;

// 2. 새로운 노드 생성 함수 (메모리 할당)
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("메모리 할당 실패\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 3. 리스트 끝에 노드 추가 함수 (데이터 입력용)
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);

    // 리스트가 비어있다면 새 노드가 헤드가 됨
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // 마지막 노드까지 탐색
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    // 마지막 노드 뒤에 새 노드 연결
    current->next = newNode;
}

// 4. 역순 출력 함수 (핵심 로직)
// 재귀(Recursion)를 사용하여 리스트를 변경하지 않고 역순으로 출력합니다.
void printReverse(Node* head) {
    // 기저 조건(Base Case): 노드가 없으면 리턴 (재귀 종료)
    if (head == NULL) {
        return;
    }

    // 1. 먼저 다음 노드로 계속 들어갑니다 (재귀 호출)
    // 이 호출들이 스택(Stack)에 쌓이면서 리스트의 끝까지 이동합니다.
    printReverse(head->next);

    // 2. 재귀가 끝나고 돌아 나오면서 데이터를 출력합니다.
    // 가장 마지막에 호출된 함수(마지막 노드)부터 실행되므로 역순이 됩니다.
    printf("%d ", head->data);
}

// 5. 메모리 해제 함수 (프로그램 종료 전 정리)
void freeList(Node* head) {
    Node* current = head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
int main() {
    Node* head = NULL;  // 리스트의 시작점 (초기화 필수)
    int n, data;

    printf("생성할 노드의 개수를 입력하세요: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("%d번째 데이터를 입력하세요: ", i + 1);
        scanf("%d", &data);
        appendNode(&head, data);
    }

    printf("\n[저장된 데이터 역순 출력 결과]\n");
    printReverse(head); // 재귀함수 호출
    printf("\n");       // 줄바꿈

    freeList(head);

    return 0;
}