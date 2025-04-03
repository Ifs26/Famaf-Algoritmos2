#include <stdbool.h>
#include <stdio.h>
#include "k_esimo.h"

#define MAX_LENGTH 5
#define N_TESTCASES 14

struct testcase {
    int a[MAX_LENGTH];
    int length;
    int k;
    int result;
};

int main() {
    struct testcase tests[N_TESTCASES] = {
      // arreglo, largo, k, resultado esperado
      { {8}, 1, 0, 8 },
      { {1,2}, 2, 0, 1 },
      { {3,6}, 2, 0, 3 },
      { {1,2}, 2, 1, 2 },
      { {3,6}, 2, 1, 6 },
      { {6,2}, 2, 0, 2 },
      { {33,7}, 2, 0, 7 },
      { {100,1}, 2, 1, 100 },
      { {333,62}, 2, 1, 333 },
      { {8, -2, 9, 0, 13},5,0,-2},
      { {8, -2, 9, 0, 13},5,1,0},
      { {8, -2, 9, 0, 13},5,2,8},
      { {8, -2, 9, 0, 13},5,3,9},
      { {8, -2, 9, 0, 13},5,4,13},

      // COMPLETAR!!

    };
    int result;

    printf("TESTING k_esimo\n");

    for (int i=0; i < N_TESTCASES; i++) {
        printf("Test case %i: ", i+1);

        result = k_esimo(tests[i].a, tests[i].length, tests[i].k);
        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED\n");
        }
    }

    return 0;
}
