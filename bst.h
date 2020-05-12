

class BST{
    private:
        struct node{
            int key;
            node* left;
            node* right;
        };
        node* root;
        void AddLeafPrivate(int key, node* ptr);
        void PrintInOrderPrivate(node *ptr);
        node* ReturnNodePrivate(int key, node* ptr);
    public:
        BST();
        node* CreateLeaf(int key);
        void AddLeaf(int key);
        void PrintInOrder();
        node* ReturnNode(int key);
        int ReturnRootKey();
        void PrintChildren(int key);
};