#include <iostream>
#include <cstdlib>
#include "bst.cpp"
using namespace std;
//Conditional (or Ternary)
int main()
{
    int treeKeys[16] = {68, 83, 14, 12, 87, 55, 97, 31, 90, 3, 12, 51, 73, 58, 66, 45};
    int len = *(&treeKeys + 1) - treeKeys;
    BST myTree;

    cout << "Printing the Tree in Order, before adding numbers\n";
    myTree.PrintInOrder();

    for (auto i = 0; i < len; i++)
    {
        myTree.AddLeaf(treeKeys[i]);
    }

    cout << "Printing the Tree in Order, After adding numbers\n";
    myTree.PrintInOrder();
    cout << "\n";
    // myTree.PrintChildren(myTree.ReturnRootKey());
    // for (auto i = 0; i < len; i++){myTree.PrintChildren(treeKeys[i]); cout << endl;}
    cout << "Smallest value in true " << myTree.FindSmallest() << endl;

    return 0;
} //end main

/*

In-Order Traversal
1) Go left 
2) Process Current Node
3) Go right

boolean ?
true :
false
*/