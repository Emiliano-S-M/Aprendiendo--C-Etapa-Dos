#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo del árbol binario
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Función para crear un nuevo nodo
struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (node == NULL) {
        fprintf(stderr, "Error de asignación de memoria\n");
        exit(1);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Función para insertar un nuevo nodo en el árbol
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Función para recorrer el árbol en preorden (raíz -> izquierda -> derecha)
void preOrder(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Función para recorrer el árbol en inorden (izquierda -> raíz -> derecha)
void inOrder(struct TreeNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Función para recorrer el árbol en postorden (izquierda -> derecha -> raíz)
void postOrder(struct TreeNode* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    insert(root, 4);
    insert(root, 9);
    insert(root, 14);
    insert(root, 17);
    insert(root, 16);
    insert(root, 20);

    printf("Recorrido en Preorden: ");
    preOrder(root);
    printf("\n");

    printf("Recorrido en Inorden: ");
    inOrder(root);
    printf("\n");

    printf("Recorrido en Postorden: ");
    postOrder(root);
    printf("\n");

    return 0;
}
