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

// Função auxiliar para realizar o merge de duas partes do array
void merge(int array[], int esquerda, int meio, int direita) {
    // Tamanhos dos subarrays
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    // Arrays temporários para armazenar as duas metades
    int *esquerdaArray = (int *)malloc(n1 * sizeof(int));
    int *direitaArray = (int *)malloc(n2 * sizeof(int));

    // Copiando os dados para os arrays temporários
    for (int i = 0; i < n1; i++)
        esquerdaArray[i] = array[esquerda + i];
    for (int j = 0; j < n2; j++)
        direitaArray[j] = array[meio + 1 + j];

    // Realizando o merge dos arrays temporários de volta ao array principal
    int i = 0, j = 0, k = esquerda;
    while (i < n1 && j < n2) {
        if (esquerdaArray[i] <= direitaArray[j]) {
            array[k] = esquerdaArray[i];
            i++;
        } else {
            array[k] = direitaArray[j];
            j++;
        }
        k++;
    }

    // Copiando os elementos restantes de esquerdaArray, se houver
    while (i < n1) {
        array[k] = esquerdaArray[i];
        i++;
        k++;
    }

    // Copiando os elementos restantes de direitaArray, se houver
    while (j < n2) {
        array[k] = direitaArray[j];
        j++;
        k++;
    }

    // Liberando a memória alocada para os arrays temporários
    free(esquerdaArray);
    free(direitaArray);
}

// Função principal do Merge Sort
void mergeSort(int array[], int esquerda, int direita) {
    if (esquerda < direita) {
        // Encontrando o ponto médio
        int meio = esquerda + (direita - esquerda) / 2;

        // Ordenando as duas metades recursivamente
        mergeSort(array, esquerda, meio);
        mergeSort(array, meio + 1, direita);

        // Realizando o merge das duas metades ordenadas
        merge(array, esquerda, meio, direita);
    }
}

int main() {
    int array[LEN];
    double dif;
    input(array, LEN);
    clock_t init = clock();
    // Chamando a função Merge Sort
    mergeSort(array, 0, LEN - 1);
    clock_t end = clock();
    dif = (double) (end-init) / CLOCKS_PER_SEC;
    printf("Exec em segundos = %f", dif);
    return 0;
}