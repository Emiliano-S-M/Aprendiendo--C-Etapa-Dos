#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int n, i;

    // Tamaño del array
    printf("Ingrese el tamaño del array: ");
    scanf("%d", &n);

    // Asignar memoria para n enteros
    array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Error de asignación de memoria\n");
        return 1;
    }

    // Inicializar y mostrar el array
    for (i = 0; i < n; i++) {
        array[i] = i * 2;  // Ejemplo de inicialización
    }

    printf("Elementos del array:\n");
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
