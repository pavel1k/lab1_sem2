#include "menu.h"
#include "co_num.h"
#include "my_array.h"
#include "tests.h"


void my_sum_int(int* val) {
    int t;
    printf("sum element with\n");
    scanf_s("%d", &t);
    *val = *val + t;
    return val;
}

void my_sum_float(float* val) {
    int t;
    printf("sum element with\n");
    scanf_s("%d", &t);
    *val = *val + t;
}

void my_sum_double(double* val) {
    int t;
    printf("sum element with\n");
    scanf_s("%d", &t);
    *val = *val + t;
}

void my_mult_int(int* val) {
    int t;
    printf("multiply element on\n");
    scanf_s("%d", &t);
    *val = *val * t;
}

void my_mult_float(float* val) {
    int t;
    printf("multiply element on\n");
    scanf_s("%d", &t);
    *val = *val * t;
}
void my_mult_double(double* val) {
    int t;
    printf("multiply element on\n");
    scanf_s("%d", &t);
    *val = *val * t;
}
bool less_int(int* a, int* b)
{
    return  *a < *b;
}
bool less_float(float* a, float* b)
{
    return  *a < *b;
}
bool less_double(double* a, double *b)
{
    return  *a < *b;
}
int get_int(int* n, int down, int up) {
    int k = (down == 0 && up == 0) ? 0 : 1;
    int err, num;

    do {
        err = scanf_s("%d", &num);
        if (err < 0) {
            exit(0);
        }
        if ((num < down || num > up) && k) {
            err = 0;
            printf("Sorry, you are wrong. Please try again:\n::");
        }
    } while (err <= 0);

    if (n != NULL)
        *n = num;

    return num;
}

double get_double(double* n, double down, double up) {
    int k = (down == 0 && up == 0) ? 0 : 1;
    int err;
    double num;

    do {
        err = scanf_s("%lf", &num);
        if (err < 0) {
            exit(0);
        }
        if ((num < down || num > up) && k) {
            err = 0;
            printf("Sorry, you are wrong. Please try again:\n::");
        }
    } while (err <= 0);

    if (n != NULL)
        *n = num;

    return num;
}

float get_float(float* n, float down, float up) {
    int k = (down == 0 && up == 0) ? 0 : 1;
    int err;
    float num;

    do {
        err = scanf_s("%f", &num);
        if (err < 0) {
            exit(0);
        }
        if ((num < down || num > up) && k) {
            err = 0;
            printf("Sorry, you are wrong. Please try again:\n::");
        }
    } while (err <= 0);

    if (n != NULL)
        *n = num;

    return num;
}

complex* get_complex() {
    printf("put real part: ");
    float a = get_float(NULL, 0, 0);
    printf("put complex part: ");
    float b = get_float(NULL, 0, 0);
    complex* res = new_complex(a, b);
    return res;
}

Array* fill_array_int(Array* array) {
    int t;
    
    for (array->count = 1; array->count <= array->_allocated; array->count += 1) {
        printf("put the element\n");
        t = get_int(NULL, 0, 0);
        if (!array_set(array, array->count - 1, &t))
            return false;

    }
    array->count -= 1;
    return array;
}


Array* fill_array_float(Array* array) {
    float t;
    
    for (array->count = 1; array->count <= array->_allocated; array->count += 1) {
        printf("put the element\n");
        t = get_float(NULL, 0, 0);
        if (!array_set(array, array->count - 1, &t))
            return false;

    }
    array->count -= 1;
    return array;
}

Array* fill_array_double(Array* array) {
    double t;
    
    for (array->count = 1; array->count <= array->_allocated; array->count += 1) {
        printf("put the element\n");
        t = get_double(NULL, 0, 0);
        if (!array_set(array, array->count - 1, &t))
            return false;

    }
    array->count -= 1;
    return array;
}

Array* fill_array_complex(Array* array) {
    complex *t;
    
    for (array->count = 1; array->count <= array->_allocated; array->count += 1) {
        printf("put the element\n");
        t = get_complex(NULL, 0, 0);
        if (!array_set(array, array->count - 1, &t))
            return false;

    }
    array->count -= 1;
    return array;
}
void print_menu() {
    printf("choose action:\n"
        "\t1: change array\n"
        "\t2: print array\n"
        "\t3: delete array\n"
        "\t4: test\n"
        "\t5: exit\n"
        "put the number: ");
}
void print_menu_change() {
    printf("choose action:\n"
        "\t1: to sum up with \n"
        "\t2: to multiply on \n"
        "\t3: sort \n"
        "\t4: push element in the end \n"
        "\t5: pop the last element \n"
        "\t6: exit \n"
        "put the number: ");
}

