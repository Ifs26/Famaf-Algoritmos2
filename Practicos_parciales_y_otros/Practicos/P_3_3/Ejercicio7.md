# Ejercicio 7: 
## En el problema de la mochila se buscaba el maximo valor alcanzable al seleccionar entre n objetos de valores v1, . . . , vn y pesos w1, . . . , wn, respectivamente, una combinacion de ellos que quepa en una mochila de capacidad W. Si se tienen dos mochilas con capacidades W1 y W2, ¿cual es el valor maximo alcanzable al seleccionar objetos para cargar en ambas mochilas?

````python
Mis notas: 

Tengo dos mochilas ahora, por lo que tengo:
    -> 1,..,n objetos con v1,...,vn valores con w1,...,wn pesos 
    -> DOS capacidades W1 y W2

Necesito calcular el maximo valor alcanzable, por lo que puedo ir agregando objetos en cada mochila si todavia tiene alguna espacio para que entre.
````

_**maxValCargable(W1,W2,i)**_ = "Calcular el maximo valor cargable en las dos mochilas con capacidad *W1* y *W2* dado **1,...,i** objetos con **v1,...,vn** valores y **w1,...,wn** pesos respectivamentes."

Casos: 
* Si no hay mas objetos entonces 0.
* Si el objeto es mas pesado que la capacidad actual de W1 y de W2 entonces se saltea el objeto.
* Si el objeto pesa menos que la capacidad actual de W1 pero no entra en W2 se prueba la posibilidad de guardarlo o no en W1.
* Si el objeto pesa menos que la capacidad actual de W2 pero no entra en W1 se prueba la posibilidad de guardarlo o no en W2.
* Si el objeto pesa menos que la capacidad actual de W1 y W2 entonces se prueba el caso en el que no se guarda o se guarda en W1 o se guarda W2.



$$
maxValCargable(W1,W2,i) =
\left\lbrace
\begin{array}{ll}
0 & \text{si } (i=0)\\

maxValCargable(W1,W2,i-1) & \text{si } (w_i \gt W1) \land (w_i \gt W2)\\

\max\left(maxValCargable(W1,W2,i-1),\ (v_i + maxValCargable(W1-w_i,W2,i-1)\right)) & \text{si } (w_i \leq W1)\land(w_i \gt W2) \\

\max\left(maxValCargable(W1,W2,i-1),\ (v_i + maxValCargable(W1,W2-w_i,i-1)\right)) & \text{si } (w_i \gt W1)\land(w_i \leq W2) \\

\max\left(maxValCargable(W1,W2,i-1), max(v_i + maxValCargable(W1-w_i,W2,i-1),v_i + maxValCargable(W1,W2-w_i,i-1)\right)) & \text{si } (w_i \leq W1)\land(w_i \leq W2) 
\end{array}
\right.
$$

## La llamada principal que resuelve el problema es: maxValCargable(W1, W2, n)