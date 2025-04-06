#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}


static void insert(int a[], unsigned int i) {
    /* copiá acá la implementación que hiciste en el ejercicio 1 */
    unsigned int j = i;

    while ((j > 0) && goes_before(a[j],a[j-1])){
        /* 
        Había pensado agregar la segunda parte de la guarda como un if, 
        pero de esta manera el programa termina antes.
        */
        //array_dump(a,length);
        swap(a,j-1,j);
        j = j-1;
    } 
}

void insertion_sort(int a[], unsigned int length) {
    /* copiá acá la implementación que hiciste en el ejercicio 1 */
        for (unsigned int i = 1; i < length; ++i) {
        insert(a, i);
        assert(array_is_sorted(a, i));
    }
}


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 */
    unsigned int pivot = izq; //Osea el primer elemento de la lista
    unsigned int i = izq+1; //Tiene que detectar menores al pivot
    unsigned int j = der; //Tiene que detectar mayores al pivot

    while (i<=j){
        //printf("\n|| i=%d",i);
        //printf(" y j=%d",j);
        //printf("|| pivot: %d en lugar %d",a[pivot], pivot);

        //i = (a[i] <= a[pivot]) ? i+1 : i ;
        //j = (a[j] >= a[pivot]) ? j-1 : j ;
        

        /*if ((a[i] > a[pivot]) && (a[j] < a[pivot])){
            //printf("\nSWAP! por CASO i %d > %d y ademas CASO j %d < %d\n",a[i],a[pivot],a[j],a[pivot]);
            swap(a,i,j);
        }*/

        if (a[i] <= a[pivot]){
            i = i+1;
        } else if (a[j] >= a[pivot]){
            j = j-1;
            j = (j > 0) ? j : 0;
        } else if ((a[i] > a[pivot]) && (a[j] < a[pivot])){
            swap(a,i,j);
        }
    }
    swap(a,pivot,j);
    pivot = j;

    return pivot;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 2 */
    unsigned int ppiv; 
    if (der > izq){
        ppiv = partition(a,izq,der);
        /*if (ppiv > 0){
            quick_sort_rec(a,izq,ppiv-1);
        }*/
        quick_sort_rec(a,izq,ppiv > 0 ? ppiv-1 :0 );
        quick_sort_rec(a,ppiv+1,der);
    }
}

void quick_sort(int a[], unsigned int length) {
    /* copiá acá la implementación que hiciste en el ejercicio 1 */
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}
