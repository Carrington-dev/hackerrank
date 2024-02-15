#include <iostream>
#include "linkedlist.h"

using namespace std;



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
    cout << endl;
    mySecondLinkedList->print();
    cout << endl;
    return 0;
}