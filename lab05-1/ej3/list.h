#include <stdbool.h>

/* Esto es para el b)
struct Node{
    list_elem elem;
    Node *next;
}


typedef struct list_impl *list; 

struct Node {
    list_elem elem;
    Node *next;
}

struct list_impl {
    Node *first;
}

/*
struct list_impl {
    list_elem elems[MAX_ELEMS];
    int size;
}*/



/*
    constructors
    fun empty() ret l : List of T
    
    proc addl (in e : T, in/out l : List of T)
    {- agrega el elemento e al comienzo de la lista l. -}

*/

/* CONSTRUCTORS----------------------------------------------*/
typedef int list_elem;

typedef struct list_imp *list;

list empty();
//{- crea una lista vacía. -}

list addl(list_elem e, list l);
//{- agrega el elemento e al comienzo de la lista l. -}

void destroy(list l);
// Libera memoria en caso de que sea necesario

/* OPERATIONS----------------------------------------------*/

bool is_empty(list l);
//Devuelve true si es l es vacia

list_elem head(list l);
//Devuelve el primer elemento de la lista l

list tail(list l);
//Elimina el primer elemento de la lista l
//PRE: not is_empty(l)

void addr(list_elem e, list l);
//Agrega el elemento e al final de la lista l

int lenght(list l);
//Devuelve la cantidad de elementos de la lista l

void concat(list l,list l0);
//Agrega al final de l todos los elementos de l0 en el mismo orden

list_elem index(list l, int n);
//Devuelve el n-esimo elemento de la lista l
//PRE: lenght(l) > n && n > 0

void take(list l, int n);
//Deja en l solo los primeros n elementos, eliminando el resto

void drop(list l, int n);
//Elimina los primeros n elementos de l

list copy_list(list l);
//Copia todos los elemtnos de l1 en la nueva lista l2
