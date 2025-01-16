#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 100 // tamanho do array

int main() {

    FILE *arquivo;
    int n;
    int array[LEN];
    arquivo = fopen("random-nums/input1.txt", "r");
    for (int i = 0; i < 100; i++) {
        fscanf(arquivo, "%d", &n);
        array[i] = n;
    }
    fclose(arquivo);
    for (int i = 0; i < 100; i++) {
        printf("%d\n", array[i]);
    }



    return 0;
}