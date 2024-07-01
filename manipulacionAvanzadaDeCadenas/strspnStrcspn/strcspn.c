#include <stdio.h>
#include <string.h>

int main() {
    char s1[] = "123abc456";
    char s2[] = "abc";
    size_t len;

    // Calcula la longitud del segmento inicial
    len = strcspn(s1, s2);

    // Muestra el resultado
    printf("La longitud del segmento inicial es: %zu\n", len);
    
    getchar();
    return 0;
}
