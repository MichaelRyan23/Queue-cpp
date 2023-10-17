/********************************************************************
*** NAME        : Michael Ryan
*** CLASS       : CSc 300
*** ASSIGNMENT  : 3
*** DUE DATE    : 10 - 18 - 2023
*** INSTRUCTOR  : GAMRADT 
*********************************************************************
*** DESCRIPTION : This program implements an ADT called queue which
*** represents what a queue would do in a real-life scenario. Values are
*** Enqueued to the back of the queue, and get out from the head of the queue.
*** First in first out.
********************************************************************/

#include <iostream>
#include "Queue.h"
using namespace std;

int main() {

    // Test default constructor and enqueue
    Queue myQueue(5); // Queue of size 5
    cout << "Enqueuing elements..." << endl;
    for(int i = 1; i <= 5; ++i) {
        myQueue.enqueue(i); // Should be able to enqueue 5 elements
        myQueue.view();
    }

    // Test enqueue on full queue
    cout << "Attempting to enqueue on full queue..." << endl;
    myQueue.enqueue(6); // Should display an error message as the queue is full

    // Test dequeue
    cout << "Dequeuing elements..." << endl;
    int removedElement;
    for(int i = 1; i <= 5; ++i) {
        myQueue.dequeue(removedElement); // Should dequeue all elements
        cout << "Dequeued: " << removedElement << endl;
        myQueue.view();
    }

    // Test dequeue on empty queue
    cout << "Attempting to dequeue on empty queue..." << endl;
    myQueue.dequeue(removedElement); // Should display an error message as the queue is empty

    // Test copy constructor
    cout << "Enqueuing more elements for copy testing..." << endl;
    for(int i = 10; i <= 14; ++i) {
        myQueue.enqueue(i); // Enqueue 5 elements
        myQueue.view();
    }

    cout << "Creating a copy of the queue..." << endl;
    Queue copiedQueue = myQueue; // Using copy constructor
    cout << "Original queue:" << endl;
    myQueue.view();
    cout << "Copied queue:" << endl;
    copiedQueue.view();

    // Check if both queues are independent
    cout << "Modifying original queue..." << endl;
    myQueue.dequeue(removedElement);
    cout << "Dequeued from original: " << removedElement << endl;
    cout << "Original queue after modification:" << endl;
    myQueue.view();
    cout << "Copied queue should remain unchanged:" << endl;
    copiedQueue.view();

    return 0;
}