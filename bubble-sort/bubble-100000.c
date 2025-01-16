#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 100000 // tamanho do array

int main() {

    FILE *arquivo;
    int n;
    int array[LEN];
    arquivo = fopen("random-nums/input4.txt", "r");
    for (int i = 0; i < 100000; i++) {
        fscanf(arquivo, "%d", &n);
        array[i] = n;
    }
    fclose(arquivo);
    return 0;
}