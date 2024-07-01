#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hola, mundo!";
    char dest[20];

    // Copia con límite
    strncpy(dest, src, 5);
    dest[5] = '\0';  // Asegurarse de terminar con nulo

    // Muestra el resultado
    printf("Destino: %s\n", dest);
    getchar();
    return 0;
}
