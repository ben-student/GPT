
#include <stdio.h>
#include <stdlib.h>

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

int main(){
    treeNode *n1 = createNode(10);
    treeNode *n2 = createNode(11);
    treeNode *n3 = createNode(12);
    treeNode *n4 = createNode(13);
    treeNode *n5 = createNode(14);
    treeNode *n6 = createNode(15);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;




    printTree(n1);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);



    return 0;
}


