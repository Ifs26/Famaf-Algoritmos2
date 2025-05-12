# Ejercicio 8

## I) ***Describa cual es el criterio de seleccion***

Se elegirán los troncos que duren mas tiempo y que superen la cantidad de temperatura minima establecida en ese momento.

## II) ***¿En que estructuras de datos representara la informacion del problema?***

Representaré los n troncos en un arreglo de Tronco, el cual será una tupla que contenga su duracion y la temperatura que irradia mientras se quema. Devolveré una cola de Tronco, la cual marca el orden en el que deben ser colocados

## III) ***Explique el algoritmo***

Primero separaré los troncos en dos arreglos de acuerdo a cada temperatura minima, luego los voy a ordenar de acuerdo al tiempo que duran cada uno y por ultimo los ire agregando a la cola teniendo en cuenta el tiempo restante

## Implementación para (a):

~~~~haskell
type Tronco := tuple
                    t: nat
                    k: nat
                end tuple

fun ordenTroncos (aT: array[1..n] of Tronco,K1: nat, K2: nat) ret qT: Queue of Tronco
    
    var aT1, aT2 : array[1..n] of Tronco
    var aT1_len,aT2_len: nat

    {-En el arreglo aT1 guardo solo los troncos que cumplen con la temperatura minima del K mas bajo, en aT2 guardo trncos que cumplen con K mas alto, y tomo la cantidad de elementos en total de cada caso-}
    dividirT(aT,aT1,aT2,K1,K2,aT1_len,aT2_len)

    {-Ahora voy a ordenar cada arreglo (de min t a max t) con un quick sort de largo personalizable-}
    qsp_T(aT1,aT1_len)
    qsp_T(aT2,aT2_len)

    contadorK1 := 8*60
    contadorK2 := 6*60

    aT1_len := aT1_len-1
    aT2_len := aT2_len-1
    if (K1 < K2)
        {-Primer caso: K1 es el horario que necesita menor temperatura (raro pero posible?)-}
        while (contadorK1 > 0 && aT1_len > 0) do
            enqueue(qT,aT1[aT1_len])
            aT1_len := aT1_len - 1
            contadorK1 := contadorK1 - aT1[aT1_len].t
        od
        while (contadorK2 > 0 && aT2_len > 0) do
            enqueue(qT,aT2[aT2_len])
            aT2_len := aT2_len - 1
            contadorK2 := contadorK2 - aT2[aT2_len].t
    else
        {-Segundo caso: K2 es el horario que necesita menor temperatura o K1 == K2-}
        while (contadorK1 > 0 && aT1_len > 0) do
            enqueue(qT,aT1[aT1_len])
            aT1_len := aT1_len - 1
            contadorK1 := contadorK1 - aT1[aT1_len].t
        od
        while (contadorK2 > 0 && aT2_len > 0) do
            enqueue(qT,aT2[aT2_len])
            aT2_len := aT2_len - 1
            contadorK2 := contadorK2 - aT2[aT2_len].t
    fi
end fun

proc dividirT(in aT:array[1..n] of Tronco, in/out aT1:array[1..n] of Tronco, in/out aT2:array[1..n] of Tronco, in K1: nat, in K2: nat, in/out aT1_len: nat, in/out aT2_len: nat)

    var minK,maxK,pos_aT1,pos_aT2 : nat

    aT1_len := 0
    aT2_len := 0
    pos_aT1 := 0
    pos_aT2 := 0

    if (K1 < K2) then
        aT1_len := 0
        aT2_len := 0
        pos_aT1 := 0
        pos_aT2 := 0
        for i:=1 to n do
            if (aT[i].k >= K1 && aT[i].k < K2 ) then
                aT1[pos_aT1] := aT[i]
                aT1_len := aT1_len + 1
                pos_aT1 := pos_aT1 +1
            else 
                aT2[pos_aT2] := aT[i]
                aT2_len := aT2_len + 1
                pos_aT2 := pos_aT2 + 1
            fi
        od
    else 
        aT1_len := 0
        aT2_len := 0
        pos_aT1 := 0
        pos_aT2 := 0
        for i:=1 to n do
            if (aT[i].k >= K2 && aT[i].k < K1 ) then
                aT2[pos_aT2] := aT[i]
                aT2_len := aT2_len + 1
                pos_aT2 := pos_aT2 + 1
            else 
                aT1[pos_aT1] := aT[i]
                aT1_len := aT1_len + 1
                pos_aT1 := pos_aT1 +1
            fi
        od
    fi

    {-Complejidad final de este proceso: O(n) -}
end proc

proc qsp_T(in/out aT:array[1..n] of Tronco,in aT1_len: nat)
    qsp_T_rec(aT,1,aT1_len)
end proc

proc qsp_T_rec(in/out aT:array[1..n] of Tronco, in lft : nat, in rgt: nat)
    var ppiv: nat
    if (rgt > lft) then
        partitionT(aT,lft,rgt,ppiv)
        qsp_T_rec(aT,lft,ppiv-1)
        qsp_T_rec(aT,ppiv+1,rgt)
    fi
end proc

proc partitionT(in/out aT:array[1..n] of Tronco, in lft : nat, in rgt: nat, out ppiv: nat)
    var i,j: nat
    ppiv := lft
    i:= lft
    j := rgt

    while (i<=j) do
        if (aT[i].t <= aT[ppiv].t) then
            i:=i+1
        else if (aT[j].t >= aT[ppiv].t) then
                j:=j-1
            else if ((aT[i].t > aT[ppiv].t)&&(aT[j].t < aT[ppiv].t)) then
                swap(aT,i,j)
                i:=i+1
                j:=j-1
                fi
            fi
        fi
    od
    swap(aT,ppiv,j)
    ppiv:=j
end proc

~~~~