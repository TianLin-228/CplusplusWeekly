//
// Created by Cu Cui on 2021/10/26.
//

#ifndef PARALLEL_TOOLS_H
#define PARALLEL_TOOLS_H




auto sum = [](auto x[], size_t s) {
    double sum = 0;
    for (int i=0; i<s; ++i) sum += x[i];
    return sum;
};


typedef struct Cell
{
    Cell(int i, bool b, const double x_[], const double y_[]) {
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

void print_cell(cell_t &cell)
{
    printf("Index: %d, flag: %d, sum x[]= %4.1f, sum y[]= %4.1f\n",
           cell.index, cell.flag, sum(cell.x, 4), sum(cell.y, 4));
}

template <typename T>
void print_vector(T vec, size_t n)
{
    for (int i=0; i<n; ++i)
        std::cout << vec[i] << ", ";
    std::cout << std::endl;
}

template <typename T>
void init(T &data, size_t n)
{
    for (int i=0; i<n; ++i)
        data[i] = i+1;
}

#endif //PARALLEL_TOOLS_H
