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
int cima_log(int a[], int length) {

    int res = length-1; //ubicacion del ultimo elemento
    if (length == 1){ //Si el largo es igual a 1 entonces la ubicacion es 0
        res = 0;
    } else {
        res = a[cima_log(a,length-1)] > a[res] ? cima_log(a,length-1) : res;
    }

    return res;
}
