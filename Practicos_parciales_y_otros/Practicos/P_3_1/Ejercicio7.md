# Ejercicio 7

## I) ***Describa cual es el criterio de seleccion***

Se elegirá siempre al sobreviviente que le quede menos tiempo de vida (medido en minutos) y que no muera durante el rescate.

## II) ***¿En que estructuras de datos representara la informacion del problema?***

En ambos ejercicios se ingresan la cantidad de personas en un arreglo del tipo Persona, la cual es una tupla que contiene el nombre y los minutos de vida restantes. Se devuelve una cola con las personas a rescatar.

## III) **Explique el algoritmo**

El algoritmo para el apartado (a) ordena el arreglo segun los minutos restantes, poniendo primero a las personas con menos minutos. Luego se evalua si la persona sobrevivirá al rescate y si aun queda tiempo para rescatar, si ambas condiciones son favorables se rescata la persona, sino se la descarta, se actualizan los tiempos a verificar y se continua verificando con el resto.

Para el algoritmo del apartado (b) el procedimiento es el mismo, pero se evalua cada rescate verificando un "m" numero de personas, si sobrevivirán en el proceso y aun hay tiempo y espacio son rescatadas en ese viaje.

## Implementación para (a):
~~~~
type Persona = tuple
                    c : nat
                    nombre : string
                end tuple

fun rescate(aP:array[1..n] of Persona,t: nat, c_total: nat) ret qP: Queue of Persona

    var rescate_actual,cT,it : nat

    rescate_actual := 1
    cT := c_total
    it := 1

    {- Proceso que ordena un arreglo de personas con quick sort (O(n*log n)) mirando sus minutos restantes, no lo voy a implementar porque es intuitivo. -}
    qs_rescate(aP) 

    
    while (cT >= t) do
        if ((aP[it].c - (rescate_actual*t) > 0) && (aP[it].c - (rescate_actual*t) >= cT)) then
            enqueue(qP,aP[it])
            rescate_actual := rescate_actual + 1
            cT := cT - t
        fi
        it := it +1
    od
end fun
~~~~

## Implementación para (b):
~~~~
type Persona = tuple
                    c : nat
                    nombre : string
                end tuple

fun rescate(aP:array[1..n] of Persona,t: nat, c_total: nat, m: nat) ret qP: Queue of Persona

    var rescate_actual,cT,it : nat

    rescate_actual := 1
    cT := c_total
    it := 1

    {- Proceso que ordena un arreglo de personas con quick sort (O(n*log n)) mirando sus minutos restantes, no lo voy a implementar porque es intuitivo. -}
    qs_rescate(aP) 

    espacios_rescate := m
    while (cT >= t && it <= n) do

        {-Arranca un rescate-}
        while (espacios_rescate > 0 && it <= n ) do
        
            {-Verifico que sobreviva el superviviente y el rescatista en este rescate-}
            if ((aP[it].c - (rescate_actual*t) > 0) && (aP[it].c - (rescate_actual*t) >= cT)) then

                enqueue(qP,aP[it])
                it := it +1
                espacios_rescate := espacios_rescate - 1
            fi
            espacios_rescate := m
        od

        rescate_actual := rescate_actual + 1
        cT := cT - t
    od
end fun
~~~~