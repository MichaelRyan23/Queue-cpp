/********************************************************************
*** NAME        : Michael Ryan
*** CLASS       : CSc 300
*** ASSIGNMENT  : 3
*** DUE DATE    : 10 - 18 - 2023
*** INSTRUCTOR  : GAMRADT 
*********************************************************************
*** DESCRIPTION : <detailed english description of the abstract data type> ***
*** <including supporting operations> ***
********************************************************************/

#include <iostream>
#include "Queue.h"
using namespace std;

// constructor
Queue::Queue(const int size) : QUEUE_SIZE(size), head(-1), tail(-1) {

    queueArray = new (std::nothrow) Element[QUEUE_SIZE];

    if(queueArray = nullptr) {
        cout << "Memory allocation error" << endl;
        return;
    }
}

// copy constructor
Queue::Queue(Queue &old): QUEUE_SIZE(old.QUEUE_SIZE), head(old.head), tail(old.tail) {

    Queue tempArray(QUEUE_SIZE);
    queueArray = new (std::nothrow) Element[QUEUE_SIZE];

    if(queueArray == nullptr) {
        cout << "Memory allocation error" << endl;
        return;
    }

    Element tempElement;


}

Queue::~Queue() {

    Element dequeuedElement;

    while(!isEmpty()) {
        dequeue(dequeuedElement);
    }

    if(queueArray != nullptr) {
        delete[] queueArray;
        queueArray = nullptr;
    }

    head = 0;
    tail = 0;
}

void Queue::enqueue(const Element item) {

    if(isFull()) {
        cout << "Queue is full. Cannot enqueue." << endl;
        return;
    }

    if(isEmpty()) {
        head = tail = 0;
        queueArray[tail] = item;
    } else {
        tail = (tail + 1) % QUEUE_SIZE;
        queueArray[tail] = item;
    }

}

void Queue::dequeue(Element &removedElement) {
    
    if(isEmpty()) {
        cout << "Queue is empty, no element to remove!" << endl;
        return;
    }

    if(head == tail) {
        head = tail = -1;
    } else {
        head = (head + 1) % QUEUE_SIZE;
    }

}

void Queue::view() {

    if(isEmpty()) {
        cout << "HEAD -> TAIL" << endl;
        return;
    }

    cout << "HEAD ->";

}

bool Queue::isEmpty() const {
    return (head == -1) && (tail == -1);
}

bool Queue::isFull() const {
    return ((tail + 1) % QUEUE_SIZE) == head;
}