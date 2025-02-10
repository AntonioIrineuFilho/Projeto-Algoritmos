#include <stdio.h>
#include <time.h>

#define LEN 1000000

void input(int array[]) {
    int n;
    FILE *arquivo;
    arquivo = fopen("random-nums/input5.txt", "r");
    for (int i = 0; i < LEN; i++) {
        fscanf(arquivo, "%d", &n);
        array[i] = n;
    }
    fclose(arquivo);
}

void selection(int array[]) {
    for (int i = 0; i < LEN; i++) {
        int indiceMenor = i;
        for (int j = i; j < LEN; j++) {
            if (array[j] < array[indiceMenor]) {
                indiceMenor = j;
            }
        }
        if (i != indiceMenor) {
            int aux = array[i];
            array[i] = array[indiceMenor];
            array[indiceMenor] = aux;
        }
    }
}

int main() {

    int array[LEN];
    input(array);
    double dif;
    clock_t init = clock();
    selection(array);
    clock_t end = clock();
    dif = (double)(end-init) / CLOCKS_PER_SEC;
    printf("Exec em segundos = %f\n", dif);

    return 0;
}