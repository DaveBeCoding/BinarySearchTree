
#include <iostream>
#include <cstdlib>
#include "bst.h"
using namespace std;

BST::BST(){
    root = nullptr;
}

//node* is not known by cpp file, and outside definition, must explicitly tell it.
BST::node* BST::CreateLeaf(int key){
    node* n = new node;
    n->key = key;
    n->left = nullptr;
    n->right = nullptr;
    return n;}