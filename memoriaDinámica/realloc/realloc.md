# `realloc` - Redimensionar Memoria Dinámica

La función `realloc` se utiliza para cambiar el tamaño de un bloque de memoria previamente asignado mediante `malloc`, `calloc`, o una llamada anterior a `realloc`. Es útil cuando necesitas aumentar o disminuir el tamaño de un bloque de memoria sin perder los datos ya almacenados en ese bloque.

**Sintaxis**
```c
void *realloc(void *ptr, size_t size);
```

**Parámetros**

1. **`ptr`**: Puntero al bloque de memoria previamente asignado que se desea redimensionar. Si es `NULL`, `realloc` actúa como `malloc`.
2. **`size`**: Nuevo tamaño en bytes para el bloque de memoria.

**Valor de Retorno**

- **Puntero al bloque de memoria redimensionado**: Si la redimensión es exitosa, `realloc` devuelve un puntero al primer byte del nuevo bloque de memoria.
- **`NULL`**: Si la redimensión falla (por ejemplo, si no hay suficiente memoria disponible), `realloc` devuelve `NULL` y el bloque original de memoria sigue siendo válido.

**Uso de `realloc`**

`realloc` es especialmente útil cuando trabajas con estructuras de datos dinámicas cuyo tamaño no puedes predecir de antemano, como arrays dinámicos.

### [Código --> aquí](./realloc.c)

**Explicación del Ejemplo**

1. **Declaración de variables**: `int *array;` declara un puntero a `int` para el array, `int n = 5;` para el tamaño inicial del array, `int new_size;` para el nuevo tamaño del array, y `int i;` como índice para los bucles.
2. **Asignación de memoria inicial:** `array = (int *)malloc(n * sizeof(int));` asigna memoria para n enteros.
    - **Verificación de la asignación:** Si `malloc` devuelve `NULL`, se imprime un mensaje de error y se finaliza el programa.
3. **Inicialización del array:** Se inicializan los primeros `n` elementos del array con valores.
4. **Impresión del array inicial:** Se muestra el contenido del array inicial.
5. **Redimensionamiento del array:** `array = (int *)realloc(array, new_size * sizeof(int));` redimensiona el array a `new_size` enteros.
    - **Verificación de la redimensión:** Si `realloc` devuelve `NULL`, se imprime un mensaje de error y se finaliza el programa.
6. **Inicialización de los nuevos elementos:** Se inicializan los nuevos elementos del array.
7. **Impresión del array redimensionado:** Se muestra el contenido del array redimensionado.
8. **Liberación de memoria:** `free(array); `libera la memoria asignada para evitar fugas de memoria.

**Consideraciones**

- **Redimensión a menor tamaño:** Si `size` es menor que el tamaño actual, el contenido del bloque se truncará, y los datos después del nuevo tamaño se perderán.
- **Redimensión a mayor tamaño:** Si `size` es mayor que el tamaño actual, el nuevo bloque tendrá el contenido del bloque original más espacio no inicializado adicional.
- **Puntero `NULL`:** Si `ptr` es `NULL`, `realloc` actúa como `malloc` y asigna un nuevo bloque de memoria del tamaño especificado.
- **Liberación de memoria original:** Si `realloc` falla, el bloque original de memoria aún es válido y debe ser liberado con `free`.

**Resumen**

- **`realloc`:** Función para redimensionar un bloque de memoria previamente asignado. Devuelve un puntero al bloque redimensionado o `NULL` si la redimensión falla.
- **Liberación de memoria:** Usa `free` para liberar la memoria asignada y evitar fugas de memoria.
- **Uso seguro:** Siempre verifica si la redimensión fue exitosa y convierte el puntero `void *` al tipo adecuado.