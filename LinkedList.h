#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedListInterface.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

template<typename T>
class LinkedList: public LinkedListInterface<T> {

public:
    LinkedList() {
    	head = NULL;
        length = 0;
    }
	~LinkedList() {
		cout << "The linked list deconstructor was called" << endl;
	}
	
	struct Node { //KIND OF LIKE A CLASS (BABY CLASS) CAN USE ABOVE CODE. EVERYTHING IS PUBLIC IN A STRUCT
    	T value;
    	Node *next; //integer that points to a new thing which is the same type as me
    	
    	Node(T val) {
        	value = val;
        	next = NULL;
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
            head = new Node(value);
            length++;
        }
        //case 2: otherwise
        else {
            Node *cur = head; //pointer to a Node. Local variable.
            for (int i = 0; i < length-1; i++) {
            	if (cur->next == NULL) {
            		break;
            	}
                cur = cur->next;//current pointer is now at whatever it was pointing to and pointing to the next. Eventually points to last item
            }
            cur->next = new Node(value);
            length++;
        }
	}
	void insertAfter(T value, T insertionNode) { 
		if (isDuplicate(value)) {
			return;
		}
		if (head == NULL) {
			head = new Node(value);
    		length++;
    		cout << "NULL head" << endl;
		}
		else {
			Node *cur = head;
			if (find(insertionNode) == true) {
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
			else {
				cout << "cant insert" << endl;
			}
		}
	}
	void remove(T value) {
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
			return NULL;
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
		cout << "the size" << length << endl;
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