#include <iostream>
#include "doublylinkedlist.h"

using namespace std;

DoublyLinkedList* reverseDoublyLinkedList(DoublyLinkedList* doublyLinkedList){
    Node* current = doublyLinkedList->root;
    Node* previous = nullptr;

    while( current ){
        Node* next = current->next;
        current->next = previous;
        previous =current;
        current = next;
    }

    doublyLinkedList->root = previous;
    return doublyLinkedList;
}

int main(){


    DoublyLinkedList* myFistLinkedList = new DoublyLinkedList();
    for(int i = 0; i < 25; i++){
        if( i % 2 == 0)
            myFistLinkedList->insert(i);
    }

   

    myFistLinkedList->print();
    cout << endl;
    myFistLinkedList->printPrev();
    cout << endl;
    myFistLinkedList->reverse();
    myFistLinkedList->print();
    cout << endl;
    DoublyLinkedList* reversedDoubledLinkedList = reverseDoublyLinkedList(myFistLinkedList);
    cout << endl;
    reversedDoubledLinkedList->print();
    cout << endl;
    myFistLinkedList->print();
    cout << endl;
    
    myFistLinkedList->print();
    cout << endl;
    return 0;
}