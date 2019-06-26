//
//  linkedList.cpp
//  Workspace
//
//  Created by Kori Vernon on 6/24/19.
//  Copyright © 2019 Kori Vernon. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 * The struct `Node`, which is the building block of our linked list code.
 * */
//The truct consists of an int and a next pointer to a nullptr
struct Node {
    Node(int d, Node* n=nullptr) : data(d), next(n) {}
    int data;
    Node* next;
};

/*
 * The various functions that can operate on our linked lists:
 * */
std::ostream& operator<<(std::ostream& os, const Node* nd);
void print_list(std::ostream& os, const Node* curr);
Node* last(Node* head);
void add_at_end(Node*& head, int d);
void add_at_front(Node*& head, int d);
bool del_head(Node*& head);
bool del_tail(Node*& head);
Node* duplicate(Node* head);
Node* reverse(Node* curr, Node* new_next=nullptr);
Node* join(Node*& list1, Node* list2);

/* Output a Node pointer. */
ostream& operator<<(ostream& os, const Node* nd) {
    if (!nd) os << "null";
    else {
        os << " data: " << nd->data << "-->";
    }
    return os;
}

/* Add a node to the end of a list. */
void add_at_end(Node*& tail, int d) {
    if (!tail) {
        tail = new Node(d,nullptr);
    }
    else {
        add_at_end(tail->next, d);
        //use recursion to go to the end and add at the end.
    }
}


/* Given the head of a list, print the whole thing. */
void print_list(ostream& os, const Node* curr) {
    os << curr;
    if (curr){
    print_list(os,curr->next);
    } else {
        os << endl;
    }
}

/* Add a node at the front of a linked list.*/
void add_at_front(Node*& head, int d) {
    head = new Node(d,head);
}


/* Get the last node of a list.*/
Node* last(Node* tail) {
    if (!tail) return nullptr;
    else if (!tail->next) return tail;
    else return last(tail->next);
}

/* Delete the first node and attach head to the 2nd node: */
bool del_head(Node*& head) {
    if (!head){
        return false;
    }
    else {
        Node* temp = head;
        head = head -> next;
        delete temp;
    }
    return true;
}

bool del_tail(Node*& curr){
    if (!curr) {
        return false;
    }
    else {
        if (curr->next == nullptr) {
            delete curr;
            curr = nullptr;
        } else {
            del_tail(curr->next);
        }
    }
    return true;
}

/* Duplicate the entire list -- you must not share memory! */
Node* duplicate(Node* head) {
    head->next = new Node(*head->next);
    return head;
}

/* Reverse the list: return a brand new list with everything reversed. */
// yeah so i dont know how to do this one! help please
Node* reverse(Node* curr, Node* new_next){
    if (curr == nullptr) return new_next;
    else {
        new_next = new Node(curr->data,new_next);
        return reverse(curr->next,new_next);
    }
}
//put list2 onto the end of list1
Node* join(Node*& list1, Node* list2) {
    last(list1)->next = list2;
    return list1;
}
/*
int main() {
    Node* head = nullptr;
    head = new Node(8, nullptr);
    add_at_end(head, 16);
    add_at_end(head, 32);
    add_at_end(head, 64);
    add_at_end(head, 128);
    add_at_end(head, 256);
    cout << "head->data: " << head->data << endl;
    assert(head->data == 8);
    
    // let's see if our last() function works:
    Node* lastp = last(head);
    cout << "Last: " << lastp << endl;
    assert(lastp->data == 256);
    
    add_at_front(head, 4);
    assert(head->data == 4);
    
    // delete the head:
    del_head(head);
    assert(head->data == 8);
    
    // delete the tail:
    del_tail(head);
    lastp = last(head);
    cout << "Last: " << lastp << endl;
    assert(lastp->data == 128);
    Node* list_of_one = new Node(1, nullptr);
    del_tail(list_of_one);
    print_list(cout, list_of_one);
    
    // check our whole list:
    cout << "head list: \n";
    print_list(cout, head);
    
    // now reverse it:
    Node* reversed = reverse(head, nullptr);
    cout << "Reversed: \n";
    print_list(cout, reversed);
    assert(reversed->data == 128);
    lastp = last(reversed);
    assert(lastp->data == 8);
    
    
    // now duplicate it:
    Node* dupe = duplicate(head);
    cout << "Duplicate: \n";
    print_list(cout, dupe);
    assert(dupe->data == 8);
    lastp = last(dupe);
    assert(lastp->data == 128);
    // now join the reversed list on to the end of the original list:
    head = join(head, reversed);
    cout << "Joined lists: \n";
    print_list(cout, head);
    lastp = last(head);
    assert(lastp->data == 8);
}
*/
