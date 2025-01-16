#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 1000 // tamanho do array

int main() {

    FILE *arquivo;
    int n;
    int array[LEN];
    arquivo = fopen("random-nums/input2.txt", "r");
    for (int i = 0; i < 1000; i++) {
        fscanf(arquivo, "%d", &n);
        array[i] = n;
    }
    fclose(arquivo);
    return 0;
}