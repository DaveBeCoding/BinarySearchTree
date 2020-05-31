
#include <iostream>
#include <cstdlib>
#include "bst.h"
using namespace std;

BST::BST() { root = nullptr; }

//node* is not known by cpp file, and outside definition, must explicitly tell it.
BST::node *BST::CreateLeaf(int key)
{
    node *n = new node;
    n->key = key;
    n->left = nullptr;
    n->right = nullptr;
    return n;
} //end of CreateLeaf

void BST::AddLeaf(int key) { AddLeafPrivate(key, root); } //end AddLeaf

void BST::AddLeafPrivate(int key, BST::node *ptr)
{
    if (root == nullptr)
    {
        root = CreateLeaf(key);
    }
    else if (key < ptr->key)
    {
        if (ptr->left != nullptr)
        {
            AddLeafPrivate(key, ptr->left);
        } // recursively checking left
        else
        {
            ptr->left = CreateLeaf(key);
        }
    } //end elif L
    else if (key > ptr->key)
    {
        if (ptr->right != nullptr)
        {
            AddLeafPrivate(key, ptr->right);
        } // recursively checking right
        else
        {
            ptr->right = CreateLeaf(key);
        }
    } //end elif R
    else
    {
        cout << "The Key " << key << " Has already been added to the tree\n";
    }
} //end AddLeafPrivate

void BST::PrintInOrder() { PrintInOrderPrivate(root); }
void BST::PrintInOrderPrivate(BST::node *ptr)
{
    if (root != nullptr)
    {
        if (ptr->left != nullptr)
        {
            PrintInOrderPrivate(ptr->left);
        }                        //step 1) of In-order
        cout << ptr->key << " "; //step 2) of In-order
        if (ptr->right != nullptr)
        {
            PrintInOrderPrivate(ptr->right);
        } //step 3) of In-order
    }
    else
    {
        cout << "The tree is empty\n";
    }
} //end PRintInOrderPrivate

BST::node *BST::ReturnNode(int key) { return ReturnNodePrivate(key, root); }
BST::node *BST::ReturnNodePrivate(int key, BST::node *ptr)
{
    if (ptr != nullptr)
    {
        if (ptr->key == key)
        {
            return ptr;
        }
        else
        {
            if (key < ptr->key)
            {
                return ReturnNodePrivate(key, ptr->left);
            }
            else
            {
                return ReturnNodePrivate(key, ptr->right);
            }
        }
    }
    else
    {
        return nullptr;
    }
} //end ReturnNodePrivate

int BST::ReturnRootKey()
{
    if (root != nullptr)
    {
        return root->key;
    }
    else
    {
        return -1000;
    }
} //end ReturnRootKey

void BST::PrintChildren(int key)
{
    node *ptr = ReturnNode(key);

    if (ptr != nullptr)
    {
        cout << "Parent Node = " << ptr->key << endl;
        ptr->left == nullptr ? cout << "Left Child = Null\n" : cout << "Left Child = " << ptr->left->key << endl;

        ptr->right == nullptr ? cout << "Right Child = Null\n" : cout << "Right Child = " << ptr->right->key << endl;
    }
    else
    {
        cout << "Key " << key << " is not in the tree\n";
    }
}

int BST::FindSmallest() { return FindSmallestPrivate(root); }
int BST::FindSmallestPrivate(node *ptr)
{
    if (root == nullptr)
    {
        cout << "The tree is empty\n";
        return -1000;
    }
    else
    {
        if (ptr->left != nullptr)
        {
            return FindSmallestPrivate(ptr->left);
        }
        else
        {
            return ptr->key;
        }
    }
} //end of FindSmallestPrivate

void BST::RemoveNode(int key) { RemoveNodePrivate(key, root); } //end of RemoveNode
void BST::RemoveNodePrivate(int key, BST::node *parent)
{
    if (root != nullptr)
    {
        if (root->key == key)
        {
            RemoveRootMatch();
        }
        else
        {
            if (key < parent->key && parent->left != nullptr)
            {
                parent->left->key == key ? RemoveMatch(parent, parent->left, true) : RemoveNodePrivate(key, parent->left);
            }
            else if (key > parent->key && parent->right != nullptr)
            {
                parent->right->key == key ? RemoveMatch(parent, parent->right, false) : RemoveNodePrivate(key, parent->right);
            }
            else
            {
                cout << "The key " << key << " was not in tree\n";
            }
        }
    }
    else
    {
        cout << "The tree is empty\n";
    }
}

void BST::RemoveRootMatch()
{
    if (root != nullptr)
    {
        node *delPtr = root;
        int rootkey = root->key;
        int smallestInRightSubTree;

        //0 children
        if (root->left == nullptr && root->right == nullptr)
        {
            root = nullptr;
            delete delPtr;
        }
        // 1 child
        else if (root->left == nullptr && root->right != nullptr)
        {
            root = root->right;
            delPtr->right = nullptr;
            delete delPtr;
            cout << " the root node with key " << rootkey << " was deleted. "
                 << "The new root contains key " << root->key << endl;
        }
        // 1 child, opposite side
        else if (root->left != nullptr && root->right == nullptr)
        {
            root = root->right;
            delPtr->left = nullptr;
            delete delPtr;
            cout << " the root node with key " << rootkey << " was deleted. "
                 << "The new root contains key " << root->key << endl;
        }
        // 2 children
        else
        {
            smallestInRightSubTree = FindSmallestPrivate(root->right);
            RemoveNodePrivate(smallestInRightSubTree, root);
            root->key = smallestInRightSubTree;
            cout << " The root key containing " << rootkey << " was overwritten with key " << root->key << endl;
        }
    }
    else
    {
        "Root node is not removable, the tree is empty";
    }
} //end RemoveRootMatch

void BST::RemoveMatch(node *parent, node *match, bool left)
{
    if (root != nullptr)
    {
        node *delPtr;
        int matchKey = match->key;
        int smallestInRightSubTree;
    }
    else
    {
        cout << "Cannot remove match, the tree is empty\n";
    }
}

//13