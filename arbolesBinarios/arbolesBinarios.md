# Árboles binarios: Conceptos, implementación, y operaciones.

Los árboles binarios son estructuras de datos jerárquicas donde cada nodo tiene, como máximo, dos hijos: uno izquierdo y uno derecho. Son utilizados ampliamente en informática para representar estructuras de datos complejas como árboles de expresión, árboles de búsqueda binaria, y más

**Conceptos Básicos**

1. **Nodo:** Cada elemento en un árbol binario que contiene un valor (dato) y referencias a sus hijos izquierdo y derecho (punteros).
2. **Raíz:** El nodo superior del árbol, desde donde se origina toda la estructura.
3. **Hijo Izquierdo/Derecho:** Los nodos conectados directamente debajo de un nodo, a través de los punteros izquierdo y derecho, respectivamente.
4. **Hoja:** Un nodo que no tiene hijos.
5. **Altura del Árbol:** La longitud del camino más largo desde la raíz hasta una hoja.
6. **Recorridos:** Métodos para visitar los nodos del árbol en un orden específico: `preorden`, `inorden`, y `postorden`.
    - Recorrer un árbol en **preorden**  consiste en primer lugar, examinar el dato del nodo raíz, posteriormente se recorrer el subárbol izquierdo en preorden y finalmente  se recorre el subárbol derecho en  preorden. Esto significa que para cada subárbol se debe conservar el recorrido en preorden, primero la raíz, luego la parte izquierda y posteriormente la parte derecha.
    
        **Representación gráfica del árbol binario y su recorrido en preorden**

        [![01-07-2024-0001.jpg](https://i.postimg.cc/R0G50z47/01-07-2024-0001.jpg)](https://postimg.cc/yJJrftJx)
        
    - Recorrer un árbol en **Inorden**  consiste en primer lugar en recorrer el subárbol izquierdo en Inorden, luego se examina el dato del nodo raíz, y finalmente  se recorre el subárbol derecho en  Inorden. Esto significa que para cada subárbol se debe conservar el recorrido en Inorden, es decir, primero se visita la parte izquierda, luego la raíz y posteriormente la parte derecha.

        **Representación gráfica del árbol binario y su recorrido en Inorden**

        [![01-07-2024-0002.jpg](https://i.postimg.cc/8PqrZ28m/01-07-2024-0002.jpg)](https://postimg.cc/SJfsstxn)

    - Recorrer un árbol en **Postorden**  consiste en primer lugar en recorrer el subárbol izquierdo en Postorden, luego serecorre el subárbol derecho en  Postorden y finalmente se visita el nodo raíz. Esto significa que para cada subárbol se debe conservar el recorrido en Postorden, es decir, primero se visita la parte izquierda, luego la parte derecha y por último la raíz.

    **Representación gráfica del árbol binario y su recorrido en Postorden**

    [![01-07-2024-0003.jpg](https://i.postimg.cc/4461KCdM/01-07-2024-0003.jpg)](https://postimg.cc/Wt4ZKH06)


## Implementación

Para implementar un árbol binario, necesitamos definir una estructura para los nodos y luego funciones para las operaciones básicas.

- **Definición de la Estructura del Nodo**

    ```c
    #include <stdio.h>
    #include <stdlib.h>

    struct TreeNode {
        int data;
        struct TreeNode* left;
        struct TreeNode* right;
    };
    ```
- **Función para Crear un Nuevo Nodo**

    ```c
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
    ```
- **Función para Insertar un Nuevo Nodo**
    ```c
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
    ```
## Funciones para Recorridos en el Árbol
- **Preorden (root -> left -> right)**
    ```c
    void preOrder(struct TreeNode* root) {
        if (root != NULL) {
            printf("%d ", root->data);
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    ```
-  **Inorden (left -> root -> right)**
    ```c
    void inOrder(struct TreeNode* root) {
        if (root != NULL) {
            inOrder(root->left);
            printf("%d ", root->data);
            inOrder(root->right);
        }
    }
    ```
- **Postorden (left -> right -> root)**
    ```c
    void postOrder(struct TreeNode* root) {
        if (root != NULL) {
            postOrder(root->left);
            postOrder(root->right);
            printf("%d ", root->data);
        }
    }
    ```

### [Código --> aquí](./queueArray.c)

Ahora, para saber como dibujar el arbol de forma correcta, podemos hacerlo de dos formas, usando el resultado de PreOrden e InOrden, o los resultados de PostOrden e InOrden, formando tablas, y usaremos a InOrden para la parte superior o encabezados de la tabla, y dependiendo de lo que elijamos, ya sea PreOrden o PostOrden, lo usaremos para la parte lateral, por lo que podriamos tener una de las siguientes tablas.

**Nuestro programa dibuja las salidas siguientes:**

- Recorrido en **Preorden**: 10 5 3 1 4 7 9 15 14 17 16 20 
- Recorrido en **Inorden**: 1 3 4 5 7 9 10 14 15 16 17 20 
- Recorrido en **Postorden**: 1 4 3 9 7 5 14 16 20 17 15 10

Antes de crear nuestras tablas, debemos de considerar que para **PreOrden** Se escribe de arriba hacia abajo, y **PostOrden** de abajo hacia arriba

Con eso aclarado, nuestros diagramas se ven asi:

[![01-07-2024-0004.jpg](https://i.postimg.cc/4xdMb4Hn/01-07-2024-0004.jpg)](https://postimg.cc/mtv8TswG)



