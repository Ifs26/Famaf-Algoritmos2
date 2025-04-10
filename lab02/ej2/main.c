#include <stdio.h>
#include <stdlib.h>
#include "cima.h"

int main(void) {
    int a[] = {-2, 8, 9, 8, 77};
    int length = 5;
    int result;

    result = cima(a, length);
    int result2 = tiene_cima(a,length);

    printf("Resultado: %i\n", result2);

    return EXIT_SUCCESS;
}
