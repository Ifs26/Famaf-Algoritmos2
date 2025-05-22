#include <stdbool.h>
#include <stdlib.h>

#include <stdio.h>
#include <assert.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void){
    counter c;
    c = malloc(sizeof(struct _counter));
    c->count=0;
    return c;
}

void counter_inc(counter c) {
    c->count += 1;
}

bool counter_is_init(counter c) {
    return (c->count == 0);
}

void counter_dec(counter c) {
    c->count = c->count-1;
}

counter counter_copy(counter c) {
    counter c2;
    c2 = malloc(sizeof(struct _counter));
    c2->count = c->count;
    return c2;
}

void counter_destroy(counter c) {
    free(c);
}
