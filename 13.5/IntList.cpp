#include "IntList.h"

IntList::IntList() {
	head = 0;
	tail = 0;
}

IntList::~IntList() {

}

void IntList::display() const {
	IntNode* curr = head;
	for (curr = head; curr != 0; curr = curr->next) {
		if (curr != tail) {
			cout << curr->data << " ";
		}
		else {
			cout << curr->data;
		}
	}
}

void IntList::push_front(int value) {
	IntNode* temp = this->head;

	if (head == 0 && tail == 0) {
		head = new IntNode(value);
		(*head).next = temp;
		tail = head;
	}
	else if (head == tail && head != 0) {
		head = new IntNode(value);
		(*head).next = temp;
	}
	else {
		head = new IntNode(value);
		(*head).next = temp;
	}
}

void IntList::pop_front() {
	if (head == tail && head != 0) {
		delete head;
		head = 0;
		tail = 0;
	}
	else if (head == 0 && tail == 0) {

	}
	else {
		IntNode* temp = (*head).next;
		delete head;
		head = temp;
	}
}

bool IntList::empty() const {
	if (head == 0 && tail == 0) {
		return true;
	}
	else {
		return false;
	}
}
