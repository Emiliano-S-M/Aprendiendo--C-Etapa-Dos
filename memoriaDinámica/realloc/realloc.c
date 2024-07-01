#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int n = 5, new_size, i;

    // Asignar memoria inicial para 5 enteros
    array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Error de asignación de memoria\n");
        return 1;
    }

    // Inicializar el array
    for (i = 0; i < n; i++) {
        array[i] = i;
    }

    // Mostrar el array inicial
    printf("Array inicial:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Redimensionar el array a 10 enteros
    new_size = 10;
    array = (int *)realloc(array, new_size * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Error de redimensionamiento de memoria\n");
        return 1;
    }

    // Inicializar los nuevos elementos
    for (i = n; i < new_size; i++) {
        array[i] = i;
    }

    // Mostrar el array redimensionado
    printf("Array redimensionado:\n");
    for (i = 0; i < new_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Liberar memoria
    free(array);

    return 0;
}
