#include <stdio.h>
#include <stdlib.h>

// Definición de las categorías
#define HOTEL 1
#define RESTAURANTE 2
#define TRANSPORTE 3

// Estructura del nodo para el árbol
struct NodoArbol {
    int codigoRNT;
    int fechaVencimiento;
    int categoria; // Categoria del nodo: HOTEL, RESTAURANTE, o TRANSPORTE
    struct NodoArbol* izquierda;
    struct NodoArbol* derecha;
};
typedef struct NodoArbol NodoArbol;

NodoArbol* crearNodo(int codigoRNT, int fechaVencimiento, int categoria) {
    NodoArbol* nuevoNodo = (NodoArbol*)malloc(sizeof(NodoArbol));
    nuevoNodo->codigoRNT = codigoRNT;
    nuevoNodo->fechaVencimiento = fechaVencimiento;
    nuevoNodo->categoria = categoria;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;
    return nuevoNodo;
}

// Función para insertar un nodo en el árbol
NodoArbol* insertarNodo(NodoArbol* raiz, int codigoRNT, int fechaVencimiento, int categoria) {
    if (raiz == NULL) {
        return crearNodo(codigoRNT, fechaVencimiento, categoria);
    }

    if (codigoRNT < raiz->codigoRNT) {
        raiz->izquierda = insertarNodo(raiz->izquierda, codigoRNT, fechaVencimiento, categoria);
    } else {
        raiz->derecha = insertarNodo(raiz->derecha, codigoRNT, fechaVencimiento, categoria);
    }

    return raiz;
}

// Función para recorrer el árbol en preorden
void preorden(NodoArbol* raiz) {
    if (raiz != NULL) {
        printf("(%d, %d, %d) ", raiz->codigoRNT, raiz->fechaVencimiento, raiz->categoria);
        preorden(raiz->izquierda);
        preorden(raiz->derecha);
    }
}

// Función para recorrer el árbol en inorden
void inorden(NodoArbol* raiz) {
    if (raiz != NULL) {
        inorden(raiz->izquierda);
        printf("(%d, %d, %d) ", raiz->codigoRNT, raiz->fechaVencimiento, raiz->categoria);
        inorden(raiz->derecha);
    }
}

// Función para recorrer el árbol en posorden
void posorden(NodoArbol* raiz) {
    if (raiz != NULL) {
        posorden(raiz->izquierda);
        posorden(raiz->derecha);
        printf("(%d, %d, %d) ", raiz->codigoRNT, raiz->fechaVencimiento, raiz->categoria);
    }
}

// Función para liberar la memoria de todos los nodos del árbol
void liberarArbol(NodoArbol* raiz) {
    if (raiz != NULL) {
        liberarArbol(raiz->izquierda);
        liberarArbol(raiz->derecha);
        free(raiz);
    }
}

// Función principal
int main() {
    NodoArbol* raiz = NULL;
    int opcion, codigoRNT, fechaVencimiento, categoria;

    do {
        printf("\nMENU\n");
        printf("1. Insertar nodo\n");
        printf("2. Recorrer en preorden\n");
        printf("3. Recorrer en inorden\n");
        printf("4. Recorrer en posorden\n");
        printf("5. Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el codigo RNT del nodo: ");
                scanf("%d", &codigoRNT);
                printf("Ingrese la fecha de vencimiento del nodo: ");
                scanf("%d", &fechaVencimiento);
                printf("Ingrese la categoria del nodo (1: Hotel, 2: Restaurante, 3: Transporte): ");
                scanf("%d", &categoria);
                raiz = insertarNodo(raiz, codigoRNT, fechaVencimiento, categoria);
                break;
            case 2:
                printf("Recorrido en preorden: ");
                preorden(raiz);
                printf("\n");
                break;
            case 3:
                printf("Recorrido en inorden: ");
                inorden(raiz);
                printf("\n");
                break;
            case 4:
                printf("Recorrido en posorden: ");
                posorden(raiz);
                printf("\n");
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Por favor);
