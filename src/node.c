#include "node.h"

void calcNodeValue(struct Node* node)
{
    double sum = node->bias;
    for(int i = 0; i < node->prevSize; ++i)
    {
        sum += node->weights[i] * node->prevLayer[i]->value;
    }
    node->value = sum < 0 ? 0 : sum;
}
