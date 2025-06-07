# Ejercicio 9: 
## El juego -U↑P% consiste en mover una ficha en un tablero de n filas por n columnas desde la fila inferior a la superior. La ficha se ubica al azar en una de las casillas de la fila inferior y en cada movimiento se desplaza a casillas adyacentes que esten en la fila superior a la actual, es decir, la ficha puede moverse a:
-   ## la casilla que esta inmediatamente arriba
-   ## la casilla que esta arriba y a la izquierda (si la ficha no esta en la columna extrema izquierda),
-   ## la casilla que esta arriba y a la derecha (si la ficha no esta en la columna extrema derecha).
## Cada casilla tiene asociado un numero entero cij (i, j = 1, . . . , n) que indica el puntaje a asignar cuando la ficha este en la casilla. El puntaje final se obtiene sumando el puntaje de todas las casillas recorridas por la ficha, incluyendo las de las filas superior e inferior. Determinar el maximo y el mınimo puntaje que se puede obtener en el juego.

````python
Mis notas: 
-> En cada paso tengo que subir si o si, y tengo tres opciones.
-> En cada llamada empiezo desde la linea i y se quiere llegar al final, viendo como se altera j, PERO SIEMPRE SE SUMA ALGO.
-> En cada llamada quiero restar 1 a "i", que representa las filas, y debere sumar el valor de c_{i,j} de acuerdo al j que haya elegido entre las tres opciones.

````

_**maxPuntaje(i,j)**_ = "Calcula el maximo puntaje de UP al llegar a la casilla (i,j) con valor $c_{i,j}$ desde cualquier casilla en la fila inicial, avanzando una fila a la vez de manera vertical o diagonal y sumando los valores de cada casilla visitada."  

Casos: 
* Si no hay mas filas por las que pasar entonces 0.
* Si hay filas entonces y se está en fila j=1 entonces se elige entre la misma fila j o la fila j+1.
* Si hay filas entonces y se está en fila j=n entonces se elige entre la misma fila j o la fila j+1.
* Si hay filas y no se está en los bordes entonces se debe verificar las tres opciones de movimiento.





$$
maxPuntaje(i,j) =
\left\lbrace
\begin{array}{ll}
0 & \text{si } (i=0)\\
\max\left(c_{i,j} + maxPuntaje(i-1,j),\ c_{i,j} + maxPuntaje(i-1,j+1)\right)) & \text{si } (j=1)\land(i>0) \\
\max\left(c_{i,j} + maxPuntaje(i-1,j),\ c_{i,j} + maxPuntaje(i-1,j-1)\right)) & \text{si } (j=n)\land(i>0) \\
\max\left(c_{i,j} + maxPuntaje(i-1,j),
         \max (c_{i,j} + maxPuntaje(i-1,j-1),
               c_{i,j} + maxPuntaje(i-1,j+1)\right)) & \text{si } ((j \gt 1 \land j \lt n)\land(i>0) 
\end{array}
\right.
$$

## La llamada principal que resuelve el problema es: $\max (maxPuntaje(n,1),max (maxPuntaje(n,2),max (maxPuntaje(n,3),\dots,maxPuntaje(n,n)\dots )))$