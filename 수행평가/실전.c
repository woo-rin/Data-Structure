#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node*next;
}Node;

Node*createNode(int data) {
    Node*node = (Node*)malloc(sizeof(Node));
    if (node==NULL) {
        printf("구조 활당실패");
        exit(1);
    }
    node -> data = data;
    node -> next = NULL;
    return node;
}
Node*appendNode(Node**head,int data) {
    Node* newnode = createNode(data);
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    Node*current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newnode;
}
