#include <stdio.h>
#include <stdlib.h>
#include "expressieboom.h"

void printInorder(ExpressionNode* root) {
    if (root == NULL)
        return;

    if (root->isoperator == 'n')
    {
        printf("%d ", root->value);
    }
    else
    {
        printf("(");
        printInorder(root->left);
        printf("%c ", root->operator);
        printInorder(root->right);
        printf(")");
    }
}

ExpressionNode *createNumberNode(int value)
{
    ExpressionNode *node = (ExpressionNode *)malloc(sizeof(ExpressionNode));
    if (node)
    {
        node->value = value;
        node->isoperator = 'n';
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

ExpressionNode *createOperatorNode(char operator)
{
    ExpressionNode *node = (ExpressionNode *)malloc(sizeof(ExpressionNode));
    if (node)
    {
        node->operator = operator;
        node->isoperator = 'y';
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

int evaluateExpressionTree(ExpressionNode *root)
{
    if (root == NULL)
    {
        fprintf(stderr, "De expressieboom is leeg.\n");
        return 0;
    }

    if (root->isoperator == 'n')
    {
        return root->value;
    }

    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    switch (root->operator)
    {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            if (rightValue != 0)
                return leftValue / rightValue;
            else
            {
                fprintf(stderr, "Fout: Deling door nul.\n");
                exit(EXIT_FAILURE);
            }
        default:
            fprintf(stderr, "Fout: Ongeldige operator: %c\n", root->operator);
            exit(EXIT_FAILURE);
    }
}

void freeExpressionTree(ExpressionNode *root)
{
    if (root == NULL)
        return;

    freeExpressionTree(root->left);
    freeExpressionTree(root->right);
    free(root);
}