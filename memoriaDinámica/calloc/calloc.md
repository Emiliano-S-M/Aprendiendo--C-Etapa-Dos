# `calloc` - Asignación de Memoria Dinámica Inicializada a Cero

La función calloc (contiguous allocation) se utiliza para asignar un bloque de memoria en el heap para un número específico de elementos de un tamaño determinado, y además, inicializa todos los bytes de este bloque a cero.

**Sintaxis**

```c
void *calloc(size_t num, size_t size);
```

**Parámetros**

1. **`num:`** El número de elementos que se desean asignar.
2. **`size:`** El tamaño en bytes de cada elemento.

**Valor de Retorno**

- **Puntero al bloque de memoria asignado:** Si la asignación es exitosa, `calloc` devuelve un puntero al primer byte del bloque de memoria asignado e inicializado a cero.
- **`NULL`**: Si la asignación falla (por ejemplo, si no hay suficiente memoria disponible), `calloc` devuelve `NULL`.

**Uso de calloc**

`calloc` es útil cuando se necesita asegurar que la memoria asignada esté inicializada a cero, lo cual puede ser importante para evitar errores al trabajar con datos no inicializados.

### [Código --> aquí](./calloc.c)

**Explicación del Ejemplo**
- **Declaración de variables:** `int *array;` declara un puntero a `int` para el array, `int n;` para el tamaño del array, y `int i;` como índice para los bucles.
- **Lectura del tamaño del array:** Se pide al usuario que ingrese el tamaño del array.
- **Asignación de memoria:** `array = (int *)calloc(n, sizeof(int));` asigna memoria para `n` enteros y asegura que cada elemento esté inicializado a cero.
    1. **`n`:** Número de elementos.
    2. **`sizeof(int)`:** Tamaño de cada elemento en bytes.
    3. **Casting del puntero:** (`int *`) convierte el puntero `void *` devuelto por `calloc` a un puntero a `int`.
- **Verificación de la asignación:** Si `calloc` devuelve `NULL`, se imprime un mensaje de error y se finaliza el programa.
- **Impresión del array inicializado:** Se muestra el contenido del array para verificar que todos los elementos están inicializados a cero.
- **Liberación de memoria:** `free(array);` libera la memoria asignada para evitar fugas de memoria.


**Resumen**

**`calloc`:** Función para asignar memoria dinámica inicializada a cero. Devuelve un puntero al bloque de memoria asignado e inicializado a cero o `NULL` si la asignación falla.
- **Liberación de memoria:** Usa `free` para liberar la memoria asignada y evitar fugas de memoria.
- **Uso seguro:** Siempre verifica si la asignación fue exitosa y convierte el puntero `void *` al tipo adecuado.