#include <iostream>
#include <mpi.h>
#include <unistd.h>
#include <string>
#include "time_experiment.hh"

typedef struct Cell
{
    Cell(int i, bool b, double x_[], double y_[]) {
        index = i;
        flag = b;
        for (int j=0; j<4; ++j) {
            x[j] = x_[j];
            y[j] = y_[j];
        }
    }
    Cell() = default;;
    int index{};
    bool flag{};
    double x[4]{};
    double y[4]{};

} cell_t;

void print_cell(cell_t &cell);

template <typename T, typename U>
void do_something(T data, U val);

template <>
void do_something(int* data, int val)
{
    std::cout << "Rank [" << val << "] is doing sth. ...\n";
    sleep(1);
}

template <>
void do_something(cell_t &data, double & val)
{
    print_cell(data);
    sleep(1);
}


void creat_cell_datatype(MPI_Datatype &new_type)
{
    int length[4] = {1, 1, 4, 4};
    MPI_Aint displacements[4];
    cell_t dummy_cell;

    // calculate displacement
    MPI_Aint base_adress;
    MPI_Get_address(&dummy_cell, &base_adress);
    MPI_Get_address(&dummy_cell.index, &displacements[0]);
    MPI_Get_address(&dummy_cell.flag, &displacements[1]);
    MPI_Get_address(&dummy_cell.x, &displacements[2]);
    MPI_Get_address(&dummy_cell.y, &displacements[3]);
    for (int i=0; i<4; i++)
        displacements[i] = MPI_Aint_diff(displacements[i], base_adress);

    MPI_Datatype types[4] = { MPI_INT, MPI_C_BOOL, MPI_DOUBLE, MPI_DOUBLE};
    MPI_Type_create_struct(4, length, displacements, types, &new_type);
    MPI_Type_commit(&new_type);
}

auto sum = [](auto x[], size_t s) {
    double sum = 0;
    for (int i=0; i<s; ++i) sum += x[i];
    return sum;
};

void print_cell(cell_t &cell)
{
    printf("Index: %d, flag: %d, sum x[]= %4.1f, sum y[]= %4.1f\n",
           cell.index, cell.flag, sum(cell.x, 4), sum(cell.y, 4));
}

int main(int argc, char **argv)
{
    int size, rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

//    auto start = get_time_stamp();
//    do_something(&rank, rank);
//    auto stop = get_time_stamp();
//    double elapsed = get_duration_seconds(start, stop);
//    std::cout << rank << " : " << elapsed << std::endl;

    /* init data */
    const int N = 1 << 10;
    int A[N];
    double B[N];
    double x[4], y[4];

    for (int i=0; i<4; i++) {
        x[i] = rank + 1;
        y[i] = x[i] * x[i];
    }

    cell_t cell {rank, static_cast<bool>(rank%2), x, y};
    if (rank == 0) std::cout << "Init ... \n";
    print_cell(cell);

    MPI_Datatype cell_type;
    creat_cell_datatype(cell_type);

    /* blocking send & recv */
    MPI_Barrier(MPI_COMM_WORLD);
    cell_t buffer{};
    double val = 0;
    if (rank == 0) std::cout << "Cycling ... \n";
    const int P = 1;
    for (int round = 0; round < P; ++round) {


        if (rank % 2) {
            MPI_Send(&cell, 1, cell_type, (rank + 1) % size, 0, MPI_COMM_WORLD);
            MPI_Recv(&buffer, 1, cell_type, (rank + size - 1) % size, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            cell.index = buffer.index;
            do_something(cell, val);
        } else {
            MPI_Recv(&buffer, 1, cell_type, (rank + size - 1) % size, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            MPI_Send(&cell, 1, cell_type, (rank + 1) % size, 0, MPI_COMM_WORLD);
            cell.index = buffer.index;
            do_something(cell, val);
        }

    }
    print_cell(cell);

    /*  Isend Irecv  */
//    MPI_Isend()
    MPI_Finalize();
}