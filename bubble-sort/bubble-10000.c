#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 10000 // tamanho do array

int main() {

    FILE *arquivo;
    int n;
    int array[LEN];
    arquivo = fopen("random-nums/input3.txt", "r");
    for (int i = 0; i < 10000; i++) {
        fscanf(arquivo, "%d", &n);
        array[i] = n;
    }
    fclose(arquivo);
    return 0;
}