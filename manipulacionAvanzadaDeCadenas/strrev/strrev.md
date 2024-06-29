# `strrev` - Inversión de Cadenas (No estándar)

La función strrev no es una función estándar en C, pero es comúnmente utilizada para invertir cadenas. Dado que no forma parte de la librería estándar string.h, debes implementarla manualmente o usar alguna biblioteca específica que la incluya.

**Implementación de `strrev` - Inversión de Cadenas**

La función strrev invierte el contenido de una cadena, es decir, el primer carácter se convierte en el último, el segundo en el penúltimo, y así sucesivamente.

<br>

**Sintaxis Propuesta**
```c
char *strrev(char *str);
```

**Parámetros**
- str: La cadena que se desea invertir. Debe ser una cadena modificable (no una cadena constante).

**Valor de Retorno**
- Devuelve un puntero a la cadena invertida (que es la misma cadena que se pasó como argumento).

### [Código --> aquí](./strrev.c)

**Explicación del Código**
1. Declaración de la función strrev:

- **Validación de la cadena:** Si str es NULL, la función devuelve NULL.
- **Cálculo de la longitud:** Se obtiene la longitud de la cadena usando strlen.
- **Intercambio de caracteres:** Se utiliza un bucle for para recorrer la mitad de la cadena, intercambiando los caracteres desde los extremos hacia el centro.

2. Uso en main:

- **Cadena original:** Se declara y se inicializa la cadena str.
- **Impresión de la cadena original:** Se muestra la cadena antes de invertirla.
- **Inversión e impresión:** Se llama a strrev para invertir la cadena y se muestra el resultado.

**Consideraciones**
- **Modificación in situ:** La función strrev modifica la cadena original en su lugar. Si necesitas preservar la cadena original, asegúrate de trabajar con una copia de la cadena.
- **Cadenas no modificables:** No se debe pasar cadenas constantes (como literales de cadena) a strrev, ya que estas no pueden ser modificadas en su lugar.
- **Manejo de NULL:** La función incluye una verificación para manejar el caso en que se pase una cadena nula.

Implementar strrev puede ser muy útil cuando trabajas con manipulación de cadenas y no quieres depender de bibliotecas externas que puedan no estar disponibles en todas las plataformas.