//
// Created by krampus on 6/15/20.
//

#ifndef TAREA3FEDA_BINARYTREE_HPP
#define TAREA3FEDA_BINARYTREE_HPP
#include <bits/stdc++.h>

using namespace std;

template <typename dataType>
struct node{
    dataType data;
    int key;
    node *right;
    node *left;
};
template <typename T>
class BinaryTree {
private:
    node<T> *root;
    int size;
public:
    BinaryTree(){
        size = 0;
        root = NULL;
    }
    template <typename dataType>
    void insert(dataType data){
        // Revisa si el árbol está vacío, en cuyo caso el nodo a insertar será raíz
        if (size == 0){
            root = new node<dataType>;
            // Le entrega el valor de data
            root->data = data;
            // Inicializa los children a null
            root->left = NULL;
            root->right = NULL;
            root->key = 15;
        }
        // Tamaño != 0, al menos hay una raíz
        else{
            // Comienza a buscar el siguiente nodo vacío desde la raíz
            node<dataType> *x = root;
            // Nodo donde almacenar parcialmente mientras se recorre el árbol
            node<dataType> *y = NULL;
            // Comienza a buscar
            while(x != NULL){
                y = x;
                if (x->data > data){
                    x = x->left;
                }
                else{
                    x = x->right;
                }
            }
            // Se encontró donde acomodar nuevo nodo
            auto *new_node = new node<dataType>;
            // Llena los atributos
            new_node->data = data;
            new_node->left = NULL;
            new_node->right = NULL;
            // Revisa dónde acomodar al nuevo nodo
            if (data < y->data) y->left = new_node;
            else y->right = new_node;
        }
        // Incrementa el tamaño (se insertó un elemento)
        size++;

    }
    template <typename dataType>
    node<dataType> * search(dataType x){
        // Comienza a buscar desde la raíz
        node<dataType> *aux = root;
        // Comienza a buscar
        while(aux != NULL){
            // Si lo encontró, retorna
            if (aux->data == x) return aux;
            // Si no, se va hacia un lado o al otro
            else if (aux->data < x) aux = aux->right;
            else aux = aux->left;
        }
        // Salió del while, implica no pudo encontrarlo
        return NULL;
    };

};



#endif //TAREA3FEDA_BINARYTREE_HPP
