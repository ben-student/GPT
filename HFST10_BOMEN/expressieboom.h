#ifndef EXPRESSIEBOOM_H
#define EXPRESSIEBOOM_H

struct expressionnode_t
{
    int value;
    char operator;
    char isoperator;
    struct expressionnode_t *left;
    struct expressionnode_t *right;
};


typedef struct expressionnode_t ExpressionNode;

ExpressionNode *createNumberNode(int value);
ExpressionNode *createOperatorNode(char operator);
int evaluateExpressionTree(ExpressionNode *root);
void freeExpressionTree(ExpressionNode *root);
void printInorder(ExpressionNode* root);


#endif
