#include <stdio.h>
#include <string.h>

// Implementación de la función strrev
char *strrev(char *str) {
    if (!str) {
        return NULL;  // Manejo de cadenas nulas
    }

    int length = strlen(str);
    int i;
    char temp;

    for (i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }

    return str;
}

int main() {
    char str[] = "Hola, mundo!";
    
    printf("Original: %s\n", str);
    printf("Invertida: %s\n", strrev(str));
    
    getchar();
    return 0;
}
