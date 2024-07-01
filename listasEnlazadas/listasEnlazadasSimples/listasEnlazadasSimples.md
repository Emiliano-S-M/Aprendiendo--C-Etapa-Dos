# Listas enlazadas simples.

Las listas enlazadas simples (o simplemente listas enlazadas) son una estructura de datos fundamental en C que se utiliza para almacenar una colección de elementos. Cada elemento en una lista enlazada se llama nodo, y cada nodo contiene dos partes: un dato y un puntero al siguiente nodo en la lista.

**Conceptos Básicos**
- **Nodo:** La unidad básica de una lista enlazada, que contiene un valor (dato) y un puntero al siguiente nodo.
- **Cabeza (Head):** El primer nodo en una lista enlazada.
- **Cola (Tail):** El último nodo en una lista enlazada, cuyo puntero al siguiente nodo es `NULL`.


**Definición de un Nodo**
Un nodo de una lista enlazada simple se puede definir utilizando una estructura (`struct`).

```c
#include <stdio.h>
#include <stdlib.h>

// Definición del nodo
struct Node {
    int data;
    struct Node *next;
};
```

**Creación de un Nodo**

Para crear un nuevo nodo, debes asignar memoria dinámica utilizando `malloc` y asignar el valor de datos y el puntero al siguiente nodo.

```c
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error de asignación de memoria\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
```

**Operaciones Básicas**

- **Inserción al Principio**
    ```c
    void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
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
    }
    ```
- **Eliminación de un Nodo**
    ```c
    void deleteNode(struct Node** head, int key) {
        struct Node* temp = *head;
        struct Node* prev = NULL;

        if (temp != NULL && temp->data == key) {
            *head = temp->next;
            free(temp);
            return;
        }

        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("No se encontró el nodo con el valor %d\n", key);
            return;
        }

        prev->next = temp->next;
        free(temp);
    }
    ```

- **Impresión de la Lista**
    ```c
    void printList(struct Node* head) {
        struct Node* temp = head;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    ```
    
    <br><br>


### [Código --> aquí](./listasEnlazadasSimples.c)
<br>
<br>

**Explicación del Ejemplo**

1. **Definición del nodo:** Se define la estructura `Node` con un entero `data` y un puntero `next`.
2. **Crear un nuevo nodo:** `createNode` asigna memoria para un nuevo nodo, inicializa sus valores y devuelve un puntero al nodo.
3. **Insertar al principio:** `insertAtBeginning` inserta un nuevo nodo al principio de la lista.
4. **Insertar al final:** `insertAtEnd` inserta un nuevo nodo al final de la lista.
5. **Eliminar un nodo:** `deleteNode` elimina el primer nodo que contiene el valor especificado.
6. **Imprimir la lista:** `printList` recorre la lista e imprime los valores de los nodos.
7. **Función principal:** Se crean nodos, se insertan, se eliminan y se imprime la lista para demostrar las operaciones.

Las listas enlazadas simples son una estructura de datos muy versátil y útil en muchas aplicaciones. Entender cómo funcionan y cómo manipularlas es una habilidad fundamental para cualquier programador en C.