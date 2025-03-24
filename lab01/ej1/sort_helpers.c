#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"

void swap(int a[], unsigned int i, unsigned int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

bool goes_before(int x, int y) {
    return x <= y;
}

bool array_is_sorted(int array[], unsigned int length) {
    unsigned int i = 1;
    while (i < length && goes_before(array[i-1], array[i])) {
        i++;
    }
    return (i >= length);
    /*
    Este algoritmo verifica que un arreglo esta ordenado, para ello
    avanza de izquierda a derecha desde el segundo elemento y verifica 
    que el elemento anterior es menor.
    */
}
