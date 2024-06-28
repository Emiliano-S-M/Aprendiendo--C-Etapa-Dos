# `strstr` - Búsqueda de Subcadenas en C

La función `strstr` pertenece a la librería `string.h` y se utiliza para buscar una subcadena dentro de otra cadena. Es una herramienta útil cuando necesitas localizar la primera aparición de una subcadena específica dentro de una cadena más grande.

```c
char *strstr(const char *haystack, const char *needle);
```

**Parámetros**

- **haystack:** La cadena en la que se va a buscar. Es la "aguja en el pajar" donde queremos encontrar la subcadena.
- **needle:** La subcadena que estamos buscando. Es la "aguja" que queremos encontrar dentro de haystack.

<br>

**Valor de Retorno**

1. **Puntero a la primera aparición de needle en haystack**: Si `needle` se encuentra dentro de `haystack`, la función devuelve un puntero a la primera aparición de `needle` en `haystack`.

1. **NULL**: Si needle no se encuentra dentro de `haystack`, la función devuelve `NULL`.

<br>

**Funcionamiento**

La función recorre la cadena haystack buscando la primera aparición de la subcadena needle. Si la encuentra, devuelve un puntero al primer carácter de la subcadena dentro de haystack. Si no la encuentra, devuelve NULL.

### [Código --> aquí](./strstr.c)

<br>

**Explicación del Ejemplo**

1. **Declaración de las cadenas:** `char haystack[] = "Hola, mundo. Bienvenido al mundo de la programación.";` y `char needle[] = "mundo";`.
1. **Búsqueda de la subcadena:** `result = strstr(haystack, needle);`  busca la primera aparición de la subcadena `"mundo"` dentro de la cadena haystack.
1. **Verificación del resultado:**
    - Si result no es NULL, la subcadena se encontró y se imprime la posición calculada como result - haystack.
    - Si result es NULL, significa que la subcadena no se encontró en `haystack`.
<br>

**Consideraciones**

**Caso de subcadena vacía:** Si needle es una cadena vacía (""), strstr devuelve haystack.

**Sensible a mayúsculas y minúsculas:** La función distingue entre mayúsculas y minúsculas, por lo que "Mundo" y "mundo" se consideran diferentes.

**Rendimiento:** Para cadenas muy largas o búsquedas repetitivas, puede ser más eficiente utilizar algoritmos más avanzados como Knuth-Morris-Pratt (KMP) o Boyer-Moore, pero ***strstr es generalmente adecuada para la mayoría de los casos prácticos.***