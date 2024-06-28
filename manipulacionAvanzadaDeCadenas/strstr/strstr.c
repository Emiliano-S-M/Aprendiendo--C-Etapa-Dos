#include <stdio.h>
#include <string.h>

void main() {
    char haystack[] = "Hola, mundo. Bienvenido al mundo de la programación.";
    char needle[] = "mundo";
    char *result;

    // Búsqueda de la subcadena
    result = strstr(haystack, needle);

    // Verificación del resultado
    if (result != NULL) {
        printf("La subcadena '%s' se encontró en '%s' en la posición: %ld\n", needle, haystack, result - haystack);
    } else {
        printf("La subcadena '%s' no se encontró en '%s'.\n", needle, haystack);
    }

    getchar();
}
