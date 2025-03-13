#include <stdio.h>
#include <stdbool.h>

char board[3][3] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
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

int main(){
    printf("\n %d \n",has_free_cell(board));
    return 0;
}