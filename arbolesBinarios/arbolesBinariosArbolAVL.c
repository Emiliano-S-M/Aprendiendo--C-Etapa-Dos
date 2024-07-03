#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo del árbol AVL
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    int height;
};

// Función para obtener la altura de un nodo
int height(struct TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Función para crear un nuevo nodo
struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // Nuevo nodo se agrega inicialmente en la hoja
    return node;
}

// Función para obtener el máximo de dos enteros
int maxim(int a, int b) {
    return (a > b) ? a : b;
}

struct TreeNode* rightRotate(struct TreeNode* y) {
    struct TreeNode* x = y->left;
    struct TreeNode* T2 = x->right;

    // Realizar rotación
    x->right = y;
    y->left = T2;

    // Actualizar alturas
    y->height = maxim(height(y->left), height(y->right)) + 1;
    x->height = maxim(height(x->left), height(x->right)) + 1;

    // Devolver nueva raíz
    return x;
}

struct TreeNode* leftRotate(struct TreeNode* x) {
    struct TreeNode* y = x->right;
    struct TreeNode* T2 = y->left;

    // Realizar rotación
    y->left = x;
    x->right = T2;

    // Actualizar alturas
    x->height = maxim(height(x->left), height(x->right)) + 1;
    y->height = maxim(height(y->left), height(y->right)) + 1;

    // Devolver nueva raíz
    return y;
}

struct TreeNode* leftRightRotate(struct TreeNode* node) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
}

struct TreeNode* rightLeftRotate(struct TreeNode* node) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
}

struct TreeNode* insert(struct TreeNode* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node;
    }

    node->height = 1 + maxim(height(node->left), height(node->right));

    int balance = height(node->left) - height(node->right);

    if (balance > 1 && data < node->left->data) {
        return rightRotate(node);
    }

    if (balance < -1 && data > node->right->data) {
        return leftRotate(node);
    }

    if (balance > 1 && data > node->left->data) {
        return leftRightRotate(node);
    }

    if (balance < -1 && data < node->right->data) {
        return rightLeftRotate(node);
    }

    return node;
}


void preOrder(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct TreeNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(struct TreeNode* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct TreeNode* root = NULL;
    //Unicamente cambiamos la forma de insertar los nodos
    // root = insert(root, 10);
    // insert(root, 5);
    // insert(root, 15);
    // insert(root, 3);
    // insert(root, 7);
    // insert(root, 1);
    // insert(root, 4);
    // insert(root, 9);
    // insert(root, 14);
    // insert(root, 17);
    // insert(root, 16);
    // insert(root, 20);
    // insert(root, 2);
    // insert(root, 6);
    // insert(root, 8);

    // Ahora lo haremos declarando explicitamente la creacion del nodo

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 14);
    root = insert(root, 17);
    root = insert(root, 16);
    root = insert(root, 20);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 21);
    root = insert(root, 22);
    root = insert(root, 23);


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
