#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "pair.h" //Recordar ponerlo en comillas para que busque el local

pair_t pair_new(elem x, elem y){
    pair_t nuevoP;
    nuevoP = malloc(sizeof(pair_t));

    nuevoP->fst = x;
    nuevoP->snd=y;
    assert(nuevoP != NULL && nuevoP->fst == x && nuevoP->snd == y);
    return nuevoP;
}
/*
 * DESC: Creates a new pair with components (x, y)
 *
 * p = pair_new(x, y);
 *
 * POS: {p --> (x, y)}
 */

elem pair_first(pair_t p){
    assert(&p != NULL);
    int res = p->fst;
    assert(res == p->fst);
    return res;
}
/*
 * DESC: Returns the first component of p
 *
 * PRE: {p --> (x, y)}
 *
 *  fst = pair_first(p);
 *
 * POS: {fst == x}
 */

elem pair_second(pair_t p){
    assert(&p != NULL);
    int res = p->snd;
    assert(res == p->snd);
    return res;
}
/*
 * DESC: Returns the second component of p
 *
 * PRE: {p --> (x, y)}
 *
 *  snd = pair_second(p);
 *
 * POS: {snd == y}
 */

pair_t pair_swapped(pair_t p){
    pair_t swaped;
    swaped->fst = p->snd;
    swaped->snd = p->fst;
    return swaped;
}
/*
 * DESC: Return a NEW pair with the components of p reversed
 *
 * PRE: {p --> (x, y)}
 *
 *  q = pair_swapped(p)
 *
 * POS: {pair_first(q) == pair_second(p) && pair_second(q) == pair_first(p)}
 *
 */

pair_t pair_destroy(pair_t p){
    free(p);
    p=NULL;
    return p;
}
/*
 * DESC: Free memory if its necesary
 *
 */
