#ifndef CUDA_OPS_H_
#define CUDA_OPS_H_

#include <cuda_runtime.h>

void cudaCallCalcLayerKernel(const uint blockCount, const uint threadsPerBlock,
        struct Node** nodes, int size);

#endif
