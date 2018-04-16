#include <stdio.h>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>

#define NUM 10

__global__ void averagePx(int * a, int * c)
{
    int width = blockIdx.x;

    printf("w: %d\n", width);

    if(width < NUM*NUM) {
        c[width] = a[width] / 2;
    }

}

int main ()
{
    int a[NUM][NUM], c[NUM*NUM];
    int change_a[NUM*NUM];
    int *de_a, *de_c;

    // 이미지의 값을 넣어 준다. 지금은 내 임의로 넣는다.
    int gap = 0;
    for (int i = 0; i < NUM; ++i) {
        for (int j = 0; j < NUM; ++j) {
            a[i][j] = 5 * 10;
            change_a[gap] = a[i][j];
            printf("a[%d][%d] = %d\n", i, j, a[i][j]);
            printf("gap[%d] = %d\n", gap, change_a[gap]);
            ++gap;
        }
    }

    // 이미지를 일차원으로 바꿔준다.


    cudaMalloc((void**)&de_a, sizeof(int) * NUM*NUM);
    cudaMalloc((void**)&de_c, sizeof(int) * NUM*NUM);

    cudaMemcpy(de_a, change_a, sizeof(int) * NUM*NUM, cudaMemcpyHostToDevice);

    averagePx <<<100, 1>>> (de_a, de_c);

    cudaMemcpy(c, de_c, sizeof(int) * NUM*NUM, cudaMemcpyDeviceToHost);

    for (int i = 0; i < NUM*NUM; ++i) {
            printf("a(%d) = c(%d)\n", change_a[i], c[i]);
    }

    cudaFree(de_a);
    cudaFree(de_c);

    getchar();
    return 0;

}