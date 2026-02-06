#include "sort.h"
#include <stdio.h>

/* Helper: swap two integers */
void swap_ints(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Lomuto partition with printing */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j && array[i] != array[j])
            {
                swap_ints(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }

    if (i + 1 != high && array[i + 1] != array[high])
    {
        swap_ints(&array[i + 1], &array[high]);
        print_array(array, size);
    }

    return i + 1;
}

/* Recursive Quick Sort helper */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi = lomuto_partition(array, low, high, size);
        quick_sort_recursive(array, low, pi - 1, size);
        quick_sort_recursive(array, pi + 1, high, size);
    }
}

/* Public Quick Sort function */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}
