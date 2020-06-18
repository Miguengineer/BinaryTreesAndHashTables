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


/**
 * Realiza una serie de tests sobre la estructura de datos de BinaryTree, realiza medición de tiempo y reporta
 */

void test_cases(){
    // Lee de memoria los datos
    vector<User> users = readFile();
    map<int, double> test_times;
    // Crea el árbol sobre el que testear
    BinaryTree<User> bt1;
    // Inserta 1000 usuarios y mide tiempo
    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < 1000; i++){
        bt1.insert(users[i]);
    }
    auto end = std::chrono::system_clock::now();
    double time = chrono::duration<double>(end - start).count();
    // Inserta el tiempo en el map
    test_times.insert(make_pair(1000, time));

    start = std::chrono::system_clock::now();
    node<User> *aux = bt1.search("879120276054835666");
    end = std::chrono::system_clock::now();
    time = chrono::duration<double>(end - start).count();
    cout.precision(10);
    cout << fixed <<  time << endl;


    // Crea nuevo árbol
    BinaryTree<User> bt4;
    // Inserta 5000 usuarios y mide tiempo
    start = std::chrono::system_clock::now();
    for (int i = 0; i < 5000; i++){
        bt4.insert(users[i]);
    }
    end = std::chrono::system_clock::now();
    time = chrono::duration<double>(end - start).count();
    // Inserta el tiempo en el map
    test_times.insert(make_pair(5000, time));

    start = std::chrono::system_clock::now();
    aux = bt4.search("2342343243223");
    end = std::chrono::system_clock::now();
    time = chrono::duration<double>(end - start).count();
    cout.precision(10);
    cout << fixed <<  time << endl;


    // Crea nuevo árbol
    BinaryTree<User> bt2;
    // Inserta 10000 usuarios y mide tiempo
    start = std::chrono::system_clock::now();
    for (int i = 0; i < 10000; i++){
        bt2.insert(users[i]);
    }
    end = std::chrono::system_clock::now();
    time = chrono::duration<double>(end - start).count();
    // Inserta el tiempo en el map
    test_times.insert(make_pair(10000, time));


    start = std::chrono::system_clock::now();
    aux = bt2.search("2342343243223");
    end = std::chrono::system_clock::now();
    time = chrono::duration<double>(end - start).count();
    cout.precision(10);
    cout << fixed <<  time << endl;

    // Crea nuevo árbol
    BinaryTree<User> bt3;
    // Inserta 15000 usuarios y mide tiempo
    start = std::chrono::system_clock::now();
    for (int i = 0; i < 15000; i++){
        bt3.insert(users[i]);
    }
    end = std::chrono::system_clock::now();
    time = chrono::duration<double>(end - start).count();
    // Inserta el tiempo en el map
    test_times.insert(make_pair(15000, time));

    start = std::chrono::system_clock::now();
    aux = bt3.search("2342343243223");
    end = std::chrono::system_clock::now();
    time = chrono::duration<double>(end - start).count();
    cout.precision(10);
    cout << fixed <<  time << endl;





    // Crea nuevo árbol
    BinaryTree<User> bt5;
    // Inserta 20000 usuarios y mide tiempo
    start = std::chrono::system_clock::now();
    for (int i = 0; i < 20000; i++){
        bt5.insert(users[i]);
    }
    end = std::chrono::system_clock::now();
    time = chrono::duration<double>(end - start).count();
    // Inserta el tiempo en el map
    test_times.insert(make_pair(20000, time));


    start = std::chrono::system_clock::now();
    aux = bt5.search("2342343243223");
    end = std::chrono::system_clock::now();
    time = chrono::duration<double>(end - start).count();
    cout.precision(10);
    cout << fixed <<  time << endl;

    cout << "INSERTION TIMES: " << endl;

    cout << test_times[1000] << endl;
    cout << test_times[5000] << endl;
    cout << test_times[10000] << endl;
    cout << test_times[15000] << endl;
    cout << test_times[20000] << endl;


}


int main() {




    // test_cases();




    return 0;
}
