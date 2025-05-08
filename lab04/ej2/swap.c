#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
//
// Completar aquí
//
/*
proc swap(in/out a : int, in/out b : int)
    var aux : int
    aux := a
    a := b
    b := aux 
end proc
fun main() ret r : int
  var x, y : int
  x := 6
  y := 4
  print(x, y)
  swap(x, y)
  print(x, y)
  r := 0
end fun
*/

void swap1(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}



int main(void) {
    int x=-20, y=0; 

    
    printf("\n%d,%d\n",x,y);
    swap(&x,&y);
    printf("\n%d,%d\n",x,y);

    return EXIT_SUCCESS;
}