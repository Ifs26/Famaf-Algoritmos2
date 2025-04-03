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
bool tiene_cima(int a[], int length) {
    //para encontrar el lugar puedo sumar 1
    bool sube;
    bool baja;

    bool cima_alcanzada = false;

    if (length<2){
        cima_alcanzada = true;
    } else {

        if (a[0]<=a[1]){
            sube = true;
            baja = false;
        } else {
            baja = true;
            sube = false;
        }
    
        for (int i=1; i<length;i++){
    
            //Caso cuando arranca subiendo
            if ((a[i-1] < a[i]) && sube){
                sube = true;  
            } else if ((a[i-1] > a[i]) && sube){
                cima_alcanzada = true;
                sube = false;
                baja = true;
            }
    
            //caso cuando arranca bajando
            if(baja && (a[i-1] < a[i])){
                baja = false;
                sube = true;
            }
            
        }
    }
    /* Consultar nmuero de picos ////  si tiene un elemento es un pico trivial*/
    //Verifica si el arreglo comienza subiendo o bajando

    //ESTO SIRVE SOLO SI EL ARREGLO DOS ELEMENTOS O MAS
    
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

    // COMPLETAR!!
    bool sube;
    bool baja;

    int res = 0;

    //Verifica si el arreglo comienza subiendo o bajando
    if (a[0]<=a[1]){
        sube = true;
        baja = false;
    } else {
        baja = true;
        sube = false;
    }

    for (int i=1; i<length;i++){

        //Caso cuando arranca subiendo
        if ((a[i-1] < a[i]) && sube){
            sube = true;  
        } else if ((a[i-1] > a[i]) && sube){
            res = i;
            sube = false;
            baja = true;
        }

        //caso cuando arranca bajando
        if(baja && (a[i-1] < a[i])){
            baja = false;
            sube = true;
        }
        
    }
    return res;
}
