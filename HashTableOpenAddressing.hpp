//
// Created by krampus on 6/23/20.
//

#ifndef TAREA3FEDA_HASHTABLEOPENADDRESSING_HPP
#define TAREA3FEDA_HASHTABLEOPENADDRESSING_HPP
#include <bits/stdc++.h>

using namespace std;
/**
 * Clase que implementa una hash table con con open addressing
 * @tparam dataType: Tipo de datos que va a implementar la tabla hash. Dada la forma en que está implementado, por ahora
 * solo acepta tipo de dato User.
 */

template<typename dataType>
class HashTableOpenAddressing {
private:
    // Guarda número de buckets indicada por usuario
    int buckets{};
    // Lista enlazada de punteros a arreglos
    dataType *lists;
    // Para determinar qué tipo de key se usara
    bool stringKey;
    // Lleva seguimiento del tamaño actual de la estructura
    int current_size;
public:
    // Constructor de la clase
    HashTableOpenAddressing(int b){
        this->buckets = b;
        lists = new dataType[buckets];
        stringKey = true;
        current_size = 0;
    }
    /**
     * Si dentro del control de flujo del programa se determina que se debe aumentar la tabla, esta función lo implementa
     * aumentando el tamaño al doble de forma fija
     */
    void expand_table(){
        // Tabla auxiliar donde almacenar parcialmente los valores
        dataType aux_lists[buckets];
        // Para almacenar parcialmente el tamaño
        int aux_bucket = buckets;
        // Copia los datos actuales a una tabla auxiliar
        for (int i = 0; i < buckets; i++) aux_lists[i] = lists[i];
        // Crea nueva lista con el doble del tamaño inicial
        this->lists = new dataType[buckets*2];
        // Dobla el tamaño de buckets
        buckets *= 2;
        // Reinserta los valores en la nueva tabla
        for (int i = 0; i < aux_bucket; i++) insert(aux_lists[i]);

    }

    /**
     * Calcula la key asociada al tipo de dato entregado. Implementa función hash dato % buckets
     * @param x: Dato al cual calcularle la función hash. Por ahora solo acepta objetos  tipo User
     * @return: Key como entero
     */
    int hashFunction(dataType x){
        // Si se quiere usar username como key, stringKey es true
        if (stringKey){
            // Obtiene el username del objeto
            string user = x.getUsername();
            int sum = 0;
            // Comienza a sumar cada una de las letras llevadas a entero
            for (char i : user){
                sum = sum + int(i);
            }
            return sum % buckets;
        }
        else{
            // Retorna directamente la función módulo. Se usa fmod porque el dato es de tipo double
            return fmod(stod(x.getUserId()), buckets);
        }
    }

    /**
     * Implementa método insert de una tabla hash convencional
     * @param data: Dato a ser insertado. Solo acepta objetos user por ahora
     */
    void insert(dataType data){
        // Revisa si ya se ha excedido la capacidad de la lista
        if (current_size == buckets) expand_table();
        // Calcula el key de los datos
        int address = hashFunction(data);
        while(true){
            // Si el objeto tiene username inicializado por constructor a vacío, significa que no hay elemento insertado
            if (lists[address].getUsername().empty()){
                // Como hay espacio disponible, sale
                break;
            }
            // Linear probing
            else address = (address + 1) % buckets;
        }
        // Inserta el elemento con la dirección calculada
        lists[address] = data;
        // Aumenta el tamaño
        current_size++;
    }
    /**
     * Implementa método search de tablas hash
     * @param data: Dato a ser buscado. Solo acepta objeto user
     * @return: Retorna dato encontrado. Null si no lo encuentra
     */
    dataType search(dataType data){
        // Calcula la dirección del dato a buscar
        int address = hashFunction(data);
        // Dirección inicial para saber si se volvió al principio de la lista con linear probing
        int initial_add = address;
        // Hace la búsqueda dependiendo del key usado
        if (stringKey){
            while(true){
                // Si coinciden los username, retorna
                if (lists[address].getUsername() == data.getUsername()) return lists[address];
                // No coincidieron, usa linear probing
                else address = (address + 1) % buckets;
                // Si se dio vuelta en la tabla (wrap), rompe: dato no encontrado
                if (address == initial_add) break;
            }
        }
        else{
            // Repite lo anterior con key = userID
           while(true){
               if (lists[address].getUserId() == data.getUserId()) return lists[address];
               else address = (address + 1) % buckets;
               if (address == initial_add) break;
           }
        }
    }
};



#endif //TAREA3FEDA_HASHTABLEOPENADDRESSING_HPP
