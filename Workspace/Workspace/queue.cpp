//
//  queue.cpp
//  Workspace
//
//  Created by Kori Vernon on 6/20/19.
//  Copyright © 2019 Kori Vernon. All rights reserved.
//

/*
#include <iostream>
#include <cstdlib>
using namespace std;
#define SIZE 10

class Queue {
    int *iarr;
    int top;
    int capacity;
    int first_elem;
    
public:
    Queue(int size = SIZE);
    void enqueue(int);
    void dequeue();
    int first();
    bool isEmpty();
    int size();
    bool isFull();
    int front();
};

Queue::Queue(int size){
    iarr = new int[size];
    capacity = size;
    top = -1;
}
void Queue::enqueue(int x) {
    if (isFull()) {
        cout << "Overflow Error \n";
        exit(EXIT_FAILURE);
    }
    cout << "enqueueing... " << x << endl;
    iarr[++top] = x;
    capacity++;
}

int Queue::front() {
    return (capacity+1)%top;
}
int Queue::first() {
    if (!isEmpty()) {
        return iarr[front()];
    }
    else {
        exit(EXIT_FAILURE);
    }
}

void Queue::dequeue() {
    cout << iarr[front()] << endl;
    iarr[front()] = NULL;
    capacity--;
    top--;
}
*/
