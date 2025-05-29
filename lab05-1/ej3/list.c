#include <stdio.h>
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

void addr(list_elem e, list l){
    list l2;
    struct list_imp *elemToAdd = malloc(sizeof(struct list_imp));
    elemToAdd->elem = e;
    elemToAdd->next = NULL;

    l2 = l;
    while(l2 != NULL){
        l2 = l2->next;
    }
    l2->next = elemToAdd;
}
//Agrega el elemento e al final de la lista l

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

void concat(list l,list l0){
    list l1 = l;
    while(l1!=NULL){
        l1 = l1->next;
    }
    l1->next=l0;
}
//Agrega al final de l todos los elementos de l0 en el mismo orden

list_elem index(list l, int n){
    list l1 = l;
    int iter = n;
    while(iter!=0){
        l1 = l1->next;
        iter = iter-1;
    }
    return l1->elem;
}
//Devuelve el n-esimo elemento de la lista l
//PRE: lenght(l) > n && n > 0
/*void destroy(list l){
    struct list_imp *elemento;
    elemento = l;
    while(l != NULL){
        l = elemento->next;
        free(elemento);
        elemento = l;
    }
}
*/
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
//Deja en l solo los primeros n elementos, eliminando el resto

void drop(list l, int n){
    // Voy a eliminar con el algoritmo de destroy los n primeros
    // No tengo que perder el acceso
    list l1 = l; // guardo la direccion base
    int iter = n;
    while(iter!=n){ //Avanzo l n lugares
        l=l->next;
        iter=iter-1;
    }
    //Comienzo a liberar memoria
    //--------------------------------------------------------------
    /* Idea: voy elimanando siempre el primero, si paso el n lugar empiezo a agregarlo por 
    la derecha.*/
}
//Elimina los primeros n elementos de l

list copy_list(list l);
//Copia todos los elemtnos de l1 en la nueva lista l2
