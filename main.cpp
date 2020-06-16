#include <iostream>
#include "BinaryTree.hpp"


int main() {
    BinaryTree<int> bt;
    bt.insert(3);
    bt.insert(5);
    bt.insert(1);
    bt.insert(15);
    bt.insert(9);
    node<int> *nodo = bt.search(5);
    cout << nodo->data << endl;
    return 0;
}
