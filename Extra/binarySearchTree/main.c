#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>    

typedef struct treeNode{

    int value;
    struct treeNode *left;
    struct treeNode *right;

}treeNode;


treeNode *createNode(int value){
    treeNode* result = malloc(sizeof(treeNode));

    if(result !=NULL){
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}



void printTabs(int numTabs){
    for(int i=0; i < numTabs; i++){
        printf("\t");
    }
}

void printTree_rec(treeNode *root, int level){
    if(root == NULL){
        printTabs(level);
        printf("empty tree\n");
        return;
    }
    printTabs(level);
    printf("value = %d\n", root->value);

    printTabs(level);
    printf("left\n");
    printTree_rec(root->left, level+1);

    printTabs(level);
    printf("right\n");
    printTree_rec(root->right, level+1);

    printTabs(level);
    printf("Done\n");

}

void printTree(treeNode *root){
    printTree_rec(root,0);
}


void insert(){

    
}


bool insertNumber(treeNode **rootPtr, int value){
    treeNode *root = *rootPtr;
    if(root==NULL){
        //tree empty
        (*rootPtr) = createNode(value);
        return true;
    }
    if(value == root->value){
        //do nothing
        return false;
    }
    if(value< root->value){
        //look left side of tree
        return insertNumber(&(root->left),value);
    }else{
        return insertNumber(&(root->right),value);
    }
}



bool findNumber(treeNode *root, int value){
    if(root == NULL ) return false;
    if(root->value==value) return true;

    if(value < root->value){
        return findNumber(root->left,value);
    }else{
        return findNumber(root->right,value);
    }
}

int main(){
    treeNode *root = NULL;

    insertNumber(&root,15);
    insertNumber(&root,11);
    insertNumber(&root,24);
    insertNumber(&root,5);
    insertNumber(&root,19);
    insertNumber(&root,16);

    printTree(root);

    printf("%d (%d)\n", 16, findNumber(root,16));
    printf("%d (%d)\n", 16, findNumber(root,15));
    printf("%d (%d)\n", 16, findNumber(root,5));
    printf("%d (%d)\n", 16, findNumber(root,115));
    printf("%d (%d)\n", 16, findNumber(root,1));
    


    return 0;
}


