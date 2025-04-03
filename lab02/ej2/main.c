#include <stdio.h>
#include <stdlib.h>
#include "cima.h"

int main(void) {
    int a[] = {-2, 8, 9, 9, 9};
    int length = 5;
    int result;

    result = cima(a, length);
    int result2 = tiene_cima(a,length);

    printf("Resultado: %i\n", result);

    return EXIT_SUCCESS;
}
