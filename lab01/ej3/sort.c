#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

#include <stdio.h>

void print_array(int a[], unsigned int length) {
    printf("[");
    for (unsigned int i = 0; i < length; i++) {
        printf("%d", a[i]);
        if (i < length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    /* Needs implementation */

    /* PRECONDITION: 
       0 <= izq < der < length of the array

     Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */
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

    
    //printf("\nUltimo j de iteracion: %d\n",j);
    swap(a,pivot,j);
    pivot = j;

    return pivot;

    /*
    while (i<=j){//i y j se van a ir a acercando desde los bordes

        printf("\n|| i=%d",i);
        printf(" y j=%d",j);
        printf("|| pivot: %d en lugar %d",a[pivot], pivot);

        if ((a[i] > a[pivot]) && (a[j] < a[pivot])){
            printf("\nSWAP! por %d > %d y ademas %d < %d",a[i],a[pivot],a[j],a[pivot]);
            swap(a,i,j);
        }

        i = (a[i] <= a[pivot]) ? i+1 : i ;
        j = (a[j] >= a[pivot]) ? j-1 : j ;
        
        


        
        printf("\n|| i=%d",i);
        printf(" y j=%d",j);
        printf("|| pivot: %d en lugar %d",a[pivot], pivot);
        //assert(i<=j);
    }
    printf("\n/------");
    swap(a,pivot,j);
    pivot = j; 
    return pivot;
   */
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 */
    unsigned int ppiv; 
    if (der > izq){
        ppiv = partition(a,izq,der);
        quick_sort_rec(a,izq,ppiv > 0 ? ppiv-1 :0 );
        quick_sort_rec(a,ppiv+1,der);
    }

}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

