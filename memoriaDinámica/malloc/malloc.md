# función malloc (memory allocation) de la librería `<stdlib.h>` 

En C, la función malloc (memory allocation) de la librería stdlib.h se utiliza para asignar dinámicamente una cantidad específica de memoria durante la ejecución del programa. La memoria asignada con malloc está en el heap, a diferencia de la memoria de pila (stack) que se usa para variables locales.

**Sintaxis**

```c
void* malloc(size_t size);
```

**Parámetro**

- `size`: Es la cantidad de bytes que deseas asignar.

**Valor de Retorno**

- **Puntero al bloque de memoria asignado**: Si la asignación es exitosa, `malloc` devuelve un puntero al primer byte del bloque de memoria asignado.
- **`NULL`**: Si la asignación falla (por ejemplo, si no hay suficiente memoria disponible), `malloc` devuelve `NULL`.

**Uso de malloc**

Para utilizar `malloc` de manera efectiva, es importante comprender algunos conceptos clave:

- **Casting del puntero**: `malloc` devuelve un puntero de tipo `void *`, que debe ser convertido (`cast`) al tipo de puntero adecuado.
- **Liberación de memoria**: La memoria asignada por `malloc` debe ser liberada utilizando `free` para evitar fugas de memoria (memory leaks).

### [Código --> aquí](./malloc.c)

**Explicación del Ejemplo**

1. **Declaración de variables:** `int *array;` declara un puntero a `int` para el array, `int n;` para el tamaño del array, y `int i;` como índice para los bucles.
2. **Lectura del tamaño del array:** Se pide al usuario que ingrese el tamaño del array.
3. **Asignación de memoria:** `array = (int *)malloc(n * sizeof(int));` asigna memoria para `n` enteros.
    - `n * sizeof(int)`: Calcula el tamaño en bytes necesario para almacenar n enteros.
    - Casting del puntero: `(int *)` convierte el puntero `void *` devuelto por `malloc` a un puntero a `int`.
4. **Verificación de la asignación:** Si `malloc` devuelve `NULL`, se imprime un mensaje de error y se finaliza el programa.
5. **Inicialización del array:** Se inicializan los elementos del array con valores de ejemplo (`i * 2`).
6. **Impresión del array:** Se muestra el contenido del array.
7. **Liberación de memoria:** `free(array);` libera la memoria asignada para evitar fugas de memoria.

**Consideraciones**

- **Fugas de memoria:** Siempre asegúrate de liberar la memoria asignada con malloc utilizando `free`.
- **Verificación de asignación:** Verifica siempre si `malloc` devuelve `NULL` antes de usar la memoria asignada.
- **Casting del puntero:** Aunque no es estrictamente necesario en C (pero sí en C++), es una buena práctica convertir el puntero `void *` al tipo adecuado para mayor claridad y compatibilidad.

**Resumen**
- **`malloc`:** Función para asignar memoria dinámica. Devuelve un puntero al bloque de memoria asignado o `NULL` si la asignación falla.
- **Liberación de memoria:** Usa `free` para liberar la memoria asignada y evitar fugas de memoria.
- **Uso seguro:** Siempre verifica si la asignación fue exitosa y convierte el puntero `void *` al tipo adecuado.