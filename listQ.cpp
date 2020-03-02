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

void reverse(int k, Queue& queue){
    if(queue.isEmpty()){
    	return;
    }
    if(k> queue.getSize())
	k = queue.getSize();

    stack<Node> s;
    for(int i = 0 i < k; i++){
    	s.push(queue.dequeue);
    }
    while(!s.empty()){
    	queue.enqueue(s.top());
	s.pop();
    }
    for(int i = 0; i < queue.getSize()-k; i++){
    	queue.enqueue(queue.dequeue);
    }
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
