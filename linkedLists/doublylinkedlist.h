#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next, *prev;
        Node(int number): data(number){ 
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList{
    public:
        Node* root;
        Node* tail;

        DoublyLinkedList(){ root = nullptr; tail = nullptr; }
        
        Node* insertSingle(int number, Node* head) {
            if( root == nullptr){
                root =  new Node(number);
                
                return root;
            } else{
                head->next = insertSingle(number, head->next);
            }
            return root;
        }


        Node* insert(int number){
            if( root == nullptr){
                root = new Node(number);
                root->prev = nullptr;
                tail = root;
                return root;
            }else{
                Node* current = root;
                while( current->next ){
                    current = current->next;
                }
                current->next = new Node(number);
                current->next->prev = current;
                tail = current->next;
                return root;
            }
            return root;
        }


        void print(Node* head){
            if( head == nullptr) return;
            cout << head->data << " ";
            print(head->next);
        }

        void print(){
            print(root);
        }

         void printPrev(Node* head){
            if( head == nullptr) return;
            if( head->prev)
                cout << head->prev->data << " ";
            else
                cout << "N ";
            printPrev(head->next);
        }

        void printPrev(){
            printPrev(root);
        }


        void reverseWithTail(){
            Node* temp = root;
            root = tail;
            tail = temp;
            return;
        }


        void reverse(){
            Node* current = root;
            Node* previous;

            while( current ){
                Node* next = current->next;
                previous = current;
                current->next  = current->prev;
                current = next;
            }
            root = previous;
            return;
        } 
};