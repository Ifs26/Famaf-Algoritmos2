#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i, unsigned int length) {
    assert(i<length);
    unsigned int j = i;

    while ((j > 0) && goes_before(a[j],a[j-1])){
        /* 
        Había pensado agregar la segunda parte de la guarda como un if, 
        pero de esta manera el programa termina antes.
        */
        array_dump(a,length);
        swap(a,j-1,j);
        j = j-1;
    } 
    /*
    Desde una ubicacion (j) va desde el lado izquierdo a derecho chequeando 
    que el elemento a su derecha (j-1) es menor o mayor, y mientras su valor
    derecho (j-1) sea mayor se intercambian de lugar (swap).

    Luego se vuelve a repetir la condicion chequeando (j-1) y (j-2), 
    hasta llegar a (j-x)==1, donde se chequea con el primer elemento
    (a[0]) y termina el control.
    */
}

void insertion_sort(int a[], unsigned int length) {
    
    for (unsigned int i = 1; i < length; ++i) {
        insert(a, i, length);
        assert(array_is_sorted(a, i));
    }
    

    /*
    El algoritmo consiste en verificar de izquierda a derecha una lista y,
    desde cada elemento, verificar derecha a izquierda si todos los elementos 
    anteriores son menores. Si en un caso un elemento de su izquierda es mayor
    se intercambia de lugar y se vuelve a verificar desde el nuevo lugar intercambiado
    si su elemento de la izquierda es menor, hasta llegar al final.
    */

    /*
    unsigned int i = 1;
    while (i < length){ 
        insert(a, i, length);
        assert(array_is_sorted(a, i));
        i = i+1;
    }  */
    
}
