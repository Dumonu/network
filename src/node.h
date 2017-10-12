#ifndef NODE_H_
#define NODE_H_

#include <cuda_runtime.h>

struct Node
{
    double value;
    double bias;
    double *weights;
    int prevSize;
    struct Node **prevLayer;
};

__host__ __device__
void calcNodeValue(struct Node* node);

#endif
