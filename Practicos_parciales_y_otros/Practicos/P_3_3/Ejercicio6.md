# Ejercicio 6: 
##  Un artesano utiliza materia prima de dos tipos: A y B. Dispone de una cantidad MA y MB de cada una de ellas. Tiene a su vez pedidos de fabricar *n* productos p1, . . . , pn (uno de cada uno). Cada uno de ellos tiene un valor de venta v1, . . . , vn y requiere para su elaboracion cantidades a1, . . . , an de materia prima de tipo A y b1, . . . , bn de materia prima de tipo B. ¿Cual es el mayor valor alcanzable con las cantidades de materia prima disponible?



_**maxValAlcanzable(MA,MB,i)**_ = "Determina el mayor valor alcanzable con **p***1*...**p**_i_ productos que valen **v***1*,...,**v***i* y requieren **a***1*,...,**a***i* materia prima A y **b***1*,...,**b***i*, dada una cantidad de MA (materia prima A) y MB (materia prima B)"

Casos: 
* Si no hay mas MA y MB entonces 0
* Si no hay mas productos a fabricar y hay o no materia prime entonces 0
* Si el producto _i_ cuesta mas materiales de los que se tienen se ignora 
* Si hay materiales suficiente materia prima para el producto _i_ entonces se evalua el caso en el que se fabrica y el caso en el que no y se elige el caso de mayor valor. 

$$
maxValAlcabzable(MA,MB,i) =
\left\lbrace
\begin{array}{ll}
0 & \text{si } (i=0)\\
maxValAlcanzable(MA,MB,i-1) & \text{si } (a_i \gt MA) \lor (b_i \gt MB)\\
\max\left(maxValAlcanzable(MA,MB,i-1),\ (v_i + maxValAlcanzable(MA-a_i,MB-b_i,i-1)\right) & \text{si } (a_i \leq MA)\land(b_i \leq MB) 
\end{array}
\right.
$$

## La llamada principal que resuelve el problema es: maxValAlcanzable(MA, MB, n)