#include "LinkedList.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

LinkedList::LinkedList () {
        head = NULL;
        length = 0;
}
LinkedList::~LinkedList() {
    cout << "The linked list deconstructor was called" << endl;
}
void LinkedList::insertHead(T value) {
    
}
void LinkedList::insertTail(T value) {
    
}

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
void LinkedList::insertAfter(T value, T insertionNode) {
	while (length > 0) {
        remove(0);
    }
}

void LinkedList::remove(T value) {
	if (index >= length) {
        cout << "index out of range" << endl;
        return;
    }
    if (index == 0) { //deleting something at head
        Node *head2 = head;
        head = head->next;
        delete head2;
        length--;
    }
    else if (index == length-1) { //deleting last item
            
    }
    else { //deleting something from the middle
        Node *cur = head;
        for (int i = 0; i < index-1; i++) {
            cur = cur->next;
        }
        Node *goner = cur->next;
        cur->next = cur->next->next;
        delete goner;
        length--;
    }
}
void LinkedList::clear() {
    
}
T LinkedList::at(int index) {
	return length;
}
int LinkedList::size() {
	return length;
}
string LinkedList::toString() {
	Node *cur = head;
    while (cur != NULL) {
        cout << cur->value << " ";
        cur = cur->next;
    }
    cout << endl;
}
