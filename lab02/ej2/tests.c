#include <stdbool.h>
#include <stdio.h>
#include "cima.h"

#define MAX_LENGTH 10
#define N_TESTCASES_TIENE_CIMA 10
#define N_TESTCASES_CIMA 6

void test_tiene_cima(void);
void test_cima(void);

int main() {
    test_tiene_cima();
    test_cima();

    return 0;
}

void test_tiene_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        bool result;
    };

    struct testcase tests[N_TESTCASES_TIENE_CIMA] = {
      { {8}, 1, true }, //1
      { {8,2}, 2, true }, //2
      { {8,9,9}, 3, false }, //3
      { {8,80,90,89}, 4, true },//4
      { {8,10,10,1,110}, 5, false },//5
      { {8,9,10,11,12}, 5, true },//6
      { {8,7,6,5,4}, 5, true },//7
      { {8,8}, 2, false },//8
      { {1,8}, 2, true },//9
      { {8,8,8,8,8}, 5, false },//10

    };
    bool result;

    printf("TESTING tiene_cima\n");

    for (int i=0; i < N_TESTCASES_TIENE_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = tiene_cima(tests[i].a, tests[i].length);

        if (result != tests[i].result) {
            printf("FAILED\n");
        } else {
            printf("OK\n");
        }
    }
}

void test_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        int result;
    };

    struct testcase tests[N_TESTCASES_CIMA] = {
        { {8}, 1, 0 }, //1
        { {8,2}, 2, 0 }, //2
        { {8,80,90,89}, 4, 2 },//3
        { {8,9,10,11,12}, 5, 4 },//4
        { {8,7,6,5,4}, 5, 0 },//5
        { {1,8}, 2, 1  },//6

        // COMPLETAR!!

    };
    int result;

    printf("TESTING cima\n");

    for (int i=0; i < N_TESTCASES_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = cima(tests[i].a, tests[i].length);

        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED. got %d expected %d\n", result, tests[i].result);
        }
    }
}
