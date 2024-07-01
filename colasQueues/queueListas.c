#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definición del nodo
struct Node {
    int data;
    struct Node* next;
};

// Definición de la cola
struct Queue {
    struct Node* front, * rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        fprintf(stderr, "Error de asignación de memoria\n");
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

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

int peek(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Cola vacía\n");
        return INT_MIN;
    }
    return queue->front->data;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("Elemento del frente es %d\n", peek(queue));
    printf("%d eliminado de la cola\n", dequeue(queue));
    printf("Elemento del frente es %d\n", peek(queue));

    return 0;
}
