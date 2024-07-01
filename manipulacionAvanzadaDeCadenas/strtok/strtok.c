#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hola,mundo,esto,es,una,prueba";
    char delim[] = ",";
    char *token;

    // Primera llamada
    token = strtok(str, delim);

    // Continuar con las llamadas
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, delim);
    }

    getchar();
    return 0;
}
