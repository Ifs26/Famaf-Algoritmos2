# Ejemplo de uso de llave, ¡Ver codigo!
$$
f(x,y) = 
\left\lbrace
\begin{array}{ll}
x + y = 10 \\
x - y = 2 \\
3x + y = 7 \\
x^2 + y^2 = 25
\end{array}
\right.
$$

# Ejercicio 3: 
## Una panaderia recibe n pedidos por importes m1, . . . , mn, pero solo queda en deposito una cantidad H de harina en buen estado. Sabiendo que los pedidos requieren una cantidad h1, . . . , hn de harina (respectivamente), determinar el maximo importe que es posible obtener con la harina disponible.

maxImporte(H,n) = "Maximo importe con H harina dispoible con h1,...,hn pedidos

Casos: 
* Si no hay mas harina (H = 0) entonces no el maximo importe es 0.
* Si no hay mas pedidos entonces el maximo importe es 0.
* Si hay pedidos y harina disponible entonces debería barajar la posibilidad de tomar o no ese pedido, y asi sucesivamente.
* Cuando no haya suficiente harina para un pedido, lo evito.

$$
maxImporte(H,n)
\left\lbrace
\begin{array}{ll}
0 &\text{si }(H=0)\lor(n=0) \\
max(maxImporte(H,n-1),m_n+maxImporte(H-h_n,n-1)) &\text{si }(H\geq h_n)\\
maxImporte(H,n-1)&\text{si }(H<h_n)\\
\end{array}
\right.
$$

$$
maxImporte(H,n) =
\left\lbrace
\begin{array}{ll}
0 & \text{si } H = 0 \lor n = 0 \\
\max\left(maxImporte(H, n - 1),\ m_n + maxImporte(H - h_n, n - 1)\right) & \text{si } H \geq h_n \\
maxImporte(H, n - 1) & \text{si } H < h_n
\end{array}
\right.
$$
