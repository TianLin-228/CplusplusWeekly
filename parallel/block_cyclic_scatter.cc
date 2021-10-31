//
// Created by Cu Cui on 2021/10/30.
//

#include <iostream>
#include <mpi.h>
#include <memory>

#include "tools.h"

const int N = 32;
const int B = 8;

int main()
{
    int size, rank;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    const int block_num = N/B;
    const int block_per_rank = block_num/size;
    const int n_per_rank = block_per_rank * B;

    double* A;
    double* a;

    a = new double[n_per_rank];
    for (int i=0; i<n_per_rank; ++i)
        a[i] = 0.;

    if (rank == 0){
        A = new double[N];

        for (int i=0; i<N; ++i)
            A[i] = i;
        print_vector(A, N);
    }

    for (int i=0; i<B; ++i)
        MPI_Scatter(&A[i*block_num], block_per_rank, MPI_DOUBLE, &a[i*block_per_rank],
                    block_per_rank, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    print_vector(a, n_per_rank);

    MPI_Finalize();

}