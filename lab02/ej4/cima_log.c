#include <stdio.h>
#include <stdbool.h>
#include "cima_log.h"

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima
 * usando la estrategia divide y venceras.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 * La cima es el elemento que se encuentra en la posición k.
 * PRECONDICION: tiene_cima(a, length)
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */

/* int cima_log2(int a[], int length) {

    int res = length-1; //ubicacion del ultimo elemento
    if (length == 1){ //Si el largo es igual a 1 entonces la ubicacion es 0
        res = 0;
    } else {
        res = a[cima_log(a,length-1)] > a[res] ? cima_log(a,length-1) : res;
    }

    return res;
} */

#include <stdio.h>

void print_array_segment(int a[], int start, int end) {
    printf("[");
    for (int i = start; i < end; i++) {
        printf("%d", a[i]);
        if (i < end) {
            printf(", ");
        }
    }
    printf("]\n");
}

int cima_log_rec(int a[], int lft, int rgt){
    //print_array_segment(a,lft,rgt);

    int res;
    
    if (lft == rgt){ //Si el largo es igual a 1 entonces la ubicacion es 0
        res = lft;
    } else { //
        int mid = (lft+(rgt-1)) / 2; //HABIA UN PROBLEMA ACA!
        res = a[mid] < a[mid+1] ? cima_log_rec(a,mid+1,rgt) : cima_log_rec(a,lft,mid);
    }

    return res;
}

int cima_log(int a[], int length) {
    return cima_log_rec(a,0,length);
}
