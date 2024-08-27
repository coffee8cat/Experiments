#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrix_oper.h"

void print_triange_array (int array[], size_t array_size)
{
    size_t elems_in_line = 1;
    size_t count_elems_in_line = 0;

    for(size_t i = 0; i < array_size; i++)
    {
        printf("%d ", *(array + i));
        count_elems_in_line++;

        if(count_elems_in_line == elems_in_line)
        {
            printf("\n");
            elems_in_line++;
            count_elems_in_line = 0;
        }
    }
}

void print_matrix (char *matrix, size_t size_x, size_t size_y)
{
    for(size_t x = 0; x < size_x; x++)
    {
        for(size_t y = 0; y < size_y; y++)
        {
            printf("%d ", *(matrix + x * sizeof(int) * size_y + y * sizeof(int)));
        }
        printf("\n");
    }
}

void insert_in_triange_matrix (char *matrix, int insert_val, size_t size_x, size_t size_y, size_t x, size_t y)
{
    if(x >= y)
    {
        *(matrix + x * sizeof(int) * size_y + y * sizeof(int)) = insert_val;
    }
    else
    {
        *(matrix + y * sizeof(int) * size_y + x * sizeof(int)) = insert_val;
    }
}

int *make_matrix (size_t size_x, size_t size_y)
{
    int *matrix = (int*)calloc(size_x * size_y, sizeof(int));

    for(size_t x = 0; x < size_x; x++)
    {
        for(size_t y = 0; y < size_y; y++)
        {
            *(matrix + x * size_y + y) = rand();
        }
    }

    return matrix;
}


int *make_triangle_matrix(size_t size_x, size_t size_y)
{
    int *matrix = (int*)calloc(size_x * size_y, sizeof(int));

    for(size_t x = 0; x < size_x; x++)
    {
        for(size_t y = 0; y < x; y++)
        {
            *(matrix + x * size_y + y) = rand();
        }
    }

    return matrix;
}

void make_and_draw_rhombus(size_t rhomb_size)
{
    int *matrix = (int *)calloc(rhomb_size * rhomb_size, sizeof(int));
    size_t y = rhomb_size / 2;
    printf("%d\n", y);
    for(size_t x = 0; x <= rhomb_size / 2; x++)
    {
        *(matrix + x * rhomb_size + (y + x)) = 1;
        *(matrix + x * rhomb_size + (y - x)) = 1;
    }
    for(size_t x = 0; x <= rhomb_size / 2; x++)
    {
        *(matrix + (x + rhomb_size / 2) * rhomb_size + rhomb_size - x - 1) = 1;
        *(matrix + (x + rhomb_size / 2) * rhomb_size + x) = 1;
    }

    print_matrix((char *)matrix, rhomb_size, rhomb_size);
}
