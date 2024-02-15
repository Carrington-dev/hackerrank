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


LinkedList* mergeTwoSortedLinkedList(LinkedList* LinkedListOne, LinkedList* LinkedListTwo){
    LinkedList* newLinkedList = new LinkedList();

    Node* linkedListOneHead = LinkedListOne->root;
    Node* linkedListTwoHead = LinkedListTwo->root;

    while( linkedListOneHead  && linkedListTwoHead){
        if( linkedListOneHead->data < linkedListTwoHead->data) {
            newLinkedList->insert(linkedListOneHead->data);
            linkedListOneHead = linkedListOneHead->next;
        }else if(linkedListOneHead->data > linkedListTwoHead->data){
            newLinkedList->insert(linkedListTwoHead->data);
            linkedListTwoHead = linkedListTwoHead->next;
        }else{
            newLinkedList->insert(linkedListTwoHead->data);
            newLinkedList->insert(linkedListOneHead->data);
            linkedListTwoHead = linkedListTwoHead->next;
            linkedListOneHead = linkedListOneHead->next;
        }
        // cout << "here on and" << endl;
    }

    while ( linkedListOneHead ){
        newLinkedList->insert(linkedListOneHead->data);
        linkedListOneHead = linkedListOneHead->next;
        // cout << "here on list 1 only" << endl;
    }

    while ( linkedListTwoHead ){
        newLinkedList->insert(linkedListTwoHead->data);
        linkedListTwoHead = linkedListTwoHead->next;
        // cout << "here on list 2 only" << endl;
    }

    return newLinkedList;
}


int main(){
    
    LinkedList* myFistLinkedList = new LinkedList();
    for(int i = 0; i < 25; i++){
        if( i % 2 == 0)
            myFistLinkedList->insert(i);
    }

    LinkedList* mySecondLinkedList = new LinkedList();
    for(int i = 0; i < 25; i++){
        if( i % 2 == 1)
            mySecondLinkedList->insert(i);
    }

    myFistLinkedList->print();
    myFistLinkedList->new_print();
    cout << endl;
    mySecondLinkedList->print();
    mySecondLinkedList->new_print();
    cout << endl;

    LinkedList* mergedLinkedList = mergeTwoSortedLinkedList(myFistLinkedList, mySecondLinkedList);
    mergedLinkedList->print();

    cout << endl;
    LinkedList* newMergedLinkedList = mergeTwoSortedLinkedList(mergedLinkedList, myFistLinkedList);
    newMergedLinkedList->print();
    return 0;
}