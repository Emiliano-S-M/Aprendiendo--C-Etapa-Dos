# `strtok` - Tokenización de Cadenas en C

La función strtok pertenece a la librería `string.h` y se utiliza para dividir una cadena en una serie de tokens, que son subcadenas separadas por delimitadores específicos. Esta función es muy útil para analizar y procesar textos.

```c
char *strtok(char *str, const char *delim);
```

**Parámetros**

1. `str`: La cadena que se va a dividir en tokens. En la primera llamada a strtok, se pasa la cadena completa. En las llamadas subsecuentes, se debe pasar NULL para continuar la tokenización de la misma cadena.

1. `delim`: Una cadena que contiene todos los caracteres delimitadores. Cada caracter en esta cadena es considerado como un separador entre tokens.

**Valor de Retorno**

La función **`strtok`** devuelve un puntero al primer token encontrado en la cadena. En las llamadas subsecuentes, devuelve punteros a los siguientes tokens. Si no se encuentran más tokens, la función devuelve **`NULL`**.

**Funcionamiento**

1. **Primera llamada:** Se pasa la cadena original junto con los delimitadores.

1. **Llamadas subsecuentes:** Se pasa `NULL` como el primer argumento, y la función continúa desde la posición donde terminó la última vez.

### [Código --> aquí](./strtok.c)

Explicación del Ejemplo.

**Declaración de la cadena y delimitadores:**
```c 
char str[] = "Hola,mundo,esto,es,una,prueba"; 
``` 
```
char delim[] = ",";
```

**Primera llamada a strtok:** 
```c
token = strtok(str, delim);
```
divide la cadena `str` usando `,` como delimitador. Devuelve un puntero al primer token, `"Hola"`.

**Bucle while:** Las llamadas subsecuentes a \`strtok\` usan NULL como primer argumento para obtener los siguientes tokens: "mundo", "esto", "es", "una", y "prueba". El bucle continúa hasta que strtok devuelve NULL.