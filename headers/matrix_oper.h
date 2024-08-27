#ifndef _MATRIX_OPERATIONS_H__
#define _MATRIX_OPERATIONS_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_triange_array (int array[], size_t array_size);

void print_matrix (char *matrix, size_t size_x, size_t size_y);

void insert_in_triange_matrix (char *matrix, int insert_val, size_t size_x, size_t size_y, size_t x, size_t y);

int *make_matrix (size_t size_x, size_t size_y);

int *make_triangle_matrix(size_t size_x, size_t size_y);

void make_and_draw_rhombus(size_t rhomb_size);

#endif //_MATRIX_OPERATIONS_H__
