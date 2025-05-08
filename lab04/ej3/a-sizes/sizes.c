#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);

    int n_size = sizeof(messi.name);
    int a_size = sizeof(messi.age);
    int h_size = sizeof(messi.height);
    int t_size = sizeof(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n\n", n_size,a_size,h_size,t_size);

    printf("name-size  : %lu \n"
    "age-size   : %lu\n"
    "height-size: %lu\n"
    "data_t-size: %lu\n\n",  (uintptr_t) &messi.name,(uintptr_t) &messi.age,
    (uintptr_t) &messi.height, (uintptr_t) &messi);

    printf("name-size  : %p \n"
        "age-size   : %p\n"
        "height-size: %p\n"
        "data_t-size: %p\n\n",(void *) &messi.name,(void *) &messi.age,
        (void *) &messi.height,(void* )&messi);

    data_t *p;
    p = malloc(sizeof(data_t));
    strcpy(p->name,"Leo Messi");
    p->age = 36;
    p->height = 169;

    printf("name  : %s bytes\n"
        "age   : %d bytes\n"
        "height: %d bytes\n"
        , p->name,p->age,p->height);

    free(p);
    p = NULL;

    /*
     *
     * COMPLETAR
     *
     */

    return EXIT_SUCCESS;
}
