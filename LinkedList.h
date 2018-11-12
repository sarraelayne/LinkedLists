#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedListInterface.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

template<typename T>
class LinkedList: public LinkedListInterface<T> {

public:
    LinkedList() {
    	head = NULL;
        length = 0;
    }
	~LinkedList() {
		clear();
		cout << "The linked list deconstructor was called" << endl;
	}
	
	struct Node { //KIND OF LIKE A CLASS (BABY CLASS) CAN USE ABOVE CODE. EVERYTHING IS PUBLIC IN A STRUCT
    	T value;
    	Node *next; //integer that points to a new thing which is the same type as me
    	
    	Node(T val, Node* n = NULL) {
        	value = val;
        	next = n;
    	}
	};
	bool isDuplicate(T value) {
		Node* duplicate = head;
		while (duplicate != NULL) {
			if (duplicate->value == value) {
				return true;
			}
			duplicate = duplicate->next;
		}
		return false;
	}
	void insertHead(T value) {
		if (isDuplicate(value)) {
			return;
		}
		if(head == NULL) {
			head = new Node(value);
			length++;
		}
		else {
			Node *beta = new Node(value);
			beta->next = head;
			head = beta;
			length++;
		}
	}
	void insertTail(T value){
		if (isDuplicate(value)) {
			return;
		}
		cout << "in insertTail" << endl;
		if (head == NULL) {
            insertHead(value);
            return;
        }
        Node *cur = head; //pointer to a Node. Local variable.
        while (cur->next != NULL) {
        	cur = cur->next;	
        }
        if (cur->next == NULL) {
        	Node* newNode = new Node(value);
        	cur->next = newNode;
        	newNode->next = NULL;
        }
	}
	void insertAfter(T value, T insertionNode) { 
		if (isDuplicate(value)) {
			return;
		}
		Node* cur = head;
		while (cur != NULL) {
	        if (cur->value == insertionNode) {
	            Node *beta = new Node(value);
				beta->next = cur->next;
				cur->next = beta;
				length++;
	        }
	    	cur = cur->next;
		}
	}
	void remove(T value) {
		Node* cur = head;
    	Node* goner = head;
		if (index >= length) {
	        return;
	    }
	    if (length == 0) {
	    	return;
	    }
	    if (head->value == value) {
	    	head = cur->next;
	    	delete cur;
	    	return;
	    }
	    while(cur->next != NULL) {
	    	if (cur->next->value == value) {
	    		goner = cur->next;
	    		cur->next = goner->next;
	    		goner->next = NULL;
	    		delete goner;
	    		return;
	    	}
	    	cur = cur->next;
	    }
	}
	void clear() {
		while(head != NULL) {
			Node* clearNode = head->next;
			delete head;
			head = clearNode;
		}
	}
	T at(int index) {
		if (index >= length || index < 0) {
			cout << "This is out of range" << endl;
			throw out_of_range("index out of range");
			return 0;
		}
		else {
			Node* atNode = head;
			int i = 0;
			while (atNode != NULL) {
				if (i == index) {
					return atNode->value;
				}
				i++;
				atNode = atNode->next;
			}
		}
	}
	int size() {
		Node* n = head;
		length = 0; 
		while (n != NULL) {
			n = n->next;
			length++;
		}
		return length;
	}
	
	string toString() {
		stringstream ss;
		Node *cur = head;
	    while (cur != NULL) {
	    	if(cur->next != NULL) {
	        ss << cur->value << " ";
	    	}
	    	else {
	    		ss << cur->value;
	    	}
	        cur = cur->next;
	    }
	    return ss.str();
	}
	bool find(T insertionNode) {
		Node *cur = head;
		while (cur != NULL) {
	        if(cur->value == insertionNode) {
				index = i;
				return true;
			}
	        cur = cur->next;
	        i++;
	    }
	}
private:
	Node *head;
    int length;
    int index;
    int i = 0;
};

#endif