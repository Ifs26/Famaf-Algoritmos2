#include <stdio.h>

int strlen(char *s){
    int n;
    for (n = 0; *s != '\0'; s++ ){
        n++;
    }
    
    return n;
}

int main() {

    int num = 400;

    int* pa; //Apuntador int
    pa = &num; //pointer apunta a address de num

    int num2 = *pa; //num2 es igual al valor que apunte pa
    printf("variable num = %d guardada en address: %d\n",num2,pa);

    char palabra[1];
    printf("Ingrese palabra: ");
    scanf("%s",palabra);
    printf("La palabra %s tiene %d letras.",palabra,strlen(palabra));
    

    return 0;
}