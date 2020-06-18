//
// Created by krampus on 6/15/20.
//

#ifndef TAREA3FEDA_BINARYTREE_HPP
#define TAREA3FEDA_BINARYTREE_HPP
#include <bits/stdc++.h>
#include "User.hpp"

using namespace std;

template <typename dataType>
struct node{
    dataType data;
    node *right;
    node *left;
};
template <typename dataType>
class BinaryTree {
private:
    node<dataType> *root;
    bool stringKey;
    int size;
public:
    BinaryTree(){
        size = 0;
        root = NULL;
        stringKey = false;
    }

    void insert(dataType object){
        if (stringKey){
            // Revisa si el árbol está vacío, en cuyo caso el nodo a insertar será raíz
            if (size == 0){
                root = new node<dataType>;
                // Le entrega el valor de object
                root->data= object;
                // Inicializa los children a null
                root->left = NULL;
                root->right = NULL;
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
                    // Si el elemento tiene un key menor, buscamos a la izquierda
                    if ((x->data).getUsername() > object.getUsername()){
                        x = x->left;
                    }
                    else{
                        x = x->right;
                    }
                }
                // Se encontró donde acomodar nuevo nodo
                auto *new_node = new node<dataType>;
                // Llena los atributos
                new_node->data = object;
                new_node->left = NULL;
                new_node->right = NULL;
                // Revisa dónde acomodar al nuevo nodo
                if (object.getUsername() < (y->data).getUsername()) y->left = new_node;
                else y->right = new_node;
            }
            // Incrementa el tamaño (se insertó un elemento)
            size++;
        }
        else{
            // Revisa si el árbol está vacío, en cuyo caso el nodo a insertar será raíz
            if (size == 0){
                root = new node<dataType>;
                // Le entrega el valor de object
                root->data = object;
                // Inicializa los children a null
                root->left = NULL;
                root->right = NULL;
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
                    if (stod((x->data).getUserId())> stod(object.getUserId())){
                        x = x->left;
                    }
                    else{
                        x = x->right;
                    }
                }
                // Se encontró donde acomodar nuevo nodo
                auto *new_node = new node<dataType>;
                // Llena los atributos
                new_node->data = object;
                new_node->left = NULL;
                new_node->right = NULL;
                // Revisa dónde acomodar al nuevo nodo
                if (stod(object.getUserId()) < stod((y->data).getUserId()))  y->left = new_node;
                else y->right = new_node;
            }
            // Incrementa el tamaño (se insertó un elemento)
            size++;
        }


    }
    node<dataType> * search(string x){
        cout << "NODE: " << sizeof(node<User>);
        if (stringKey){
            // Comienza a buscar desde la raíz
            node<dataType> *aux = root;
            // Comienza a buscar
            while(aux != NULL){
                // Si lo encontró, retorna
                if ((aux->data).getUsername() == x) return aux;
                    // Si no, se va hacia un lado o al otro
                else if ((aux->data).getUsername() < x) aux = aux->right;
                else aux = aux->left;
            }
            // Salió del while, implica no pudo encontrarlo
            return NULL;
        }
        else{
            // Comienza a buscar desde la raíz
            node<dataType> *aux = root;
            // Comienza a buscar
            while(aux != NULL){
                // Si lo encontró, retorna
                if (stod((aux->data).getUserId()) == stod(x)) return aux;
                // Si no, se va hacia un lado o al otro
                else if (stod((aux->data).getUserId()) < stod(x)) aux = aux->right;
                else aux = aux->left;
            }
            // Salió del while, implica no pudo encontrarlo
            return NULL;
        }

        }


};



#endif //TAREA3FEDA_BINARYTREE_HPP
