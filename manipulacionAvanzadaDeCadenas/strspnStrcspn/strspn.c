#include <stdio.h>
#include <string.h>

void main() {
    char s1[] = "123abc456";
    char s2[] = "1234567890";
    size_t len;

    // Calcula la longitud del segmento inicial
    len = strspn(s1, s2);

    // Muestra el resultado
    printf("La longitud del segmento inicial es: %zu\n", len);

   getchar();
}
