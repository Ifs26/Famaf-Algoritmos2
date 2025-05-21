#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node *List;

/**
 * @brief Construye y devuelve una lista de ejemplo de 3 elementos
 */
List setup_example() {
    //
    // COMPLETAR ACÁ!
    //
    List l;
    Node *n;
    l = malloc(sizeof(Node));
    n = l;

    //registra los dos primeros y deja creado el ultimo
    for (int i=2; i>0; i--){
        n->data = i*10;
        n->next = malloc(sizeof(Node));
        n = n->next;
    }
    n->data = 0;
    n->next = NULL;

    return l;
}

/**
 * @brief Agrega un elemento de ejemplo al final de la lista
 *
 * Precondicion: la lista xs no debe ser vacía
 */
void append_example(List xs) {
    Node *n;
    n = xs;

    //bucle que va hasta el final del arreglo
    while (n->next != NULL){
        n = n->next;
    }

    n->next = malloc(sizeof(Node));
    n = n->next;
    n->data = 88;
    n->next = NULL;
}

void show_list(List xs) {
    printf("[ ");
    while (xs != NULL) {
        printf("%i, ", xs->data);
        xs = xs->next;
    }
    printf("]\n");
}

int main(void) {
    List my_list;

    my_list = setup_example();

    printf("Lista antes del append: ");

    show_list(my_list);

    append_example(my_list);

    printf("Lista después del append: ");

    show_list(my_list);

    return 0;
}
