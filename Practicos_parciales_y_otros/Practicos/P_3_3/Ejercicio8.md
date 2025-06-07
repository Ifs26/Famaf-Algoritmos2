# Ejercicio 8: 
## Una fabrica de automoviles tiene dos lıneas de ensamblaje y cada lınea tiene n estaciones de trabajo, S1,1, . . . , S1,n para la primera y S2,1, . . . , S2,n para la segunda. Dos estaciones S1,i y S2,i (para i = 1, . . . , n), hacen el mismo trabajo, pero lo hacen con costos a1,i y a2,i respectivamente, que pueden ser diferentes. Para fabricar un auto debemos pasar por n estaciones de trabajo Si1,1, Si2,2 . . . , Sin,n no necesariamente todas de la misma l´ınea de montaje (ik = 1,2). Si el automovil esta en la estacion Si,j , transferirlo a la otra lınea de montaje (es decir continuar en Si0,j+1 con i0 6= i) cuesta ti,j . Encontrar el costo mınimo de fabricar un automovil usando ambas lıneas

````python
Mis notas: 
Cada estacion tiene un costo, asi que en cada caso tengo que verificar si me quedo en la linea o no, y cambiarse de linea cuesta ti,j.

Entonces tengo que verificar si tiene menor costo la estacion siguiente de la misma linea o la otra estacion + el cambio de estacion.

Hay una misma cantidad de estaciones, osea en cada paso tengo siempre dos opciones si o si.
````

_**mejorCombinacion(lineaActual,i)**_ = "Calcula la combinacion de *1,...,i* estaciones que tiene menor costo de produccion de ensamblaje de automoviles entre dos lineas $S_{1,1}, \dots, S_{1,i}$ y $S_{2,1},\dots,S_{2,i}$ con costos $a_{1,1}, \dots, a_{1,i}$ y $a_{2,1}, \dots, a_{2,i}$ respectivamente, comenzando en la linea _lineaActual_ (1 o 2). Cambiar de linea en la estacion **k** a **k+1**, con *k:1,...,i-1*, cuesta $t_{lineaActual,k}$"

Casos: 
* Si no hay estaciones por pasar entonces 0.
* Si aun hay lineas entonces debo ver si elijo como siguiente la estacion de la misma linea (se suma costo de la linea actual) o la otra linea (se suma costo de la otra linea mas el costo de cambio de linea)



$$
mejorCombinacion(lineaActual,i) =
\left\lbrace
\begin{array}{ll}
0 & \text{si } (i=0)\\

\min\left(S_{1,i} + mejorCombinacion(1,i-1),\ (S_{2,i}+t_{1,i}+ mejorCombinacion(2,i-1)\right)) & \text{si } (lineaActual = 1)\land(i>0) \\

\min\left(S_{2,i} + mejorCombinacion(2,i-1),\ (S_{1,i}+t_{2,i}+ mejorCombinacion(1,i-1)\right)) & \text{si } (lineaActual = 2)\land(i>0)
\end{array}
\right.
$$

## La llamada principal que resuelve el problema es: $\min (mejorCombinacion(1,n),mejorCombinacion(2,n))$