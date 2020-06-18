//
// Created by krampus on 6/17/20.
//

#ifndef TAREA3FEDA_HASHTABLEOPEN_HPP
#define TAREA3FEDA_HASHTABLEOPEN_HPP
template <typename dataType>
struct node{
    dataType data;
    node *right;
    node *left;
};
template <typename dataType>
class HashTableOpen {
public:
    HashTableOpen();
    void insert(dataType data);
    void search(dataType data);

};


#endif //TAREA3FEDA_HASHTABLEOPEN_HPP
