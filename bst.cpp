
#include <iostream>
#include <cstdlib>
#include "bst.h"
using namespace std;

BST::BST(){root = nullptr;}

//node* is not known by cpp file, and outside definition, must explicitly tell it.
BST::node* BST::CreateLeaf(int key){
    node* n = new node;
    n->key = key;
    n->left = nullptr;
    n->right = nullptr;
    return n;}//end of CreateLeaf

void BST::AddLeaf(int key){AddLeafPrivate(key, root);}//end AddLeaf

void BST::AddLeafPrivate(int key, BST::node* ptr){
    if(root == nullptr){
        root = CreateLeaf(key);
    }else if(key < ptr->key){if(ptr->left != nullptr){AddLeafPrivate(key, ptr->left);}// recursively checking left
        else{ptr->left = CreateLeaf(key);}
    }//end elif L
    else if(key > ptr->key){
        if(ptr->right != nullptr){AddLeafPrivate(key, ptr->right);}// recursively checking right
        else{ptr->right = CreateLeaf(key);}}//end elif R
    else{cout << "The Key " << key << " Has already been added to the tree\n";}
}//end AddLeafPrivate

void BST::PrintInOrder(){PrintInOrderPrivate(root);}
void BST::PrintInOrderPrivate(BST::node* ptr){
    if(root != nullptr){
        if(ptr->left != nullptr){PrintInOrderPrivate(ptr->left);} //step 1) of In-order
        cout << ptr->key << " "; //step 2) of In-order
        if(ptr->right != nullptr){ PrintInOrderPrivate(ptr->right);} //step 3) of In-order
    }else{cout << "The tree is empty\n";}}//end PRintInOrderPrivate

BST::node* BST::ReturnNode(int key){ return ReturnNodePrivate(key, root);}
BST::node* BST::ReturnNodePrivate(int key, BST::node* ptr){
    if(ptr != nullptr){
        if(ptr->key == key){return ptr;}
        else{if(key < ptr->key){return ReturnNodePrivate(key, ptr->left);}
            else{return ReturnNodePrivate(key, ptr->right);}}
    }else{return nullptr;}}//end ReturnNodePrivate

int BST::ReturnRootKey(){
    if(root != nullptr){return root->key;}
    else{return -1000;}
}//end ReturnRootKey

void BST::PrintChildren(int key){
    node* ptr = ReturnNode(key);

    if(ptr != nullptr){cout<<"Parent Node = "<< ptr->key << endl;
    ptr->left == nullptr ? 
    cout << "Left Child = Null\n" : 
    cout<<"Left Child = "<< ptr->left->key << endl;

    ptr->right == nullptr ? 
    cout << "Right Child = Null\n" : 
    cout<<"Right Child = "<< ptr->right->key << endl;
    }
    else{cout << "Key " << key <<" is not in the tree\n";}    
}