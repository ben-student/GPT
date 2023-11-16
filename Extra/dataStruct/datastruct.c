#include <stdio.h>
#include <stdlib.h>
#include "datastruct.h"

struct Node{
    int data;
    struct Node *Next;
};

void printList(struct Node* head) {
    struct Node* current = head->Next;
    while (current != NULL) {
        printf("%c -> ", current->data);
        current = current->Next;
    }
    printf("NULL\n");
}

int IsLast(Position P, List L) {
    return P->Next == NULL;
}


List CreateList(){
    List L;
    L = (struct Node*)malloc(sizeof(struct Node));
    if(L == NULL){
        perror("Out of mem!");
    }
    L->Next = NULL;
    return L;
}

Position FindPrevious(int X, List L){
    Position P;
    P = L;
    while (P->Next !=NULL && P->Next->data != X)
    P = P->Next;
    return P;
}

void Delete(int X, List L){
    Position P, TmpCell;
    P = FindPrevious(X,L);
    if(!IsLast(P,L)){
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }else P->Next = NULL;
}

void Insert(int X, List L, Position P) {
    Position TmpCell;

    TmpCell = (struct Node*)malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        perror("Out of memory");
        exit(EXIT_FAILURE); // Handle the error gracefully
    }

    TmpCell->data = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}
