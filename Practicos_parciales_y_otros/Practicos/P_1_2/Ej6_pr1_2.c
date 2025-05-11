#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void swap(int a[], unsigned int i, unsigned int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void print_array(int a[], unsigned int length) {
    printf("\n[");
    for (unsigned int i = 0; i < length; i++) {
        printf("%d", a[i]);
        if (i < length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

static unsigned int partitionFer(int a[], unsigned int lft, unsigned int rgt) {
    print_array(a,rgt+1);

    unsigned int piv_izq = lft;
    unsigned int i = lft+1;
    unsigned int j = rgt; 
    int pasos = 0;

    int pivot = a[lft]; //Este valor ya no se altera, incluso si se cambia a[lft] luego
    
    while (i<=j){
        if (a[i]<pivot){
            swap(a,i,piv_izq);
            piv_izq = piv_izq+1;
            i = i+1;
        } else if (a[i] == pivot){
            i=i+1;
        } else {
            swap(a,i,j);
            j=j-1;
        }
        pasos = pasos+1;
    }
    printf("Cantidad de pasos: %d", pasos);
    print_array(a,rgt+1);

    return j;

    /*
                                ¡¿Como lo hace?!

    -Guarda el pivot y empieza a comparar este valor con los elementos del arreglo

    -Cuando el marcador izquierdo encuentra un elemento menor al pivot, se intercambian
    los lugares y se indica que el pivot izquierdo será una ubicacion mas a la derecha
    (y se mueve el marcador izq)

    -Cuando el marcador izquierdo encuentra un elemento igual al pivot solo se mueve el
    marcador izquierdo

    -Para el resto de los casos (cuando el elemento en i es mayor que el pivote) se intercambia
    lugar con la posicion j y se mueve la posicion j un lugar a la izquierda y se vuelve a
    analizar el nuevo valor de la ubicacion i (muy inteligente para no caer en un bucle!)
    
    Como se le ocurrio mover el pivot?
    */
}
    

static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    print_array(a,der+1);
    unsigned int pivot = izq;
    unsigned int k = izq+1;
    unsigned int i = izq+1; 
    unsigned int j = der; 
    int pasos = 0;

    while (i<=j){
        if (a[i] < a[pivot]){
            i = i+1;
        } else if (a[i] == a[pivot]){
            //Tengo que hacer swaps para que el valor en i se vaya al inicio k
            for (unsigned int apunt_i = i; apunt_i>k ;apunt_i--){
                swap(a,apunt_i,apunt_i-1);
            }
            i = i+1;
            k = k+1;

        } else if (a[j] > a[pivot]){
            j = j-1;
            j = (j > 0) ? j : 0;

        } else if (a[j] == a[pivot]){
            //Tengo que hacer swaps para que el valor en j se vaya al inicio k
            for (unsigned int apunt_j = j; apunt_j>k ;apunt_j--){
                swap(a,apunt_j,apunt_j-1);
            }
            i = i+1;
            k = k+1;

        } else if ((a[i] > a[pivot]) && (a[j] < a[pivot])){
            swap(a,i,j);
            i = i+1;
            j = j-1;
            j = (j > 0) ? j : 0;
        } 
        pasos = pasos+1;  
    }
    pivot = i-1;

    //la guarda original podía darme un numero negativo y romper todo
    unsigned int it = 0;
    while (it <= pivot-k && pivot - k < der+1){
        swap(a,it,k+it);
        it = it+1;
        pasos = pasos+1;
    }
    printf("Cantidad de pasos: %d", pasos);
    print_array(a,der+1);
    //pivot derecho = pivot obtenido
    //pivot izquierdo = pivot - (k-1)
    return pivot;
}


int main() {

    /*En resumen el algoritmo de Fer es estable, el mio mientras 
    menos repetidos y mas lejos este el ultimo mas pasos ejecuta*/
    int a[] = {7,6,6,6,10,11,6,60,3,80,7,6,77,2};
    unsigned int pivot1 = partition(a,0,12);
    printf("\n%d\n",pivot1);
    unsigned int pivot2 = partitionFer(a,0,12);
    printf("\n%d\n",pivot2);
    return 0;
}
