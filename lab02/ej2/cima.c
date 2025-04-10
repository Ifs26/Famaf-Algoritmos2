#include <stdio.h>
#include <stdbool.h>
#include "cima.h"

/**
 * @brief Indica si el arreglo tiene cima.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */

bool tiene_cima(int a[], int length){

    bool estric_crec = true;
    bool estric_decrec = false;
    bool cima_alcanzada = true;

    
    if (length >= 2){
        int it = 0;

        if (a[it]>a[it+1]){ //Si el arreglo comienza bajando al cima estaria al inicio
            estric_crec = false;
            estric_decrec = true;
            it = it+1;
        } else if (a[it]>a[it+1]){//Si el arreglo arranca con repetidos no hay cima
            estric_crec = false;
            estric_decrec = false;
            cima_alcanzada = false;
        }

        while (estric_crec && it<length-1){
            if (a[it]>a[it+1]){ //posible cima y debe entrar al sig bucle
                estric_crec = false;
                estric_decrec = true;

            } else if (a[it] == a[it+1]){ //No hay cima y no debe entrar al sig bucle
                estric_crec = false; 
                cima_alcanzada = false;
            }
            it= it+1;
        }
        while (estric_decrec && it<length-1){ //desde cima debe solo bajar
            if (a[it]<=a[it+1]){
                estric_decrec = false;
                cima_alcanzada = false;
            }
            it = it+1;
        }
    }

    return cima_alcanzada;
}

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima.
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
int cima(int a[], int length) {
    /*Ahora solo tengo que frenar al iterador*/
    bool estric_crec = true;

    int it = 0;
    if (length >= 2){
        
        if (a[it]>a[it+1]){ //Si el arreglo comienza bajando al cima estaria al inicio
            estric_crec = false; //El it se queda al inicio y no se entra a los bucles
        }

        while (estric_crec && it<length){
            if (a[it]>a[it+1]){ //Se encontró cima y no debe entrar al sig bucle
                estric_crec = false;
            } else {
                it= it+1;
            }
            
        }
    }

    //La cima esta en la ultima ubicacion analizada
    return it;
}

