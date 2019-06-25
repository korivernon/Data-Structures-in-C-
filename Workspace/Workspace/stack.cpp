//
//  stack.cpp
//  Workspace
//
//  Created by Kori Vernon on 6/20/19.
#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 10

//Class for stacl

class Stack {
    int *iarr;
    int top;
    int capacity;
public:
    Stack(int size = SIZE);
    
    void push(int);
    int pop();
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

//this initializes the stack
Stack::Stack(int size) {
    iarr = new int[size];
    capacity = size;
    top = -1;
}
//push to the stack
void Stack::push(int x) {
    if (isFull()) {
        cout << "Overflow, Program Terminated" << endl;
        exit(EXIT_FAILURE);
    }
    cout << " inserting... " << x << endl;
    iarr[++top] = x;
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "The Stack Is Empty! " << endl;
    }
    cout << " removing... " << peek() <<endl;
    return iarr[top--];
}

int Stack::peek() {
    if (!isEmpty()) return iarr[top];
    else exit(EXIT_FAILURE);
}

int Stack::size() {
    return top + 1;
}

bool Stack::isEmpty() {
    if (size() == 0) {
        return true;
    } else {
        return false;
    }
}

bool Stack::isFull() {
    if (size() == 10) {
        return true;
    } else {
        return false;
    }
}
