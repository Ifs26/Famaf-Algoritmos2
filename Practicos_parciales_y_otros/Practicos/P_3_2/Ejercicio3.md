# Ejercicio 9

## Usted quiere irse de vacaciones y debe elegir una ciudad entre K posibles que le interesan. Como no dispone de mucho dinero, desea que el viaje de ida hacia la ciudad pueda realizarse con a lo sumo L litros de nafta.

### Parte (a) 
De un algoritmo que, dado un grafo representado por 
* una matriz E : array[1..n,1..n] of Nat, donde el elemento E[i,j] indica el costo en litros de nafta necesario para ir desde la ciudad i hasta la ciudad j; 
* un conjunto C de vertices entre 1 y n, representando las ciudades que quieren visitarse; 
* un vertice v, representando la ciudad de origen del viaje; 
* y un natural L, indicando la cantidad de litros de nafta total que puede gastar; 

devuelva un conjunto D de aquellos v´ertices de C que puede visitar con los L litros.

~~~~haskell
fun vertices_visitables(a:array[1..n,1..n] of int, v: int ,C: Set of Int, l: Int) ret D: Set of int

    var visited: array[1..n] of Bool
    var dist: array[1..n] of Int
    var D: Set of int
    var u, minDist: int

    D := empty_set()

    -- Inicialización de distancias y visitados
    for i := 1 to n do
        dist[i] := INF
        visited[i] := false
    od

    dist[v] := 0

    -- Algoritmo de Dijkstra alterado para este ejercicio del orto
    for i := 1 to n do
        minDist := INF
        u := -1

        -- Buscar el nodo no visitado con menor distancia
        for j := 1 to n do
            if not visited[j] and dist[j] < minDist then
                minDist := dist[j]
                u := j
            fi
        od

        if u != -1 then --Si u==-1 entonces no se habria encontrado nodo con menor distancia

            visited[u] := true

            -- Actualizar distancias de los vecinos
            for j := 1 to n do
                if not visited[j] and a[u,j] > 0 then
                    if dist[u] + a[u,j] < dist[j] then
                        dist[j] := dist[u] + a[u,j]
                    fi
                fi
            od
        fi
    od
    -- Al final dist va a tener las distancias min entre la loc inicial y las otras

    -- Verificar qué ciudades de C son alcanzables con ≤ L litros
    for i := 1 to n do
        if existe_en_set(C, i) and dist[i] <= l then
            agregar_a_set(D, i)
        fi
    od


~~~~

## Parte (b) 

Ejecute el algoritmo implementado en el inciso anterior para el grafo descripto en el siguiente grafico, con v´ertices 1,2,...11, tomando C = {11,5,10,7,8} como las ciudades de inter´es, disponiendo de L = 40 litros de nafta. ¿Cu´ales son los posibles destinos de acuerdo a su presupuesto?

Ayuda: Utilice el algoritmo de Dijkstra.

~~~~Haskell
Esperalo sentado 
