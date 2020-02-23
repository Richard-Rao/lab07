// arrayQ.cpp - implements queue as array
// NAME(S), DATE

#include "arrayQ.h"

Queue::Queue() {
    size = 0;
    front = 0;
    rear = CAPACITY - 1;    
}  // IMPLEMENT CONSTRUCTOR

void Queue::enqueue(int n) {
    if (isFull())
        throw FullQueue();
    rear = (rear+1) % CAPACITY;
    data[rear] = n;
    size = size + 1;
       
    // COMPLETE THIS IMPLEMENTATION
}

int Queue::dequeue() {
    if (isEmpty())
        throw EmptyQueue();
    int val = data[front];
    front = (front+1)%CAPACITY;
    size = size - 1;
    // COMPLETE THIS IMPLEMENTATION
    return val; // AND REPLACE THIS RETURN STATEMENT
}

void Queue::clear() {
    front = 0;
    size = 0;
    rear = CAPACITY-1;
}

bool Queue::isEmpty() const {
    return (size == 0); // AND REPLACE THIS RETURN STATEMENT
}

bool Queue::isFull() const {
    return (size == CAPACITY); // AND REPLACE THIS RETURN STATEMENT
}

int Queue::getSize() const {
    return size; // AND REPLACE THIS RETURN STATEMENT
}
