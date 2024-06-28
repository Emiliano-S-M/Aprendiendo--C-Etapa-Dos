# `strspn` - Longitud del Segmento Inicial que Contiene Solo Caracteres de otra Cadena

La función `strspn` calcula la longitud del segmento inicial de una cadena (s1) que solo contiene caracteres presentes en otra cadena (s2).

**Sintaxis**

```c
size_t strspn(const char *s1, const char *s2);
```

**Parámetros**
- **s1:** La cadena que se va a analizar.

- **s2:** La cadena que contiene los caracteres permitidos en el segmento inicial de s1.

**Valor de Retorno**

Devuelve la longitud del segmento inicial de `s1` que solo contiene caracteres presentes en `s2`.

### [Código --> aquí](./strspn.c)

**Explicación del Ejemplo**

1. Declaración de las cadenas: `char s1[] = "123abc456";` y `char s2[] = "1234567890";`.
1. Cálculo del segmento inicial: `len = strspn(s1, s2);` devuelve la longitud del segmento inicial de `s1` que solo contiene caracteres presentes en `s2`. En este caso, "123" (longitud 3).
1. Impresión del resultado: Se muestra el valor de `len`.


# `strcspn` - Longitud del Segmento Inicial que No Contiene Ningún Carácter de otra Cadena

La función `strcspn` calcula la longitud del segmento inicial de una cadena (s1) que no contiene ninguno de los caracteres presentes en otra cadena (s2).

```c
size_t strcspn(const char *s1, const char *s2);
```

**Parámetros**

- s1: La cadena que se va a analizar.
- s2: La cadena que contiene los caracteres prohibidos en el segmento inicial de s1.

**Valor de Retorno**

Devuelve la longitud del segmento inicial de s1 que no contiene ninguno de los caracteres presentes en s2.

### [Código --> aquí](strcspn.c)

**Explicación del Ejemplo**
1. **Declaración de las cadenas:** `char s1[] = "123abc456";` y `char s2[] = "abc";`.
1. **Cálculo del segmento inicial:** `len = strcspn(s1, s2);` devuelve la longitud del segmento inicial de `s1` que no contiene ninguno de los caracteres presentes en `s2`. En este caso, "123" (longitud 3).
1. **Impresión del resultado:** Se muestra el valor de `len`.

Entonces, podemos decir que:
- `strspn`: Devuelve la longitud del segmento inicial de una cadena que solo contiene caracteres de otra cadena.
- `strcspn`: Devuelve la longitud del segmento inicial de una cadena que no contiene ninguno de los caracteres de otra cadena.

Estas funciones son útiles para analizar y procesar cadenas, especialmente cuando necesitas validar segmentos específicos de una cadena basada en ciertos conjuntos de caracteres permitidos o prohibidos.