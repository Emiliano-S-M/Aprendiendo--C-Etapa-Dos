#include <stdio.h>
#include <stdlib.h>

// Definición del nodo
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// Crear un nuevo nodo
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

// Insertar al principio
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    newNode->next = *head;
    *head = newNode;
}

// Insertar al final
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

// Eliminar un nodo
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

// Imprimir la lista hacia adelante
void printListForward(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Imprimir la lista hacia atrás
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

// Función principal
int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 30);

    printf("Lista enlazada hacia adelante: ");
    printListForward(head);

    printf("Lista enlazada hacia atrás: ");
    printListBackward(head);

    deleteNode(&head, 20);
    printf("Después de eliminar 20 hacia adelante: ");
    printListForward(head);

    printf("Después de eliminar 20 hacia atrás: ");
    printListBackward(head);

    return 0;
}
