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
    while(i)



    while (i<=j){
        printf("particion! %d\n", i);
        if (a[i] <= a[pivot]){
            i = i+1;
        } else if (a[j] >= a[pivot]){
            j = j-1;
        } else if (a[i]>a[pivot] && a[j]<a[pivot]){
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

