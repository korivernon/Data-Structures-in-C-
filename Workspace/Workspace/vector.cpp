//
//  vector.cpp
//  Workspace
//
//  Created by Kori Vernon on 6/25/19.
//  Copyright © 2019 Kori Vernon. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

const int DEF_CAPACITY = 10;
const int CAPACITY_MULT = 2;

class MyVec {
public:
    class Iterator {
        /*
         * This class supports ranged for loops.
         * It includes:
         * Iterator(int*)
         * operator++
         * operator*
         * operator!=
         * */
        friend bool operator!=(Iterator& rhs, Iterator& lhs) {
            return rhs.iptr != lhs.iptr;
            //comparing the pointer at the left hand and right hand side
        }
    public:
        Iterator(int* ip) : iptr(ip) {}
        
        Iterator& operator++() {
            (iptr)++;
            //increment the iptr
            return *this;
        }
        int operator*() { return *iptr; }
        //you are returning the pointer of iptr in the vector. you are prefilling with the given value
        
    private:
        int* iptr;
    };
    
    MyVec();
    MyVec(int sz, int val=0);
    
    // copy control:
    MyVec(const MyVec& v2);
    ~MyVec();
    MyVec& operator=(const MyVec& v2);
    
    void push_back(int val);
    int size() const { return sz; }
    int operator[](int i) const;
    int& operator[](int i);
    Iterator begin() const;
    Iterator end() const;
    
private:
    void copy(const MyVec& v2);
    int* data;
    int sz;
    int capacity;
};


void print_vector(const MyVec& v);

bool operator==(MyVec& v1, MyVec& v2);

void print_vector(const MyVec& v) {
    for (int i : v) cout << i << " ";
    cout << endl;
}


MyVec::MyVec() : sz(0) {
    capacity = DEF_CAPACITY;
    data = new int[DEF_CAPACITY];
}


MyVec::MyVec(int sz, int val) : sz{sz} {
}


MyVec::MyVec(const MyVec& v2) {
    copy(v2);
}

MyVec::~MyVec() {
    delete [] data;
}

MyVec& MyVec::operator=(const MyVec& v2) {
    if (this != &v2) {
        delete [] data;
        copy(v2);
    }
    return *this;
}


MyVec::Iterator MyVec::begin() const {
    return MyVec::Iterator(nullptr);
}

MyVec::Iterator MyVec::end() const {
    return MyVec::Iterator(nullptr);
}


/*
 * == is true when every element of the vectors are the same in
 * the same order. (Thus they must be the same size.)
 * */
bool operator==(MyVec& v1, MyVec& v2) {
    //if you have to check if the vectors are equal then you have to loop through and check.
    if (v1.size() != v2.size()){
        return false;
    }
    else {
        for(int i = 0 ; i < v1.size() ; i++) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }
        return true;
    }
}

/*
 * Puts an element at the back of a vector.
 * */
void MyVec::push_back(int val) {
    if (sz > capacity) {
        capacity *= CAPACITY_MULT;
        int* new_data = new int[capacity];
        //you need to multiply the capacity by the capacity multiple of two to make space for the new data
        for (int i = 0; i < sz; i++){
            new_data[i] = data[i];
        }
        delete [] data;
        // multiplyting the capacity
        //deleting the old data by using the delete [] data operator
    }
    data[sz++] = val;
}

/*
 * this [] is for reading items from the MyVec:
 * It returns the i-th element.
 * */
int MyVec::operator[](int i) const {
    return data[i];
}

/*
 * this [] allows write access to items in the MyVec:
 * It returns a reference to the i-th element.
 * */
int& MyVec::operator[](int i) {
    return data[i];
}

void MyVec::copy(const MyVec& v2) {
    sz = v2.sz;
    // set the size equal to the v2 size
    capacity = v2.capacity;
    //setting the capacity equal
    data = new int[capacity]; //new int array of cap, cap.
    for (int i=0;i<sz;i++){
        data[i] = v2.data[i];
        // you are calling v2 data because you need to get the data from v2.. duhs.
    }
}

int copy_vector(MyVec v) {
    MyVec local_v = v;
    return local_v.size();
    //returning the size of the new vector
}

int main() {
    MyVec v = MyVec();
    for (int i = 0; i < 200; i++) {
        v.push_back(i);
        copy_vector(v);
    }
    assert(v[199] == 199);
    for (int i = 0; i < 200; i++) {
        v[i] *= 2;
    }
    assert(v[199] == 398);
    MyVec v3;
    for (int i = 9; i < 100; i += 9) {
        v3.push_back(i);
    }
    assert(v3[1] == 18);
    
    MyVec v2 = v;
    print_vector(v2);
    assert(v2 == v);
    
    v2 = v3;
    print_vector(v2);
    assert(v2 == v3);
    
    for (int i : v3) {
        assert((i % 9) == 0);
    }
    
    MyVec v4 = MyVec(10, 20);
    for (int i : v4) {
        assert(i == 20);
    }
}
