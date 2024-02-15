#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* left, *right;
        Node(int y):data(y){ left = nullptr; right = nullptr; }
};

class BST{
    public:
        Node* root = nullptr;
        BST(){ root = nullptr }

        Node* insert(int x, Node* current){
            if( root == nullptr ){
                root = new Node(x);
                return root;
            }

            if ( current->){
                
            }

            if( x < root->){
                
            }
        }

        Node* insert(int x){
            insert(x, root)
        }
};

int main(){

    return 0;
}