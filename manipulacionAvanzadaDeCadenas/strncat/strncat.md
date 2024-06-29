# `strncat` - Concatenar Cadenas con Límite

La función `strncat` se utiliza para concatenar una cantidad limitada de caracteres de una cadena al final de otra. Esto es útil para asegurar que no se agreguen más caracteres de los necesarios y para evitar posibles desbordamientos de búfer.

**Sintaxis**

```c
char *strncat(char *dest, const char *src, size_t n);
```

**Parámetros**
- **dest:** Puntero a la cadena de destino donde se concatenará `src`.
- **src**: Puntero a la cadena de origen que se desea concatenar.
- **n**: Número máximo de caracteres a concatenar desde `src`.

**Valor de Retorno**

Devuelve un puntero a la cadena de destino `dest`.

**Funcionamiento**
- Concatenar hasta `n` caracteres de `src` al final de `dest`.
- Asegura que la cadena de destino esté terminada con un carácter nulo.

### [Código --> aquí](./strncat.c)

**Explicación del Ejemplo**

- **Declaración de las cadenas:** `char dest[20] = "Hola";` y `char src[] = ", mundo!";`.
- **Concatenación con límite:** `strncat(dest, src, 7);` concatena los primeros 7 caracteres de `src` al final de `dest`.
- **Impresión del resultado:** Se muestra la cadena de destino con el contenido concatenado.

`strncat`: Concatenar hasta `n` caracteres de una cadena al final de otra, asegurando que la cadena de destino esté correctamente terminada.

Esta Función es útil para manejar cadenas de manera segura, evitando desbordamientos de búfer y otros problemas relacionados con la manipulación de cadenas en C.