#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

struct list_imp{
    list_elem elem;
    struct list_imp *next;
};

/* CONSTRUCTORS----------------------------------------------*/

list empty(){
    /*
    list l;
    l = NULL;
    return l;
    */
    return NULL;
}
//{- crea una lista vacía. -}

list addl(list_elem e, list l){
    struct list_imp *elemento;
    elemento = malloc(sizeof(struct list_imp));
    elemento->elem = e;
    elemento->next = l;
    return elemento;
}
//{- agrega el elemento e al comienzo de la lista l. -}

//Esta es una version alterativa
void addlALT(list_elem e, list *l){
    struct list_imp *elemento;
    elemento = malloc(sizeof(struct list_imp));
    elemento->elem = e;
    elemento->next = *l;
    *l = elemento;
}
//{- agrega el elemento e al comienzo de la lista l. -}

void destroy(list l){
    struct list_imp *elemento;
    elemento = l;
    while(l != NULL){
        l = elemento->next;
        free(elemento);
        elemento = l;
    }
}
// Libera memoria en caso de que sea necesario

/* OPERATIONS----------------------------------------------*/

bool is_empty(list l){
    bool res = false;
    if (l!=NULL){
        res = true;
    }
    return res;
}
//Devuelve true si es l es vacia

list_elem head(list l){
    struct list_imp *elem1 = l;
    list_elem res = elem1->elem;
    return res;
}
//Devuelve el primer elemento de la lista l

list tail(list l){
    struct list_imp *elem1 = l;
    if(is_empty(l) != false){
        l = elem1->next;
        free(elem1);
    }
    return l;
}
//Elimina el primer elemento de la lista l
//PRE: not is_empty(l)

//Agrega el elemento e al final de la lista l
list addr(list_elem e, list l){

    //Idea: voy hasta el final de la lista y hago que el ultimo elemento apunte al nuevo

    //Guardo el elemento en el tipo de dato
    struct list_imp *elemToAdd = malloc(sizeof(struct list_imp));
    elemToAdd->elem = e;
    elemToAdd->next = NULL;

    //Primero verifico si la lista no esta vacia
    if (l != NULL){
        list laux = l; //Creo laux para recorrer toda la lista
        //Avanzo hasta el final de la lista
        while(laux->next != NULL){
            laux = laux->next;
        }
        laux->next = elemToAdd;
    } else {
        l = elemToAdd;
    }

    return l;
}


int lenght(list l){
    list l2;
    l2 = l;
    int res = 0;
    while(l2!=NULL){
        l2 = l2->next;
        res += 1;
    }
    return res;
}
//Devuelve la cantidad de elementos de la lista l

//Agrega al final de l todos los elementos de l0 en el mismo orden
void concat(list l,list l0){ 
    /*Arreglar esto, tengo que usar malloc con cada elemento de la proxima lista
    LOS ELEMENTOS NO PUEDEN QUEDAR COMPARTIDOS*/
    
    //Primero voy a avanzar hasta el final de la lista
    list laux = l;
    while(laux->next != NULL){

    }
}

//Devuelve el n-esimo elemento de la lista l
//PRE: lenght(l) > n && n > 0
list_elem index(list l, int n){
    list l1 = l;
    int iter = n;
    while(iter!=0){
        l1 = l1->next;
        iter = iter-1;
    }
    return l1->elem;
}

//Deja en l solo los primeros n elementos, eliminando el resto
void take(list l, int n){
    //Primero avanzo n lugares
    list l1 = l;
    list l2;
    int iter = n;
    while(iter != 0){
        l1=l1->next;
        iter = iter-1;
    }
    //Ahora imito el proceso de destroy
    while(l1!=NULL){
        l2 = l1;
        free(l2);
        l1 = l1->next;
    }

}

//Elimina los primeros n elementos de l
list drop(list l, int n){
    //Alternativa mejor
    list l1; 
    int pos = 0;
    while(pos<n && !is_empty(l)){
        l1 = l;
        l = l->next;
        free(l1);
        pos++;
    }
    return l;
    //--------------------------------------------------------------
    /* Idea alternativa 2: voy elimanando siempre el primero, si paso el n lugar empiezo a agregarlo por 
    la derecha.*/
}

//Copia todos los elemtnos de l1 en la nueva lista l2
list copy_list(list l){
    
    list lret = empty();
    list *last_ptr = &lret;
    list laux = l;
    while (laux != NULL) {
        *last_ptr = malloc(sizeof(struct list_imp));
        (*last_ptr)->elem = laux->elem;
        (*last_ptr)->next = NULL;
        last_ptr = &((*last_ptr)->next);
        laux = laux->next;
    }
    return lret;
}