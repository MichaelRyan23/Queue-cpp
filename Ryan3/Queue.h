/********************************************************************
*** NAME        : Michael Ryan
*** CLASS       : CSc 300
*** ASSIGNMENT  : 3
*** DUE DATE    : 10 - 18 - 2023
*** INSTRUCTOR  : GAMRADT 
*********************************************************************
*** DESCRIPTION : <general english description of the abstract data type> ***
*** <including supporting operations> ***
********************************************************************/

#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>
using namespace std;

typedef int Element;
typedef Element * ElementPtr;

class Queue {
    public:
        explicit Queue(int size = 3);
        Queue(Queue &old);
        ~Queue();

        void enqueue(const Element item);
        void dequeue(Element &);
        void view();

    private:
        const short QUEUE_SIZE;
        ElementPtr queueArray;
        short head, tail;
        bool isEmpty() const;
        bool isFull() const;

};

#endif