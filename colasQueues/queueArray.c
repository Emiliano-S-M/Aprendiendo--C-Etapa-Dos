#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        fprintf(stderr, "Error de asignación de memoria\n");
        exit(1);
    }
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    if (queue->array == NULL) {
        fprintf(stderr, "Error de asignación de memoria\n");
        exit(1);
    }
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

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

int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Cola vacía\n");
        return INT_MIN;
    }
    return queue->array[queue->front];
}

void main() {
    struct Queue* queue = createQueue(MAX);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("Elemento del frente es %d\n", peek(queue));
    printf("%d eliminado de la cola\n", dequeue(queue));
    printf("Elemento del frente es %d\n", peek(queue));

    getcahr();
}
