# Listas Enlazadas Dobles

Las listas enlazadas dobles son una extensión de las listas enlazadas simples que permiten una mayor flexibilidad en la manipulación de los nodos. En una lista enlazada doble, cada nodo contiene un puntero al siguiente nodo y un puntero al nodo anterior, lo que permite recorrer la lista en ambas direcciones.

**Conceptos Básicos**

- **Nodo:** La unidad básica de una lista enlazada doble, que contiene un valor (dato), un puntero al siguiente nodo y un puntero al nodo anterior.
- **Cabeza (Head):** El primer nodo en una lista enlazada doble.
- **Cola (Tail):** El último nodo en una lista enlazada doble, cuyo puntero al siguiente nodo es `NULL`.

**Definición de un Nodo**

Un nodo de una lista enlazada doble se puede definir utilizando una estructura (`struct`).

```c
#include <stdio.h>
#include <stdlib.h>

// Definición del nodo
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};
```

**Creación de un nodo**

ara crear un nuevo nodo, debes asignar memoria dinámica utilizando malloc y asignar el valor de datos, el puntero al siguiente nodo y el puntero al nodo anterior.

```c
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error de asignación de memoria\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
```

**Operaciones Básicas**

- **Inserción al Principio**

    ```c
    void insertAtBeginning(struct Node** head, int data) {
        struct Node* newNode = createNode(data);
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        newNode->next = *head;
        *head = newNode;
    }
    ```
- **Inserción al Final**
    ```c
    void insertAtEnd(struct Node** head, int data) {
        struct Node* newNode = createNode(data);
        if (*head == NULL) {
            *head = newNode;
            return;
        }
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    ```
- **Eliminación de un Nodo**
    ```c
    void deleteNode(struct Node** head, int key) {
        struct Node* temp = *head;

        while (temp != NULL && temp->data != key) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("No se encontró el nodo con el valor %d\n", key);
            return;
        }

        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            *head = temp->next;
        }

        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        free(temp);
    }
    ```
- **Impresión de la lista hacia adelante**
    ```c
    void printListForward(struct Node* head) {
        struct Node* temp = head;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    ```
- **Impresión de la lista hacia atras**
    ```c
    void printListBackward(struct Node* head) {
        struct Node* temp = head;
        if (temp == NULL) {
            return;
        }
        
        while (temp->next != NULL) {
            temp = temp->next;
        }

        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->prev;
        }
        printf("NULL\n");
    }
    ```

### [Código --> aquí](./listasEnlazadasDobles.c)

<br>

**Explicación del Ejemplo**

1. **Definición del nodo:** Se define la estructura `Node` con un entero `data`, un puntero `next` al siguiente nodo y un puntero `prev` al nodo anterior.
2. **Crear un nuevo nodo:** `createNode` asigna memoria para un nuevo nodo, inicializa sus valores y devuelve un puntero al nodo.
3. **Insertar al principio:** `insertAtBeginning` inserta un nuevo nodo al principio de la lista y actualiza los punteros `prev` y `next` según sea necesario.
4. **Insertar al final:** `insertAtEnd` inserta un nuevo nodo al final de la lista y actualiza los punteros `prev` y `next` según sea necesario.
5. **Eliminar un nodo:** `deleteNode` elimina el primer nodo que contiene el valor especificado y actualiza los punteros `prev` y `next` de los nodos adyacentes.
6. **Imprimir la lista hacia adelante:** `printListForward` recorre la lista desde el principio hasta el final e imprime los valores de los nodos.
7. **Imprimir la lista hacia atrás:** `printListBackward` recorre la lista desde el final hasta el principio e imprime los valores de los nodos.
8. **Función principal:** Se crean nodos, se insertan, se eliminan y se imprime la lista en ambas direcciones para demostrar las operaciones.

Las listas enlazadas dobles son una estructura de datos versátil que permite un acceso eficiente y flexible a los nodos en ambas direcciones. Entender cómo funcionan y cómo manipularlas es una habilidad fundamental para cualquier programador en C.