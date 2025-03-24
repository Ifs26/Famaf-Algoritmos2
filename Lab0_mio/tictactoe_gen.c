#include <stdio.h>
#include <stdbool.h>

#define N 4

char board[4][4] = {
    { 'x', '-', 'x', 'o' },
    { '-', '-', 'o', 'o' },
    { 'x', 'x', '-', 'o' },
    { 'o', 'o', '-', 'o' }
};

char get_winner(char board[N][N]){
    char winner;
    winner = '-';
    int it = 0;
    while (it < N){
        /*Ahora necesito un iterador que compare el elemento 0 con cada uno hasta el
        N-1 lugar*/
        int it_elem = 0;
        bool fila_win = true;
        bool col_win = true;
        while (it_elem < N){
            //Verifica filas
            fila_win = fila_win && (board[it][0]==board[it][it_elem]) && (board[it][it_elem] !='-');
            //Verifica columna
            col_win = col_win && (board[0][it]==board[it_elem][it]) && (board[it_elem][it] !='-');

            it_elem = it_elem+1;
        }

        if (fila_win == 1) {
            winner = board[it][0];      
        } else if (col_win == 1) {
            winner = board[0][it];
        }

        it = it+1;
    }

    //Verifica diagonal de arriba izquierdo hacia abajo
    it = 0;
    bool winDiag1 = true;
    bool winDiag2 = true;
    while (it<N){
        //Verifica diagonal de arriba izquierdo hacia abajo
        winDiag1 = winDiag1 && (board[0][0] == board[it][it]) && (board[it][it] !='-');
        //Verifica diagonal de arriba izquierdo hacia abajo
        winDiag2 = winDiag2 && (board[0][N-1] == board[0+it][(N-1)-it]) && (board[0+it][(N-1)-it] !='-');
        it = it+1;
    }
    if (winDiag1 == 1) {
        winner = board[0][0];
    } else if (winDiag2 == 1) {
        winner = board[0][N-1];
    } 

    return winner;
}

int main(){
    //printf("\n %c \n",get_winner(board));
    printf("Se encontro winner! es %c\n", get_winner(board));
    return 0;
}