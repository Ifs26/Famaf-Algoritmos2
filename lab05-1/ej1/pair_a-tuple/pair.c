#include <stdio.h>
#include <assert.h>
#include "pair.h"

/*
 * DESC: Creates a new pair with components (x, y)
 *
 * p = pair_new(x, y);
 *
 * POS: {p --> (x, y)}
 */
pair_t pair_new(int x, int y){
    pair_t nuevoPar;
    nuevoPar.fst = x;
    nuevoPar.snd = y;
    assert((nuevoPar.fst == x) && (nuevoPar.snd == y));
    return nuevoPar;
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
int pair_first(pair_t p){
    //assert(&p != NULL); //CONSULTAR QUE SIGNIFICA "-->"
    int res = p.fst;
    assert(res == p.fst);
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
int pair_second(pair_t p){
    //assert();
    int res = p.snd;
    assert(res == p.snd); //CONSULTAR
    return res;
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
pair_t pair_swapped(pair_t p){
    pair_t q;
    q.fst = p.snd;
    q.snd = p.fst;
    assert(pair_first(p) == pair_first(q) && pair_second(p) == pair_second(q));
    return q;
}

pair_t pair_destroy(pair_t p){
    return p;
}
/*
 * DESC: Free memory if its necesary
 *
 */



