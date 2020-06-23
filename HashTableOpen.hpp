//
// Created by krampus on 6/17/20.
//

#ifndef TAREA3FEDA_HASHTABLEOPEN_HPP
#define TAREA3FEDA_HASHTABLEOPEN_HPP
#include <bits/stdc++.h>

using namespace std;


template <typename dataType>
class HashTableOpen {
private:
    // Guarda número de buckets indicada por usuario
    int buckets{};
    // Lista enlazada de punteros a arreglos
    list<dataType> *lists;
    // Para determinar qué tipo de key se usara
    bool stringKey;
public:
    HashTableOpen(int b){
        this->buckets = b;
        lists = new list<dataType>[buckets];
        stringKey = false;
    }
    int hashFunction(dataType x){
        if (stringKey){
            return -1;
        }
        else{
            return fmod(stod(x.getUserId()),buckets);
        }
    }
    void insert(dataType data){
        // Calcula el key de los datos
        int address = hashFunction(data);
        lists[address].push_back(data);
    }
    dataType search(dataType data){
        // Calcula la dirección del dato a buscar
        int address = hashFunction(data);
        if (stringKey){

        }
        else{
            // Comienza a buscar en la key-ésima lista
            for (auto x : lists[address]){
                if (stod(x.getUserId()) == stod(data.getUserId())){
                    return x;
                }

            }
        }
    }
};


#endif //TAREA3FEDA_HASHTABLEOPEN_HPP
