#pragma once
#include "my_array.h"
#include "co_num.h"

int get_int(int* n, int down, int up);
double get_double(double* n, double down, double up);
float get_float(float* n, float down, float up);
Array* fill_array_int(Array* array);
complex *get_complex();
Array* new_array(Array* res);

void print_menu();
