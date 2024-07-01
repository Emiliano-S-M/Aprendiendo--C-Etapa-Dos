# Pilas (Stacks)

Las pilas (stacks) son una estructura de datos lineal que sigue el principio LIFO (Last In, First Out), donde el último elemento en entrar es el primero en salir. En una pila, solo se pueden realizar operaciones en un extremo llamado el "tope" de la pila.

**Conceptos Básicos**

**Tope (Top):** El último elemento añadido a la pila.
**Pila Vacía:** Una pila sin elementos.

**Operaciones Básicas**

Las operaciones básicas que se pueden realizar en una pila son:

- **push:** Añadir un elemento al tope de la pila.
- **pop:** Eliminar y devolver el elemento del tope de la pila.
- **peek:** Devolver el elemento del tope de la pila sin eliminarlo.
- **isEmpty:** Verificar si la pila está vacía.

## **Implementación de una Pila Usando Arrays**

1. **Definición de la Pila**
    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <limits.h> // Para utilizar INT_MIN

    #define MAX 1000

    struct Stack {
        int top;
        int arr[MAX];
    };
    ```
2. **Inicialización de la Pila**
    ```c
    void initStack(struct Stack* stack) {
        stack->top = -1;
    }
    ```
3. **Verificar si la Pila está Vacía**
    ```c
    int isEmpty(struct Stack* stack) {
        return stack->top == -1;
    }
    ```
4. **Añadir un Elemento (Push)**
    ```c
    void push(struct Stack* stack, int data) {
        if (stack->top >= MAX - 1) {
            printf("Desbordamiento de pila\n");
            return;
        }
        stack->arr[++stack->top] = data;
        printf("%d añadido a la pila\n", data);
    }
    ```
5. **Eliminar un Elemento (Pop)**
    ```c
        int pop(struct Stack* stack) {
        if (isEmpty(stack)) {
            printf("Subdesbordamiento de pila\n");
            return INT_MIN;
        }
        return stack->arr[stack->top--];
    }
    ```
6. **Obtener el Elemento del Tope sin Eliminarlo (Peek)**
    ```c
    int peek(struct Stack* stack) {
        if (isEmpty(stack)) {
            printf("Pila vacía\n");
            return INT_MIN;
        }
        return stack->arr[stack->top];
    }
    ```

### [Código --> aquí](./pilasUsandoArray.c)

**Explicación del Ejemplo Usando Arrays**

1. **Definición de la Pila:** La estructura `Stack` se define con un entero `top` que mantiene el índice del elemento en el tope de la pila, y un array `arr` de tamaño `MAX` que almacena los elementos de la pila.
2. **Inicialización de la Pila:** La función `initStack` inicializa la pila configurando top a `-1`, indicando que la pila está vacía.
3. **Verificar si la Pila está Vacía:** La función `isEmpty` devuelve `1` si la pila está vacía (top es `-1`) y `0` en caso contrario.
4. **Añadir un Elemento (`Push`):** La función `push` incrementa `top` y añade el elemento al array `arr`. Si la pila está llena (top es mayor o igual a `MAX - 1`), muestra un mensaje de error de desbordamiento.
5. **Eliminar un Elemento (Pop):** La función `pop` decrementa `top` y devuelve el elemento del array `arr`. Si la pila está vacía (top es `-1`), muestra un mensaje de error de subdesbordamiento y devuelve `INT_MIN`.
7. **Obtener el Elemento del Tope sin Eliminarlo (`Peek`):** La función `peek` devuelve el elemento en el tope del array `arr` sin modificar `top`. Si la pila está vacía (top es `-1`), muestra un mensaje de pila vacía y devuelve `INT_MIN`.


## Implementación de una pila usando listas enlazadas.

1. **Definición del Nodo**
    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <limits.h>

    // Definición del nodo
    struct Node {
        int data;
        struct Node* next;
    };
    ```
2. **Añadir un Elemento (`Push`)**
    ```c
    void push(struct Node** top, int data) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Error de asignación de memoria\n");
            exit(1);
        }
        newNode->data = data;
        newNode->next = *top;
        *top = newNode;
        printf("%d añadido a la pila\n", data);
    }
    ```
3. **Eliminar un Elemento (`Pop`)**
    ```c
    int pop(struct Node** top) {
        if (*top == NULL) {
            printf("Subdesbordamiento de pila\n");
            return INT_MIN;
        }
        struct Node* temp = *top;
        *top = (*top)->next;
        int popped = temp->data;
        free(temp);
        return popped;
    }
    ```
4. **Obtener el Elemento del Tope sin Eliminarlo (`Peek`)**
    ```c
    int peek(struct Node* top) {
        if (top == NULL) {
            printf("Pila vacía\n");
            return INT_MIN;
        }
        return top->data;
    }
    ```
5. **Verificar si la Pila está Vacía**
    ```c
    int isEmpty(struct Node* top) {
        return top == NULL;
    }
    ```

### [Código --> aquí](./pilasUsandoArray.c)

**Explicación del Ejemplo usando Listas Enlazadas**

1. **Definición del nodo:** Se define la estructura `Node` con un entero `data` y un puntero `next` al siguiente nodo.
2. **`Push`:** `push` añade un nuevo nodo al tope de la pila y actualiza el puntero `top`.
3. **`Pop`:** `pop` elimina el nodo del tope de la pila y actualiza el puntero `top`, devolviendo el valor del nodo eliminado.
4. **`Peek`:** `peek` devuelve el valor del nodo del tope de la pila sin eliminarlo.
5. **`isEmpty`:** `isEmpty` verifica si la pila está vacía.
6. **Función principal:** Se crean nodos, se insertan, se eliminan y se muestra el valor del tope para demostrar las operaciones.

Las pilas son una estructura de datos fundamental y se utilizan en muchas aplicaciones, como la gestión de la memoria, la evaluación de expresiones aritméticas y la implementación de llamadas a funciones.