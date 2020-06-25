//
// Created by krampus on 6/17/20.
//

#ifndef TAREA3FEDA_HASHTABLEOPEN_HPP
#define TAREA3FEDA_HASHTABLEOPEN_HPP
#include <bits/stdc++.h>

using namespace std;

/**
 * Implementa tabla hash con chaining
 * @tparam dataType: Tipo de dato de la estructura de dato. Por ahora, solo acepta o bjeto user
 */
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
        stringKey = true;
    }
    /**
     * Calcula la key asociada al tipo de dato entregado. Implementa función hash dato % buckets
     * @param x: Dato al cual calcularle la función hash. Por ahora solo acepta objetos  tipo User
     * @return: Key como entero
     */
    int hashFunction(dataType x){
        if (stringKey){
            string user = x.getUsername();
            int sum = 0;
            for (int i = 0; i < user.length(); i++){
                sum = sum + int(user[i]);
            }
            return sum % buckets;
        }
        else{
            return fmod(stod(x.getUserId()),buckets);
        }
    }

    /**
     * Implementa insert de la estructura de datos tabla hash
     * @param data: Tipo de dato. Solo acepta objeto User
     */
    void insert(dataType data){
        // Calcula el key de los datos
        int address = hashFunction(data);
        // Inserta el dato en la lista enlazada correspondiente
        lists[address].push_back(data);
    }
    /**
     * Implementa el método búsqueda de una tabla hash
     * @param data: Dato a buscar
     * @return: Retorna el dato, null si no lo encuentra
     */
    dataType search(dataType data){
        // Calcula la dirección del dato a buscar
        int address = hashFunction(data);
        if (stringKey){
            // Busca en cada uno de los elementos de la lista
            for (auto x : lists[address]){
                if (x.getUsername() == data.getUsername()){
                    return x;
                }
            }
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
