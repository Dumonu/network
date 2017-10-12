extern "C" {
#include "cudaOps.h"
#include "node.h"
}

__global__ //kernel
void cudaCalcLayerValues(struct Node** nodes, int size)
{
    int threadIndex = blockIdx.x * blockDim.x + threadIdx.x;

    while(threadIndex < size)
    {
        calcNodeValue(nodes[threadIndex]);
        threadIndex += blockDim.x * gridDim.x;
    }
    
}

extern "C"
void cudaCallCalcLayerKernel(const uint blockCount, const uint threadsPerBlock,
        struct Node** nodes, int size)
{
    cudaCalcLayerValues<<<blockCount, threadsPerBlock>>>(nodes, size);
}
