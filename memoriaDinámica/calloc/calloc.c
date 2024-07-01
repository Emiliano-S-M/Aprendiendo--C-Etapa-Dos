#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int n, i;

    // Tamaño del array
    printf("Ingrese el tamaño del array: ");
    scanf("%d", &n);

    // Asignar memoria para n enteros e inicializar a cero
    array = (int *)calloc(n, sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Error de asignación de memoria\n");
        return 1;
    }

    // Mostrar el array inicializado
    printf("Elementos del array inicializado:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Liberar memoria
    free(array);
    getchar();
    getchar();
    return 0;
}
