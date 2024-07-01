#include <stdio.h>
#include <string.h>

int main() {
    char dest[20] = "Hola";
    char src[] = ", mundo!";

    // Concatenar con límite
    strncat(dest, src, 7);

    // Muestra el resultado
    printf("Resultado: %s\n", dest);

    getchar();
    return 0;
}
