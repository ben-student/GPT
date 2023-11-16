#include <stdio.h>
#include <stdlib.h>
#include "expressieboom.h"

int main() {
      // Voorbeeld: (3 + 2) * 4

    ExpressionNode *root = createOperatorNode('*');
    root->left = createOperatorNode('+');
    root->right = createNumberNode(4);

    root->left->left = createNumberNode(3);
    root->left->right = createNumberNode(2);

    int result = evaluateExpressionTree(root);
    printInorder(root);
    printf("Resultaat: %d\n", result);

    freeExpressionTree(root);

    return 0;
}
