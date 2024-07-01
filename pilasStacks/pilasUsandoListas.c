#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definición del nodo
struct Node {
    int data;
    struct Node* next;
};

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

int peek(struct Node* top) {
    if (top == NULL) {
        printf("Pila vacía\n");
        return INT_MIN;
    }
    return top->data;
}

int isEmpty(struct Node* top) {
    return top == NULL;
}

int main() {
    struct Node* stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Elemento del tope es %d\n", peek(stack));
    printf("%d eliminado de la pila\n", pop(&stack));
    printf("Elemento del tope es %d\n", peek(stack));

    return 0;
}
