# Ejercicio 3: 
## Usted se encuentra en un globo aerostatico sobrevolando el oceano cuando descubre que empieza a perder altura porque la lona esta levemente dañada. Tiene consigo n objetos cuyos pesos p1, . . . , pn y valores v1, . . . , vn conoce. Si se desprende de al menos P kilogramos lograra recuperar altura y llegar a tierra firme, y afortunadamente la suma de los pesos de los objetos supera holgadamente P. ¿Cu´al es el menor valor total de los objetos que necesita arrojar para llegar sano y salvo a la costa?

_**minPerdida(P,pTotal,i)**_ = "Menor valor total de los **1, ...,i** objetos con peso **p**1,...**p**i y valor **v**1,...**v**i  que se necesita arrojar para tener peso total **pTotal** menor al peso soportable **P** y asi llegar sano y salvo a la costa"

Casos: 
* Si no hay objetos (n=0) pero p_total es mayor que P (pTotal > P) entonces infinito (imposible llegar).
* Si P = 0 entonces 0 (no se tira nada).
* Si pTotal es menor o igual que P entonces 0 (Se logró el objetivo).
* Si pTotal > P y existen objetos, debo barajar la posibilidad de quitarlo o no en cada caso. Al final me quedare con la via que pierde menos valor.

$$
minPerdida(P,pTotal,i) =
\left\lbrace
\begin{array}{ll}
0 & \text{si } P = 0 \lor pTotal \leq P \\
\infty & \text{si } i=0\ \land pTotal \gt P \\
\min\left(minPerdida(P,pTotal,i-1),\ v_i + minPerdida(P, pTotal - p_i, i-1)\right) & \text{si } pTotal \gt P \land i \gt 0 
\end{array}
\right.
$$

## Nota: Estoy indexando desde 1, no desde 0. AVERIGUAR