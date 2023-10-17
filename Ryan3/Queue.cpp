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
Queue::Queue(const short size) : QUEUE_SIZE(size), head(-1), tail(-1) {

    queueArray = new (std::nothrow) Element[QUEUE_SIZE];

    if(queueArray == nullptr) {
        cout << "Memory allocation error" << endl;
        return;
    }
}

// copy constructor
Queue::Queue(Queue &old): QUEUE_SIZE(old.QUEUE_SIZE), head(-1), tail(-1) {

    Queue tempArray(old.QUEUE_SIZE);
    queueArray = new (std::nothrow) Element[QUEUE_SIZE];

    if(queueArray == nullptr) {
        cout << "Memory allocation error" << endl;
        return;
    }

    Element tempElement;

    while(!old.isEmpty()) {
        old.dequeue(tempElement);
        tempArray.enqueue(tempElement);
    }

    while(!tempArray.isEmpty()) {
        tempArray.dequeue(tempElement);
        enqueue(tempElement);
        old.enqueue(tempElement);
    }

}

Queue::~Queue() {

    Element dequeuedElement;

    while(!isEmpty()) {
        dequeue(dequeuedElement);
    }

    delete[] queueArray;

}

void Queue::enqueue(const Element item) {

    if(isFull()) {
        cout << "Queue is full. Cannot enqueue." << endl;
        return;
    }

    if(isEmpty()) {
        queueArray[++tail] = item;
        head++;
    } else {
        queueArray[++tail] = item;
    }

}

void Queue::dequeue(Element &removedElement) {
    
    if(isEmpty()) {
        cout << "Queue is empty, no element to remove!" << endl;
        return;
    }

    if(head == tail) {
        removedElement = queueArray[head];
        head = tail = -1;
    } else {
        removedElement = queueArray[head];
        head = (head + 1) % QUEUE_SIZE;
    }

}

void Queue::view() {

    if(isEmpty()) {
        cout << "HEAD -> TAIL" << endl;
        return;
    }

    Queue tempQueue(QUEUE_SIZE);
    Element tempElement;

    cout << "HEAD -> ";

    while(!isEmpty()) {
        dequeue(tempElement);
        cout << tempElement << " -> ";
        tempQueue.enqueue(tempElement);
    }

    cout << "TAIL" << endl;

    while(!tempQueue.isEmpty()) {
        tempQueue.dequeue(tempElement);
        enqueue(tempElement);
    }

}

bool Queue::isEmpty() const {
    return (head == -1);
}

bool Queue::isFull() const {
    return ((tail + 1) % QUEUE_SIZE) == head;
}
