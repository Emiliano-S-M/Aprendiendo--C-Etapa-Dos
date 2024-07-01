# Colas (Queues): Implementación y operaciones.

Las colas (queues) son una estructura de datos lineal que sigue el principio FIFO (First In, First Out), donde el primer elemento en entrar es el primero en salir. En una cola, los elementos se añaden en un extremo (la parte trasera o "rear") y se eliminan en el otro extremo (la parte delantera o "front").

**Conceptos Básicos**
1. **Frente (Front):** El extremo de la cola desde donde se eliminan los elementos.

2. **Parte trasera (Rear):** El extremo de la cola donde se añaden los elementos.

3. **Cola vacía:** Una cola sin elementos.

**Operaciones Básicas**

Las operaciones básicas que se pueden realizar en una cola son:

1. **enqueue:** Añadir un elemento a la parte trasera de la cola.

2. **dequeue:** Eliminar y devolver el elemento del frente de la cola.

3. **peek:** Devolver el elemento del frente de la cola sin eliminarlo.

4. **isEmpty:** Verificar si la cola está vacía.

### **Implementación de una Cola Usando Arrays**

**Definición de la Cola**

```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Para utilizar INT_MIN

#define MAX 1000

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};
```

**Inicialización de la Cola**

```c
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        fprintf(stderr, "Error de asignación de memoria\n");
        exit(1);
    }
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;  // This is important, see the enqueue
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    if (queue->array == NULL) {
        fprintf(stderr, "Error de asignación de memoria\n");
        exit(1);
    }
    return queue;
}
```

**Verificar si la Cola está Vacía**

```c
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}
```

**Verificar si la Cola está Llena**
```c
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}
```

**Añadir un Elemento (Enqueue)**
```c
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Cola llena\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d añadido a la cola\n", item);
}
```

**Eliminar un Elemento (Dequeue)**
```c
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Cola vacía\n");
        return INT_MIN;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
```

**Obtener el Elemento del Frente sin Eliminarlo (Peek)**
```c
int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Cola vacía\n");
        return INT_MIN;
    }
    return queue->array[queue->front];
}
```

### [Código --> aquí](./queueArray.c)

#### **Explicación del Ejemplo Usando Arrays**
1. **Definición de la Cola:** La estructura `Queue` se define con enteros `front`, `rear` y `size` para mantener los índices y el tamaño actual de la cola, una `capacity` para la capacidad máxima, y un puntero `array` para almacenar los elementos de la cola.

2. **Inicialización de la Cola:** La función `createQueue` asigna memoria para una nueva cola y su `array`, inicializa los valores `front`, `rear`, `size`, y `capacity`.

3. **Verificar si la Cola está Vacía:** La función `isEmpty` devuelve `1` si la cola está vacía (`size` es `0`) y `0` en caso contrario.

4. **Verificar si la Cola está Llena:** La función `isFull` devuelve `1` si la cola está llena (`size` es igual a `capacity`) y `0` en caso contrario.

5. **Añadir un Elemento (`Enqueue`):** La función `enqueue` incrementa `rear` de forma circular y añade el elemento al array `array`. Si la cola está llena, muestra un mensaje de error de cola llena.

6. **Eliminar un Elemento (`Dequeue`):** La función `dequeue` incrementa `front` de forma circular y devuelve el elemento del array `array`. Si la cola está vacía, muestra un mensaje de error de cola vacía y devuelve `INT_MIN`.

7. **Obtener el Elemento del Frente sin Eliminarlo (Peek):** La función `peek` devuelve el elemento en el frente del array `array` sin modificar `front`. Si la cola está vacía, muestra un mensaje de cola vacía y devuelve `INT_MIN`.

8. **Función Principal:** La función principal `main` demuestra la creación de una cola, la inserción de elementos usando `enqueue`, la eliminación de elementos usando `dequeue`, y la visualización del elemento en el frente usando `peek`.

### **Implementación de una Cola Usando Listas Enlazadas**

**Definición del Nodo**
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

**Definición de la Cola**
```c
struct Queue {
    struct Node* front, * rear;
};
```

**Inicialización de la Cola**
```c
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        fprintf(stderr, "Error de asignación de memoria\n");
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}
```

**Añadir un Elemento (Enqueue)**
```c
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error de asignación de memoria\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        printf("%d añadido a la cola\n", data);
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
    printf("%d añadido a la cola\n", data);
}
```

**Eliminar un Elemento (Dequeue)**
```c
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Cola vacía\n");
        return INT_MIN;
    }

    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}
```
**Obtener el Elemento del Frente sin Eliminarlo (Peek)**
```c
int peek(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Cola vacía\n");
        return INT_MIN;
    }
    return queue->front->data;
}
```

**Verificar si la Cola está Vacía**
```c
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}
```
### [Código --> aquí](./queueListas.c)

**Explicación del Ejemplo Usando Listas Enlazadas**

1. **Definición del Nodo y de la Cola:** La estructura `Node` se define con un entero `data` y un puntero `next` al siguiente nodo. La estructura `Queue` se define con dos punteros `front` y `rear` para mantener los extremos de la cola.

2. **Inicialización de la Cola:** La función `createQueue` asigna memoria para una nueva cola y configura `front` y `rear` como `NULL`.

3. **Añadir un Elemento (`Enqueue`):** La función `enqueue` asigna memoria para un nuevo nodo, configura su `data` y `next`, y lo añade al final de la cola. Si la cola está vacía, el nuevo nodo se convierte tanto en `front` como en `rear`.

4. **Eliminar un Elemento (`Dequeue`):** La función `dequeue` elimina el nodo en el frente de la cola y devuelve su `data`. Si la cola se vuelve vacía después de la eliminación, rear también se configura como `NULL`.

5. **Obtener el Elemento del Frente sin Eliminarlo (`Peek`):** La función `peek` devuelve el data del nodo en el frente de la cola sin modificar `front`. Si la cola está vacía, muestra un mensaje de cola vacía y devuelve `INT_MIN`.

6. **Verificar si la Cola está Vacía:** La función `isEmpty` devuelve `1` si la cola está vacía (`front` es `NULL`) y `0` en caso contrario.

7. **Función Principal:** La función principal `main` demuestra la creación de una cola, la inserción de elementos usando `enqueue`, la eliminación de elementos usando `dequeue`, y la visualización del elemento en el frente usando `peek`.