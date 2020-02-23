// listQ.cpp - implements queue as linked list
// Richard 2/22/20
#include <cstddef>
#include "listQ.h"

Queue::Queue() {
    size = 0;
}

Queue::~Queue() {
    while(front != NULL){
        node* temp = front;
	front = front->next;
	delete temp;
    }
}

void Queue::enqueue(int n) {
    node* temp = new node(n);
    if(rear== NULL){
        front = temp;
        rear = temp;
        return;	
    }
    rear->next = temp;
    rear = temp;
    size= size+1;
}

int Queue::dequeue() {
    if (isEmpty())
        throw EmptyQueue();
    node* temp = front;
    front = front->next;
    if(front == NULL){
    	rear = NULL;
    }
    int val = temp->data;
    delete temp;
    size = size -1;
    return val;
}

void Queue::clear() {
    while(front != NULL){
        node* temp = front;
        front = front->next;
        delete temp;
    }
    rear = NULL;
    size = 0;
}

bool Queue::isEmpty() const {
    return (size == 0);
}

int Queue::getSize() const {
    return size;
}
