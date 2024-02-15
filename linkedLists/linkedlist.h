#include <iostream>

using namespace std;


class Node{
    public:
        int data;
        Node* next;
        Node(int number): data(number){ next = nullptr; } 
};

class LinkedList{
    public:
        Node* root;
        LinkedList(){ root = nullptr; }

        Node* insert(int number){
            if( root == nullptr ){
                root = new Node(number);
                return root;
            }

            Node* current = root;
            while ( current->next ){
                current = current->next;
            }

            current->next =  new Node(number);
            return root;
        }

        void print(Node* head){
            if( head == nullptr ){
                return;
            }

            cout << head->data << " ";
            print( head -> next);
        }

        void print(){
            print(root);
        }

        void new_print(Node* head){
            cout << endl;
            Node* current  = head;
            while( current != nullptr){
                cout << current -> data << " ";
                current = current->next;
            }
        }

        void new_print(){
            new_print(root);
        }
};