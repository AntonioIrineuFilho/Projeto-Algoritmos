#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 1000000 // tamanho do array

int main() {

    FILE *arquivo;
    int n;
    int array[LEN];
    arquivo = fopen("random-nums/input5.txt", "r");
    for (int i = 0; i < 1000000; i++) {
        fscanf(arquivo, "%d", &n);
        array[i] = n;
    }
    fclose(arquivo);

    for (int i = 0; i < 1000000; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}