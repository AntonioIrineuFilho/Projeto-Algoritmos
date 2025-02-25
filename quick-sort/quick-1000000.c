#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 1000000

void input(int array[], int len) {
    int n;
    FILE *arquivo;
    arquivo = fopen("random-nums/input5.txt", "r");
    for (int i = 0; i < len; i++) {
        fscanf(arquivo, "%d", &n);
        array[i] = n;
    }
    fclose(arquivo);
}

// Função auxiliar para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para particionar o array
int partition(int array[], int baixo, int alto) {
    // Escolhe o último elemento como pivô
    int pivot = array[alto];
    int i = baixo - 1; // Índice do menor elemento

    // Rearrayanja os elementos com base no pivô
    for (int j = baixo; j <= alto - 1; j++) {
        if (array[j] < pivot) {
            i++; // Incrementa o índice do menor elemento
            swap(&array[i], &array[j]);
        }
    }

    // Coloca o pivô na posição correta
    swap(&array[i + 1], &array[alto]);

    return i + 1; // Retorna a posição do pivô
}

// Função principal do Quick Sort
void quickSort(int array[], int baixo, int alto) {
    if (baixo < alto) {
        // Encontra o índice do pivô após a partição
        int pi = partition(array, baixo, alto);

        // Ordena recursivamente as duas metades
        quickSort(array, baixo, pi - 1);
        quickSort(array, pi + 1, alto);
    }
}

int main() {
    int array[LEN];
    double dif;
    input(array, LEN);
    clock_t init = clock();
    // Chamando a função Quick Sort
    quickSort(array, 0, LEN - 1);
    clock_t end = clock();
    dif = (double) (end-init) / CLOCKS_PER_SEC;
    printf("Exec em segundos = %f", dif);
    return 0;
}