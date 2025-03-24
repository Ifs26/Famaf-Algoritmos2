#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    /* Needs implementation */
    
    /* PRECONDITION: 
       0 <= izq < der < length of the array

     Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */

    unsigned int pivot = izq;
    unsigned int i = izq+1;
    unsigned int j = der;

    while (i<=j){//i y j se van a ir a acercando desde los bordes
        if (goes_before(a[i],a[pivot])){ //a[i] <= a[pivot]
            i = i+1;
        } else if (goes_before(a[pivot],a[j])){ //a[j] >= a[pivot]    return x <= y
            j = j-1;
        } else if (!(goes_before(a[i],a[pivot])) && !(goes_before(a[pivot],a[j]))){
            swap(a,i,j);
        }
    }
    swap(a,pivot,j);
    pivot = j;
    return pivot;
   
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 */
    unsigned int ppiv; 
    if (der > izq){
        ppiv = partition(a,izq,der);
        quick_sort_rec(a,izq,ppiv-1);
        quick_sort_rec(a,ppiv+1,der);
    }

}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

