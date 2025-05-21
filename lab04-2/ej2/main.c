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

    show_list(my_list);

    return 0;
}
