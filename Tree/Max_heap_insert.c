#include <stdio.h>
#include <stdlib.h>
#define Max_num 100

typedef struct{
    int key;
}num;

typedef struct {
    num heap[Max_num];
    int heap_size;
}node;

node* create() { // create라는 함수를 만들어서 구조체 선언후 동적메모리 할당
    return (node*)malloc(sizeof(node));
}

void init(node* h) { // init이라는 함수를 만들어서 heap_size를 초기화 한다
    h->heap_size = 0;
}

void insert_Maxheap(node* h, num item) {
    int i;
    // 힙 크기를 증가시키고, i를 새로 삽입될 항목의 마지막노드로 설정합니다.
    i = ++(h->heap_size);

    while ((i != 1) && (item.key > h->heap[i/2].key)) {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

int main(void){
    num n1={10}, n2={20}, n3={30};
    node* heap;

    heap = create();
    init(heap);

    insert_Maxheap(heap,n1);
    insert_Maxheap(heap,n2);
    insert_Maxheap(heap,n3);

    free(heap);

    return 0;
}