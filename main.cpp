#include <iostream>
#include <bits/stdc++.h>
#include "BinaryTree.hpp"
#include "User.hpp"

using namespace std;

/**
 * Lee la base de datos provista de usuarios de twitter y la almacena en un vector usando la clase User
 * @return: Retorna un vector con todos los usuarios leídos
 */
vector<User> readFile(){
    // Puntero a archivo
    ifstream fin;
    // Abre el archivo con la base de datos
    fin.open("/home/krampus/CLionProjects/Tarea3FEDA/universities_followers.csv", ios::in);
    string line, word, temp;
    // Vector de strings para almacenar cada palabra
    vector<string> tempInfo;
    // Vector para almacenar todos los usuarios
    vector<User> users;
    // Lee la primera línea, que son los nombres de las columnas. No es relevante, hace nada.
    getline(fin, line);
    // Lee hasta EOF
    while (getline(fin, line)){
        // Borra la info anterior que pudiera haber en el vector
        tempInfo.clear();
        // Crea un stringstream para cada palabra individual
        stringstream s(line);
        // Ahora almacena cada palabra de forma independiente, separadas por la coma
        while(getline(s, word, ',')){
            tempInfo.push_back(word);
        }
        users.emplace_back(tempInfo[0], tempInfo[1], tempInfo[2], tempInfo[3], tempInfo[4], tempInfo[5], tempInfo[6]);
    }
    return users;
}


int main() {
    vector<User> users = readFile();
    BinaryTree<User> bt;
    bt.insert(users[0]);
    bt.insert(users[1]);
    bt.insert(users[2]);
    bt.insert(users[3]);
    node<User> *aux = bt.search("edu_hhs");
    cout << aux->data.getTweetNumber() << endl;
    //for (auto &it : users) cout << it.getUsername() << endl;


    return 0;
}
