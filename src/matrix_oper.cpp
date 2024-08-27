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

void draw_rhombus(size_t rhomb_size)
{
    int n_left = rhomb_size / 2;
    int n_right = 0;
    while(n_left >= 0)
    {
        for(size_t i = 0; i < n_left; i++)
        {
            printf(" ");
        }
        printf("%d", 1);
        for(size_t i = 0; i < n_right; i++)
        {
            printf("  ");
        }
        if(n_right > 0)
        {
            printf("%d", 1);
        }

        printf("\n");
        n_left--;
        n_right++;
    }

    n_left = 1;
    n_right = rhomb_size / 2 - 1;
    while(n_left <= rhomb_size / 2)
    {
        for(size_t i = 0; i < n_left; i++)
        {
            printf(" ");
        }

        printf("%d", 1);
        for(size_t i = 0; i < n_right; i++)
        {
            printf("  ");
        }
        if(n_right > 0)
        {
            printf("%d", 1);
        }

        printf("\n");
        n_left++;
        n_right--;
    }
}

void draw_circle(double R)
{
    int n_left = 1, n_right=1;
    double step = 3 / R;
    double x = 1;
    while(x < 2.5)
    {
        n_left = round(R / (x * x * sqrt(x)));
        n_right = R - n_left;
        for(size_t k = 0; k < n_left; k++)
        {
            printf(" ");
        }
        printf("%d", 1);
        for(size_t k = 0; k < n_right; k++)
        {
            printf("  ");
        }
        printf("%d\n", 1);

        x = x + step;
    }

    x = 2.5;
    while(x > 0.8)
    {
        n_left = round(R / (x * x * sqrt(x)));
        n_right = R - n_left;
        for(size_t k = 0; k < n_left; k++)
        {
            printf(" ");
        }
        printf("%d", 1);
        for(size_t k = 0; k < n_right; k++)
        {
            printf("  ");
        }
        printf("%d\n", 1);

        x = x - step;
    }
}
