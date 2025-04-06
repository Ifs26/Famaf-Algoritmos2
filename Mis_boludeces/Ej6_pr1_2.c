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

static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    print_array(a,der+1);
    unsigned int pivot = izq;
    unsigned int k = izq+1;
    //unsigned int pivot_izq = 0; //A la izquierda van a quedar menores
    //unsigned int pivot_der = 0; //A la derecha van a quedar mayores
    unsigned int i = izq+1; //Tiene que detectar menores al pivot
    unsigned int j = der; //Tiene que detectar mayores al pivot

    while (i<=j){

        printf("\n(!) apuntador i en %d y apuntador j en %d",i,j);

        if (a[i] < a[pivot]){
            printf("\nEl apuntador i se movio! ");
            i = i+1;
        } else if (a[i] == a[pivot]){
            printf("\nCaso i igual a pivot ");
            print_array(a,der+1);
            //Tengo que hacer swaps para que el valor en i se vaya al inicio
            for (unsigned int apunt_i = i; apunt_i>k ;apunt_i--){
                swap(a,apunt_i,apunt_i-1);
                print_array(a,der+1);
            }
            i = i+1;
            k = k+1;

        } else if (a[j] > a[pivot]){
            printf("\nEl apuntador j se movio! ");
            j = j-1;
            j = (j > 0) ? j : 0;

        } else if (a[j] == a[pivot]){
            printf("\nCaso j igual a pivot ");
            print_array(a,der+1);
            //Tengo que hacer swaps para que el valor en j se vaya al inicio
            for (unsigned int apunt_j = j; apunt_j>k ;apunt_j--){
                swap(a,apunt_j,apunt_j-1);
                print_array(a,der+1);
            }
            i = i+1;
            k = k+1;

        } else if ((a[i] > a[pivot]) && (a[j] < a[pivot])){
            swap(a,i,j);
            i = i+1;
            j = j-1;
            j = (j > 0) ? j : 0;
            printf("\nIntercambio i-j ");
            print_array(a,der+1);
        }   
    }
    //printf("\n------Fuera del bucle------\n");
    //printf("Valor total de k = %d",k);
    
    print_array(a,der+1);

    pivot = i-1;

    //la guarda podía darme un numero negativo y romper todo
    unsigned int it = 0;
    while (it <= pivot-k && pivot - k < der+1){
        printf("bug");
        swap(a,it,k+it);
        it = it+1;
    }
    
    

    print_array(a,der+1);
    //pivot derecho = pivot obtenido
    //pivot izquierdo = pivot - (k-1)
    return pivot;
}


int main() {

    int a[] = {1,7,7,7,10,11,6,60,3,80,7,7,777,2};
    unsigned int pivot1 = partition(a,0,13);
    printf("\n%d\n",pivot1);

    return 0;
}
