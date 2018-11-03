#pragma once
#include "LinkedListInterface.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

template<typename T>
class LinkedList: public LinkedListInterface() {

public:
    LinkedList() {}
	~LinkedList() {}

	void insertHead(T value);
	void insertTail(T value);
	void insertAfter(T value, T insertionNode);
	void remove(T value);
	void clear();
	T at(int index);
	int size();
	string toString();
private:
    int length;
};