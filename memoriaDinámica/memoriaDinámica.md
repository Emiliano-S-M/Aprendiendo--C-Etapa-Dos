# Memoria Dinámica en C

La memoria dinámica es una forma de asignar memoria en tiempo de ejecución, en lugar de hacerlo en tiempo de compilación. Esto es útil cuando no se conoce de antemano el tamaño exacto de la memoria necesaria para una aplicación. En C, la gestión de la memoria dinámica se realiza mediante las funciones `malloc`, `calloc`, `realloc` y `free`, todas ellas definidas en la biblioteca estándar `<stdlib.h>`.

- [`malloc` - Asignación de Memoria Dinámica](./malloc/malloc.md)
- [`calloc` - Asignación de Memoria Dinámica Inicializada en 0](./calloc/calloc.md)
- [`realloc` - Redimensionar Memoria Dinámica](./realloc/realloc.md)


**Resumen**
- **`malloc`:** Asigna un bloque de memoria contigua y devuelve un puntero a la memoria. La memoria no está inicializada.
- **`calloc`:** Asigna memoria para un número de elementos y la inicializa a cero.
- **`realloc`:** Redimensiona un bloque de memoria previamente asignado.
- **`free`:** Libera un bloque de memoria previamente asignado.
