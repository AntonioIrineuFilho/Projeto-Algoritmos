#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void input(int array[], int tamanho) {
    FILE *arquivo;
    int n;
    arquivo = fopen("random-nums/input5.txt", "r");
    for (int i = 0; i < 1000; i++) {
        fscanf(arquivo, "%d", &n);
        array[i] = n;
    }
    fclose(arquivo);
}

void troca(int *x, int *y) {
    int n = *x;
    *x = *y;
    *y = n;
}

void bubble(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (i == tamanho - 1) { break; }
        for (int j = 0; j < tamanho; j++) {
            if (j == tamanho - 1) { break; }
            if (array[j] > array[j+1]) {
                troca(&array[j], &array[j+1]);
            }
        }
    }
}

int main() {
    int len = 1000000;
    int array[len];
    double s, dif;
    input(array, len);
    for (int i = 0; i < 4; i++) {
        clock_t init = clock();
        bubble(array, len);
        clock_t end = clock();
        dif = (double)(end-init) / CLOCKS_PER_SEC;
        printf("Exec em segundos = %lf\n", dif);
        s = s + dif;
    }
    s = s / 4;
    printf("Média = %lf\n", s); // média de 19.09 segundos (array de 1.000.000 números)
    return 0;
}