Array* new_array(Array* res) {
    int n, m, s, l, k, i, t;
    float f;
    double d;
    printf("choose array:\n "
        "\t1: integer array\n"
        "\t2: float array\n"
        "\t3: double array\n"
        "\t4: complex array\n:");
    get_int(&n, 1, 4);
    

    switch (n) {
    case 1: fill_array_int(res);
        do {
            print_menu();
            scanf_s("%d", &m);
            if (m > 5 || m < 1) {
                printf("Sorry, you are wrong. Please try again: ");
                continue;
            }
            if (m == 5) break;
            switch (m) {
            case 1: do {
                print_menu_change();
                scanf_s("%d", &s);
                if (s > 6 || s < 1) {
                    printf("Sorry, you are wrong. Please try again: ");
                    continue;
                }
                if (s == 6) break;
                switch (s) {
                case 1: array_map(res, my_sum_int); break;
                case 2: array_map(res, my_mult_int); break;
                case 3: array_qsort(res, 0, res->count - 1, less_int); break;
                case 4: k = get_int(NULL, 0, 0);
                    array_push_back(res, &k); break;
                case 5: array_pop_back(res); break;
                }
            } while (1);
            break;
            case 2:
                for (size_t i = 0; i < res->count; ++i) {
                    array_get(res, i, &t);
                    printf("%d\n", t);
                } break;
            case 3: array_free(res); break;
            case 4: test(); break;
            default: break;
            }
        } while (1);
        break;
    case 2:  fill_array_float(res);
        do {
            print_menu();
            scanf_s("%d", &m);
            if (m > 5 || m < 1) {
                printf("Sorry, you are wrong. Please try again: ");
                continue;
            }
            if (m == 5) break;
            switch (m) {
            case 1: do {
                print_menu_change();
                scanf_s("%d", &s);
                if (s > 6 || s < 1) {
                    printf("Sorry, you are wrong. Please try again: ");
                    continue;
                }
                if (s == 6) break;
                switch (s) {
                case 1:
                    array_map(res, my_sum_float);
                    break;
                case 2:
                    array_map(res, my_mult_float);
                    break;
                case 3:
                    array_qsort(res, 0, res->count - 1, less_float);
                    break;
                case 4:
                    k = get_float(NULL, 0, 0);
                    array_push_back(res, &k);
                    break;
                case 5:
                    array_pop_back(res);
                    break;
                }
            } while (1);
            break;
            case 2:
                for (size_t i = 0; i < res->count; ++i) {
                    array_get(res, i, &f);
                    printf("%f\n", f);
                } break;
            case 3: array_free(res); break;
            case 4: test(); break;
            default: break;
            }
        } while (1);
        break;
    case 3: fill_array_double(res);
        do {
            print_menu();
            scanf_s("%d", &m);
            if (m > 5 || m < 1) {
                printf("Sorry, you are wrong. Please try again: ");
                continue;
            }
            if (m == 5) break;
            switch (m) {
            case 1:
                do {
                    print_menu_change();
                    scanf_s("%d", &s);
                    if (s > 6 || s < 1) {
                        printf("Sorry, you are wrong. Please try again: ");
                        continue;
                    }
                    if (s == 6) break;
                    switch (s) {
                    case 1:
                        array_map(res, my_sum_double);
                        break;
                    case 2:
                        array_map(res, my_mult_double);
                        break;
                    case 3:
                        array_qsort(res, 0, res->count - 1, less_double);
                        break;
                    case 4:
                        k = get_double(NULL, 0, 0);
                        array_push_back(res, &k);
                        break;
                    case 5:
                        array_pop_back(res);
                        break;
                    }
                } while (1);
                break;
            case 2:
                for (size_t i = 0; i < res->count; ++i) {
                    array_get(res, i, &d);
                    printf("%lf\n", d);
                }
                break;
            case 3:
                array_free(res);
                break;
            case 4:
                test();
                break;
            default:
                break;
            }
        } while (1);
        break;
    case 4: fill_array_complex(res); break;
    default: res = NULL; break;
    }
    if (n >= 1 && n <= 4 && res == NULL) {
        printf("Failed to create array!\n");
    }
    return res;
}