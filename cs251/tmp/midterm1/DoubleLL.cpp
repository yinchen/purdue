#include <stdio.h>
#include <DoubleLL.h>

DoubleLL::DoubleLL() {
	head = new DoubleLLE();
	head->next = head;
	head->prev = head;
}

void
DoubleLL::insertFront(int data) {
	DoubleLLE *e = new DoubleLLE();
	e->data = data;
	e->next = head->next;
	e->prev = head;
	e->next->prev = e;
	head->next = e;
}

void
DoubleLL::insertEnd(int data) {
	DoubleLLE *e = new DoubleLLE();
	e->data = data;
	e->next = head;
	e->prev = head->prev;
	e->prev->next = e;
	head->prev = e;
}

int
DoubleLL::removeFront() {
	if (isEmpty()) {
		exit(1);
	}
	
	DoubleLLE *e;
	e = head->next;
	e->next->prev = head;
	head->next = e->next;
	
	int data = e->data;
	delete e;
	
	return data;
}

int
DoubleLL::removeEnd() {
	if (isEmpty()) {
		exit(1);
	}
	
	DoubleLLE *e;
	e = head->prev;
	e->prev->next = head;
	head->prev = e->prev;
	
	int data = e->data;
	delete e;
	
	return data;
}

bool
DoubleLL::isEmpty() {
	if (head->next == head) {
		return true;
	}
	else {
		return false;
	}
}
