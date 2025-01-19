#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void input(int array[], int tamanho) {
    int n;
    FILE *arquivo;
    arquivo = fopen("random-nums/input4.txt", "r");
    for (int i = 0; i < tamanho; i++) {
        fscanf(arquivo, "%d", &n);
        array[i] = n;
    }
    fclose(arquivo);
}


void insertion(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int atual = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > atual) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = atual;
    }
}

int main() {
    int len = 100000;
    int array[len];
    double s, dif;
    input(array, len);

    for (int i = 0; i < 4; i++) {
        clock_t init = clock();
        insertion(array, len);
        clock_t end = clock();
        dif = (double)(end-init) / CLOCKS_PER_SEC;
        printf("Exec em segundos = %lf\n", dif);
        s = s + dif;
    }

    s = s / 4;
    printf("Média = %lf", s); // média = 1.149843 (array de 10.000 números inteiros)

    return 0;
}