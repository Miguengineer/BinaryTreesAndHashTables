//
// Created by krampus on 6/16/20.
//

#ifndef TAREA3FEDA_USER_HPP
#define TAREA3FEDA_USER_HPP


#include <bits/stdc++.h>

using namespace std;

/**
 * Clase "User" para almacenar dataset de usuarios de Twitter. Contiene todos los campos del dataset asociado.
 * university: Universidad a la que sigue el usuario en la red social.
 * userId: Número identificador del usuario en Twitter.
 * username: Nombre de usuario en Twitter.
 * createdAt: Fecha en la que el usuario creó su cuenta en la red social.
 * tweetNumber: Número de tweets publicados por el usuario.
 * friendCount: Número de cuentas que el usuario sigue en la red social.
 * followerCount: Número de seguidores que tiene el usuario en la red social.
 */
class User {
private:
    string university;
    string userId;
    string username;
    string createdAt;
    int tweetNumber;
    int friendCount;
    int followerCount;
public:
    User(string univ, string id, string user, string created, int tweet, int friends, int followers){
        this->university = move(univ);
        this->userId = move(id);
        this->username = move(user);
        this->createdAt = move(created);
        this->tweetNumber = tweet;
        this->friendCount = friends;
        this->followerCount = followers;
    }
    string getUniversity(){return this->university;}
    string getUserId(){return this->userId;}
    string getUsername(){return this->username;}
    string getCreatedAt(){return this->createdAt;}
    int getTweetNumber() const{return this->tweetNumber;}
    int getFriendCount() const{return this->friendCount;}
    int getFollowerCount() const{return this->followerCount;};

};


#endif //TAREA3FEDA_USER_HPP