#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

struct Stack {
    int top;
    int arr[MAX];
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int data) {
    if (stack->top >= MAX - 1) {
        printf("Desbordamiento de pila\n");
        return;
    }
    stack->arr[++stack->top] = data;
    printf("%d añadido a la pila\n", data);
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Subdesbordamiento de pila\n");
        return INT_MIN;
    }
    return stack->arr[stack->top--];
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Pila vacía\n");
        return INT_MIN;
    }
    return stack->arr[stack->top];
}

int main() {
    struct Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Elemento del tope es %d\n", peek(&stack));
    printf("%d eliminado de la pila\n", pop(&stack));
    printf("Elemento del tope es %d\n", peek(&stack));

    return 0;
}
