#include <stdio.h>
#include <stdbool.h>

char board[3][3] = {
        { 'x', 'o', '-' },
        { '-', 'o', 'x' },
        { '-', '-', '-' }
};

char board1[3][3] = {
        { '-', '-', '-' },
        { 'x', 'x', 'x' },
        { '-', '-', '-' }
};

char board2[3][3] = {
        { '-', '-', 'o' },
        { '-', '-', 'o' },
        { '-', '-', 'o' }
};

char board3[3][3] = {
        { '-', '-', 'x' },
        { '-', 'x', '-' },
        { 'x', '-', '-' }
};


bool has_free_cell(char board[3][3]){
    bool res = true;
    //char* puntero_verif = "-";
    int it_fila = 0;
    while (it_fila < 3){
        int it_elemento = 0;
        while (it_elemento < 3){
            res = res && ((board[it_fila][it_elemento]) == '-');
            it_elemento = it_elemento+1;
        }
        it_fila = it_fila+1;
    }
    return res;
}

char get_winner(char board[3][3]){
    char winner;
    winner = '-';
    int it = 0;
    while (it < 3){
        //verifica ganador por completar fila 
        if (((board[it][0] == board[it][1]) && (board[it][0] == board[it][2])) && (board[it][0]!='-')){
            winner = board[it][0]; 
            //siguiente if verifica ganador por completar columna
        }
        if (((board[0][it]==board[1][it])&&(board[0][it]==board[2][it])) && (board[0][it]!='-')){
            winner = board[0][it]; 
        }
        it = it+1;
    }
    if ((((board[0][0]==board[1][1])&&(board[1][1]==board[2][2])) || ((board[0][2]==board[1][1])&&(board[1][1]==board[2][0]))) && (board[1][1]!='-')) {
        winner = board[1][1];
    }   
    return winner;
}

int main(){
    printf("\n %c \n",get_winner(board1));
    return 0;
}