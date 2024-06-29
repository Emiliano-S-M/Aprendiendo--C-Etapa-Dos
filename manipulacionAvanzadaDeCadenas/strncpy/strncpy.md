# `strncpy` - Copiar Cadenas con Límite

La función `strncpy` se utiliza para copiar una cantidad limitada de caracteres de una cadena a otra. Esto es útil para asegurar que no se copien más caracteres de los necesarios y para evitar posibles desbordamientos de búfer.

**Sintaxis**
```c
char *strncpy(char *dest, const char *src, size_t n);
```

**Parámetros**
1. **dest:** Puntero al búfer de destino donde se copiará la cadena.
1. **src:** Puntero a la cadena de origen que se desea copiar.
1. **n:** Número máximo de caracteres a copiar desde src.

**Valor de Retorno**

Devuelve un puntero a la cadena de destino `dest`.

**Funcionamiento**

- Copia hasta n caracteres de src a dest.
- Si `src` tiene menos de `n` caracteres, se agregan caracteres nulos ('`\0`') a `dest` hasta alcanzar `n` caracteres.
- Si `src` tiene más de `n` caracteres, solo se copian los primeros `n` caracteres y `dest` no se termina automáticamente con un carácter nulo.

### [Código --> aquí](./strncpy.c)

**Explicación del Ejemplo**

- **Declaración de las cadenas:** `char src[] = "Hola, mundo!";` y `char dest[20];`.
- **Copia con límite:** `strncpy(dest, src, 5);` copia los primeros 5 caracteres de `src` a `dest`.
- **Terminación con nulo:** `dest[5] = '\0';` asegura que la cadena de destino esté correctamente terminada.
- `Impresión del resultado:` Se muestra la cadena de destino.

<br><br>
**En resumen:**

`strncpy`: Copia hasta n caracteres de una cadena a otra, rellenando con caracteres nulos si es necesario.

Esta Función es útil para manejar cadenas de manera segura, evitando desbordamientos de búfer y otros problemas relacionados con la manipulación de cadenas en C.