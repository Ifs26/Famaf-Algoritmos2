# Ejercicio 5: 
##  Sus amigos quedaron encantados con el telefono satelital, para las proximas vacaciones ofrecen pagarle un alquiler por el. Ademas del dia de partida y de regreso (pi y ri) cada amigo ofrece un monto m_i por dia. Determinar el maximo valor alcanzable alquilando el telefono.


_**maxValAlquiler(p,r,i)**_ = "Determina el maximo valor alcanzable alquilando el telefono a cada amigo con dia **p**i y **r**i de salida y llegada pagando **m**i por dia"

Casos: 
* Si no hay amigos (i=0) entonces no hay ganancias (0).
* Si el telefono esta disponible en el dia de salida de un amigo **i** (**r** es menor o igual **p**i) entonces barajo la posibilidad de alquilarselo o no. Si se lo alquilo debo sumar (**m**i * cantidad de dias que lo utilizó (**r**i -**p**i)) al resultado.
  - Primero verifico que la fecha de regreso **r** actual sea menor o igual a la fecha de salida del nuevo caso (No lo puedo alquilar el telefono si no está).
  - Si lo alquilo al amigo i entonces tengo que actualizar la fecha de regreso actual **r** a **r**i.
* Si el amigo **i** sale un dia que el telefono no está (**r** es mayor que **p**i) no se lo alquilo y se descarta la posibilidad de prestarselo.

$$
maxValAlquiler(r,i) =
\left\lbrace
\begin{array}{ll}
0 & \text{si } i = 0 \\[3pt]
maxValAlquiler(r,i-1) & \text{si } r \gt p_i \\[3pt]
\max\left(maxValAlquiler(r,i-1),\ (m_i * (r_i - p_i)) + maxValAlquiler(r_i,i-1)\right) & \text{si } r \leq p_i 
\end{array}
\right.
$$