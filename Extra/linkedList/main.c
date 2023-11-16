#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>    




struct Node {
    int value;
    struct Node* next;
};

typedef struct Node node_t;




void printList(node_t *head){
    node_t *tmpCell = head;

    while(tmpCell !=NULL){
        printf("%d - ", tmpCell->value);
        tmpCell = tmpCell->next;
    }
    printf("\n");
}


node_t *create_new_node(int value){
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;

    return result;
}

void *insertAtHead(node_t **head, node_t *nodeToInsert){
    nodeToInsert->next =  *head;
    *head = nodeToInsert;
    return nodeToInsert;
}


node_t *findNode(node_t *head, int value){
    node_t *tmpCell = head;
    while (tmpCell !=NULL)
    {
        if(tmpCell->value == value) return tmpCell;
        tmpCell = tmpCell->next;
    }
    return NULL;
    
}


void insertAfterNode(node_t *nodeToInsertAfter, node_t *newNode){
    newNode->next = nodeToInsertAfter->next;
    nodeToInsertAfter->next = newNode;
}

int main(){
    
    node_t *head = NULL;
    node_t *tmp;

    for (int i = 0; i < 25; i++)
    {
        tmp = create_new_node(i);
        head = insertAtHead(&head,tmp);
    }

    tmp = findNode(head,13);
    printf("found node with value %d\n", tmp->value);
    insertAfterNode(tmp, create_new_node(75));
    printList(head);
    

  
    return 0;
}


