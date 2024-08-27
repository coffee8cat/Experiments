#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "matrix_oper.h"

int main()
{
    srand(time(NULL));

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_triange_array(array, sizeof(array)/sizeof(array[0]));

    printf("\n");

    int matrix[5][4] = {
    {11, 12, 13, 14},
    {21, 22, 23, 24},
    {31, 32, 33, 34},
    {41, 42, 43, 44},
    {51, 52, 53, 54}};

    print_matrix((char *)matrix, sizeof(matrix)/sizeof(matrix[0]), sizeof(matrix[0])/sizeof(matrix[0][0]));

    int triangle_matrix[4][4] = {
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1}};

    int ins = 99;
    int x = 1, y = 3;

    insert_in_triange_matrix((char *)triangle_matrix, ins, sizeof(triangle_matrix)/sizeof(triangle_matrix[0]),
                             sizeof(triangle_matrix[0])/sizeof(triangle_matrix[0][0]), x, y);
    printf("Insert %d on %d %d\n", ins, x, y);
    print_matrix((char *)triangle_matrix, 4, 4);


    ins = 99;
    x = 2, y = 1;
    insert_in_triange_matrix((char *)triangle_matrix, ins, sizeof(triangle_matrix)/sizeof(triangle_matrix[0]),
                             sizeof(triangle_matrix[0])/sizeof(triangle_matrix[0][0]), x, y);
    printf("Insert %d on %d %d\n", ins, x, y);
    print_matrix((char *)triangle_matrix, 4, 4);

    printf("----------\n");
    const int size_x = 5;
    const int size_y = 7;

    int *matrix_ptr = make_matrix(size_x, size_y);
    print_matrix((char *)matrix_ptr, size_x, size_y);

    printf("----------\n");

    matrix_ptr = make_triangle_matrix(size_x, size_y);
    print_matrix((char *)matrix_ptr, size_x, size_y);


    printf("----------\n");
    make_and_draw_rhombus(11);
    return EXIT_SUCCESS;
}
