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

### [Código --> aquí](./arbolesBinarios.c)

Ahora, para saber como dibujar el arbol de forma correcta, podemos hacerlo de dos formas, usando el resultado de PreOrden e InOrden, o los resultados de PostOrden e InOrden, formando tablas, y usaremos a InOrden para la parte superior o encabezados de la tabla, y dependiendo de lo que elijamos, ya sea PreOrden o PostOrden, lo usaremos para la parte lateral, por lo que podriamos tener una de las siguientes tablas.

**Nuestro programa dibuja las salidas siguientes:**

- Recorrido en **Preorden**: 10 5 3 1 4 7 9 15 14 17 16 20 
- Recorrido en **Inorden**: 1 3 4 5 7 9 10 14 15 16 17 20 
- Recorrido en **Postorden**: 1 4 3 9 7 5 14 16 20 17 15 10

Antes de crear nuestras tablas, debemos de considerar que para **PreOrden** Se escribe de arriba hacia abajo, y **PostOrden** de abajo hacia arriba

Con eso aclarado, nuestros diagramas se ven asi:

[![01-07-2024-0004.jpg](https://i.postimg.cc/4xdMb4Hn/01-07-2024-0004.jpg)](https://postimg.cc/mtv8TswG)


Usamos los colores para representar un **"muro"** que no nos permite pasarnos a un lado incorrecto, ahora, para uninir los nodos, uniremos el nodo raiz(el que este mas alto en la grafica) con el nodo mas alto tanto a la izquierda como a la derecha del nodo, pero nunca pasando por encima de el muro, por lo que tendriamos lo siguiente.

[![02-07-2024-0001.jpg](https://i.postimg.cc/HLTt4Bhz/02-07-2024-0001.jpg)](https://postimg.cc/bZFbqH8S)

Como siguiente paso vamos a eliminar los **"muros"**, los nombres y los numeros que componen la tabla, quedando nuestro grafico solo con las celdas de la siguiente forma.

[![02-07-2024-0002.jpg](https://i.postimg.cc/8cGWN5gH/02-07-2024-0002.jpg)](https://postimg.cc/Vr75Fz6r)

Ahora, vamos a alinear las conexiones de los nodos, el primer nodo al que se conecte el nodo superior, sea izquierdo o derecho representara un nuevo nivel, y deberemos de alinear ambos lados a ese mismo nivel, ahora, a este nodo lo consideraremos temporalmente nodo raíz, y haremos lo mismo con sus nodos hijos.

Nuestro **Primer Nivel** quedaria de esta forma.
[![02-07-2024-0003.jpg](https://i.postimg.cc/jSfMxDpV/02-07-2024-0003.jpg)](https://postimg.cc/Wd2GS1pS)

Nuestro **Segundo Nivel** quedaria de esta forma.
[![02-07-2024-0004.jpg](https://i.postimg.cc/DZc2tyvL/02-07-2024-0004.jpg)](https://postimg.cc/phpbjvnL)

Nuestro **Tercer Nivel** quedaria de esta forma.
[![02-07-2024-0005.jpg](https://i.postimg.cc/rwmKxHGM/02-07-2024-0005.jpg)](https://postimg.cc/vcJYd3SN)

Y eliminando la tabla de fondo, tenemos nuestros graficos de arboles binarios terminados que al final son exactamente iguales. Lo que quiere decir, que nuestra representaion es correcta.

[![02-07-2024-0006.jpg](https://i.postimg.cc/501JqYcL/02-07-2024-0006.jpg)](https://postimg.cc/cKDPdJLL)

## Funcion para busqueda Binaria

Ahora agregaremos una funcion para hacer una busqueda binaria, de la siguiente forma:

```c
int search(struct TreeNode* root, int key, int* steps) {
    if (root == NULL) {
        printf("Nodo no encontrado\n");
        return 0;
    }
    
    *steps += 1;
    
    if (root->data == key) {
        printf("Nodo encontrado: %d\n", root->data);
        return 1;
    }
    
    printf("Nodo actual: %d\n", root->data);
    
    if (key < root->data) {
        return search(root->left, key, steps);
    } else {
        return search(root->right, key, steps);
    }
}
```

**Detalles de la función**

1. **Declaración de la Función:**
    ```c
    int search(struct TreeNode* root, int key, int* steps)
    ```

    - **root:** El nodo raíz del árbol o subárbol actual.
    - **key:** El valor del nodo que estamos buscando.
    - **steps:** Un puntero a un entero que cuenta los pasos realizados durante la búsqueda.

2. **Condición de Base - Árbol Vacío:**
    ```c
    if (root == NULL) {
    printf("Nodo no encontrado\n");
    return 0;
    }
    ```
    - Si el nodo actual (`root`) es `NULL`, el árbol o subárbol está vacío, por lo que el nodo con el valor `key` no se encuentra en el árbol.
    - Imprime un mensaje indicando que el nodo no fue encontrado y retorna `0`.

3. **Incremento del Contador de Pasos:**
    ```c
    *steps += 1;
    ```
    - Incrementa el contador de pasos (`steps`) en uno, ya que estamos visitando un nuevo nodo.

4. **Condición de Éxito - Nodo Encontrado:**
    ```c
        if (root->data == key) {
        printf("Nodo encontrado: %d\n", root->data);
        return 1;
    }
    ```
    - Si el valor del nodo actual (`root->data`) es igual al valor buscado (`key`), hemos encontrado el nodo.
    - Imprime un mensaje indicando que el nodo fue encontrado y retorna `1`.
5. **Impresión del Nodo Actual:**
    ```c
    printf("Nodo actual: %d\n", root->data);
    ```
    - Imprime el valor del nodo actual. Esto nos ayuda a rastrear el camino recorrido durante la búsqueda.
6. **Búsqueda Recursiva:**
    ```c
    if (key < root->data) {
        return search(root->left, key, steps);
    } else {
        return search(root->right, key, steps);
    }
    ```
    - Si el valor buscado (`key`) es menor que el valor del nodo actual (`root->data`), la búsqueda continúa en el subárbol izquierdo (`root->left`).
    - Si el valor buscado (`key`) es mayor que el valor del nodo actual (`root->data`), la búsqueda continúa en el subárbol derecho (`root->right`).
    - La función se llama recursivamente con el nodo hijo correspondiente y el contador de pasos actualizado.

    ### [Código --> aquí](./arbolesBinariosBusquedaBinaria.c)

## Arboles AVL

Un árbol AVL es una estructura de datos en forma de árbol binario de búsqueda (BST) que está balanceado automáticamente. La sigla "AVL" proviene de los apellidos de los inventores de este tipo de árbol, Adelson-Velsky y Landis. La característica principal de un árbol AVL es que para cada nodo del árbol, la diferencia de alturas entre el subárbol izquierdo y el subárbol derecho (conocida como el factor de equilibrio) no puede ser mayor que 1.

**Características clave del árbol AVL:**

1. **Balanceo automático**: Después de cada operación de inserción o eliminación, el árbol AVL ajusta automáticamente sus alturas para mantener el balance. Esto asegura que la altura del árbol sea O(log n), donde n es el número de nodos en el árbol.

2. **Propiedad de balanceo**: Para cada nodo del árbol AVL, la diferencia de alturas entre el subárbol izquierdo y el subárbol derecho no puede ser mayor que 1. Formalmente, para cada nodo N del árbol AVL, la siguiente propiedad debe cumplirse: `|altura(N->izquierdo) - altura(N->derecho)| <= 1`.

3. **Eficiencia**: Las operaciones de búsqueda, inserción y eliminación en un árbol AVL tienen un tiempo promedio de O(log n), debido a su estructura balanceada.

**Funcionamiento y operaciones:**

1. **Inserción**: Cuando se inserta un nuevo nodo en un árbol AVL, se realiza como en un árbol binario de búsqueda estándar. Luego, se verifica si se ha violado la propiedad de balance del árbol AVL. Si es así, se realizan rotaciones simples o dobles para restaurar el balance.

2. **Eliminación**: Similar a la inserción, la eliminación se realiza como en un árbol binario de búsqueda estándar. Después de eliminar un nodo, se verifica y se restaura el balance si es necesario mediante rotaciones.

3. **Rotaciones**: Son operaciones que se utilizan para restaurar el balance en un árbol AVL. Las rotaciones pueden ser simples (a izquierda o a derecha) o dobles (combinación de rotaciones simples).

<br>
<br>

**Estructura de Nodo**

Primero, definimos la estructura del nodo y las funciones básicas para los árboles AVL:
```c
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
int max(int a, int b) {
    return (a > b) ? a : b;
}
```

**Rotaciones**
- **Rotación Simple a la Derecha**
    
    La rotación simple a la derecha se realiza para balancear el árbol cuando una inserción en el subárbol izquierdo de un subárbol izquierdo hace que el árbol se desequilibre:

    ```c
    struct TreeNode* rightRotate(struct TreeNode* y) {
        struct TreeNode* x = y->left;
        struct TreeNode* T2 = x->right;

        // Realizar rotación
        x->right = y;
        y->left = T2;

        // Actualizar alturas
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        // Devolver nueva raíz
        return x;
    }
    ```

- **Rotación Simple a la Izquierda**

    La rotación simple a la izquierda se realiza para balancear el árbol cuando una inserción en el subárbol derecho de un subárbol derecho hace que el árbol se desequilibre:

    ```c
    struct TreeNode* leftRotate(struct TreeNode* x) {
        struct TreeNode* y = x->right;
        struct TreeNode* T2 = y->left;

        // Realizar rotación
        y->left = x;
        x->right = T2;

        // Actualizar alturas
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        // Devolver nueva raíz
        return y;
    }
    ```

- **Rotación Doble a la Derecha**

    La rotación doble a la derecha se realiza cuando una inserción en el subárbol derecho de un subárbol izquierdo hace que el árbol se desequilibre. Se realiza primero una rotación simple a la izquierda seguida de una rotación simple a la derecha:

    ```c
    struct TreeNode* leftRightRotate(struct TreeNode* node) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    ```
- **Rotación Doble a la Izquierda**
    
    La rotación doble a la izquierda se realiza cuando una inserción en el subárbol izquierdo de un subárbol derecho hace que el árbol se desequilibre. Se realiza primero una rotación simple a la derecha seguida de una rotación simple a la izquierda:

    ```c
    struct TreeNode* rightLeftRotate(struct TreeNode* node) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    ```
- **Inserción**
    
    La inserción en un árbol AVL incluye verificar y mantener el equilibrio utilizando las rotaciones descritas anteriormente

    ```c
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

        node->height = 1 + max(height(node->left), height(node->right));

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
    ```

- **Recorridos**

    Para recorrer el árbol, utilizamos las mismas funciones que en los ejemplos anteriores:

    ```c
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
    ```

- **Función Principal**
    ```c
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
        root = insert(root, 9);
        root = insert(root, 14);
        root = insert(root, 17);
        root = insert(root, 16);
        root = insert(root, 20);
        root = insert(root, 2);
        root = insert(root, 6);
        root = insert(root, 8);


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
    ```
Y este codigo devuelve estos datos:
- Recorrido en **Preorden**: 10 5 3 1 2 4 7 6 9 8 15 14 17 16 20 
- Recorrido en **Inorden**: 1 2 3 4 5 6 7 8 9 10 14 15 16 17 20 
- Recorrido en **Postorden**: 2 1 4 3 6 8 9 7 5 14 16 20 17 15 10 

**Nuestro arbol tendria esta Forma**

[![02-07-2024-0007.jpg](https://i.postimg.cc/vTRdH0Mr/02-07-2024-0007.jpg)](https://postimg.cc/jwh1MQD2)

Pero, ahora, que pasa si deseamos **"Agregar Tres elementos mas"**, como por ejemplo, 21, 22, y 23

Nuestro codigo devolveria estos datos:

- Recorrido en Preorden: 10 5 3 1 2 4 7 6 9 8 17 15 14 16 21 20 22 23 
- Recorrido en Inorden: 1 2 3 4 5 6 7 8 9 10 14 15 16 17 20 21 22 23 
- Recorrido en Postorden: 2 1 4 3 6 8 9 7 5 14 16 15 20 23 22 21 17 10 

**Nuestro arbol tendria esta Forma**

[![02-07-2024-0008.jpg](https://i.postimg.cc/cLcYRzbJ/02-07-2024-0008.jpg)](https://postimg.cc/75ffDKDv)

