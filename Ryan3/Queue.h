/********************************************************************
*** NAME        : Michael Ryan
*** CLASS       : CSc 300
*** ASSIGNMENT  : 3
*** DUE DATE    : 10 - 18 - 2023
*** INSTRUCTOR  : GAMRADT 
*********************************************************************
*** DESCRIPTION : Queue is implemented as a dynamic circular array-based
*** queue, first in first out idea. Elements are added to one end of the queue,
*** and come out the other.
********************************************************************/

#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>
using namespace std;

typedef int Element;
typedef Element * ElementPtr;

class Queue {
    public:

/********************************************************************
*** FUNCTION constructor
*********************************************************************
*** DESCRIPTION : Initializes a new queue with a given or default size
*** INPUT ARGS : size
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
        explicit Queue(short size = 3);

/********************************************************************
*** FUNCTION copy constructor
*********************************************************************
*** DESCRIPTION : Creates a copy of an existing queue
*** INPUT ARGS : old
*** OUTPUT ARGS : 
*** IN/OUT ARGS : old
*** RETURN : 
********************************************************************/
        Queue(Queue &old);

/********************************************************************
*** FUNCTION destructor
*********************************************************************
*** DESCRIPTION : dequeues each element from a queue, then proceeds to
*** cleanup memory by deleting.
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
        ~Queue();

/********************************************************************
*** FUNCTION enqueue
*********************************************************************
*** DESCRIPTION : Adds a new item to the back of the queue
*** INPUT ARGS : item
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : void
********************************************************************/
        void enqueue(const Element item);

/********************************************************************
*** FUNCTION dequeue
*********************************************************************
*** DESCRIPTION : removes an item from the front of the queue.
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : removedElement
*** RETURN : void
********************************************************************/
        void dequeue(Element &removedElement);

/********************************************************************
*** FUNCTION view
*********************************************************************
*** DESCRIPTION : Prints all elements in the queue from head to tail.
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : void
********************************************************************/
        void view();

    private:
        const short QUEUE_SIZE;
        ElementPtr queueArray;
        short head, tail;
        bool isEmpty() const;
        bool isFull() const;

};

#endif