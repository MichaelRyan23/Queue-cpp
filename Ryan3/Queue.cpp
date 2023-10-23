/********************************************************************
*** NAME        : Michael Ryan
*** CLASS       : CSc 300
*** ASSIGNMENT  : 3
*** DUE DATE    : 10 - 18 - 2023
*** INSTRUCTOR  : GAMRADT 
*********************************************************************
*** DESCRIPTION : The implemented "Queue" ADT is a collection of elements
*** with the first in first out idea. Queue uses an array of integers to
*** manage items, as well as implements the circular array idea. To manipulate
*** data, enqueue and dequeue are used to change the locations of head and tail
*** making sure not to touch the data.
********************************************************************/

#include <iostream>
#include "Queue.h"
using namespace std;

/********************************************************************
*** FUNCTION constructor
*********************************************************************
*** DESCRIPTION : Default and parameterized constructor. It initializes
*** an array of elements of the given size (default size 3) and sets top
*** and head values to -1, indicating an empty queue.
*** INPUT ARGS : size
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
Queue::Queue(const short size) : QUEUE_SIZE(size), head(-1), tail(-1) {

    queueArray = new (std::nothrow) Element[QUEUE_SIZE];

    if(queueArray == nullptr) {
        cout << "Memory allocation error" << endl;
        return;
    }
}

/********************************************************************
*** FUNCTION copy constructor
*********************************************************************
*** DESCRIPTION : Copy constructor creates a new queue ADT from an
*** existing one. Using enqueue and dequeue, the new queue will have
*** the same order of elements in it as the old queue being copied from.
*** INPUT ARGS : old
*** OUTPUT ARGS : 
*** IN/OUT ARGS : old
*** RETURN : 
********************************************************************/
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

/********************************************************************
*** FUNCTION destructor
*********************************************************************
*** DESCRIPTION : Destructor first dequeues all the elements from the
*** queue object, then it deletes the queueArray (element pointer)
*** from memory.
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
Queue::~Queue() {

    Element dequeuedElement;

    while(!isEmpty()) {
        dequeue(dequeuedElement);
    }

    delete[] queueArray;

}

/********************************************************************
*** FUNCTION enqueue
*********************************************************************
*** DESCRIPTION : Enqueue's function is to insert a value at the tail
*** of the queue. Checks if it's full, if not check if it's empty, if it
*** is head and tail are incremented and item goes into the tail spot. 
*** INPUT ARGS : item
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : void
********************************************************************/
void Queue::enqueue(const Element item) {

    if(isFull()) {
        cout << "Queue is full. Cannot enqueue." << endl;
        return;
    }

    if(isEmpty()) {
        queueArray[++tail] = item;
        head++;
    } else {
        tail = (tail + 1) % QUEUE_SIZE;
        queueArray[tail] = item;
    }

}

/********************************************************************
*** FUNCTION dequeue
*********************************************************************
*** DESCRIPTION : Dequeue removes an item from the front of the queue.
*** Checks to see if queue is empty, if not, provides item at head loc to the
*** output parameter and updates head. If dequeued element was last in
*** queue, it resets the queue to empty state.
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : removedElement
*** RETURN : void
********************************************************************/
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

/********************************************************************
*** FUNCTION view
*********************************************************************
*** DESCRIPTION : Displays the contents of the queue by dequeuing elements
*** from the original queue and enqueuing them into a temporary one while
*** displaying. After they're all displayed, it goes back in reverse to 
*** to the original queue, preserving the order.
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : void
********************************************************************/
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
    return (head == -1) && (tail == -1);
}

bool Queue::isFull() const {
    return ((tail + 1) % QUEUE_SIZE) == head;
}
