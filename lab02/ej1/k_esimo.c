#include <stdbool.h>
#include <stdio.h>
#include "k_esimo.h"
#include <assert.h>

// FUNCIONES INTERNAS DEL MÓDULO:
int partition(int a[], int izq, int der);
bool goes_before(int x, int y);
void swap(int a[], int i, int j);

/**
 * @brief K-esimo elemento mas chico del arreglo a.
 *
 * Devuelve el elemento del arreglo `a` que quedaría en la celda `a[k]` si el
 * arreglo estuviera ordenado. La función puede modificar el arreglo.
 * Dicho de otra forma, devuelve el k-esimo elemento mas chico del arreglo a.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 * @param k Posicion dentro del arreglo si estuviera ordenado.
 */
int k_esimo(int a[], int length, int k) {

    // COMPLETAR!!
    assert(k<=length);

    /* int res = 0;

    int ppiv = 0;
    for (int i=0;i <= k;i++){
        ppiv = partition(a,i,length-1);
        if(ppiv == k){
            res = ppiv;
        }
    }

    return a[res]; */

    int izq = 0, ppiv,der = length-1;
    //obtiene el lugar definitivo del primer elemento
    ppiv = partition(a,izq,der);

    //mientras el pivote (ubicacion def de un valor)
    //no sea igual al lugar que queremos saber
    while (ppiv!=k)
    {
        /*Si el lugar que me interesa es menor 
            o igual al lugar definitivo que encontre */
        if(goes_before(k,ppiv)){
            /*busco la ubi definitiva del primer elemento del segmento izq*/
            ppiv = partition(a, izq, ppiv-1);
        } else { /*Si el lugar que me interesa es mayor 
                    que el lugar definitivo que encontre*/
            /*busco la ubi defintiva del primer elemento del segmento der*/
            ppiv = partition(a,ppiv+1, der);
        }
    }
    return a[ppiv];
    
}

int partition(int a[], int izq, int der) {
    int i, j, ppiv;
    ppiv = izq;
    i = izq + 1;
    j = der;
    while (i <= j) {
        if (goes_before(a[i], a[ppiv])) {
            i = i + 1;
        } else if (goes_before(a[ppiv], a[j])) {
            j = j - 1;
        } else {
            swap(a, i, j);
        }
    }

    swap(a, ppiv, j);
    ppiv = j;

    return ppiv;
}

bool goes_before(int x, int y) {
    return x <= y;
}

void swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
