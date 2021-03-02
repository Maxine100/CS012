#include "IntList.h"

IntList::IntList() {
	head = 0;
	tail = 0;
}

IntList::~IntList() {

}

void IntList::display() const {
	IntNode* curr = this->head;
	for (curr = this->head; curr != 0; curr = curr->next) {
		cout << curr->data;
		if (curr != this->tail) {
			cout << " ";
		}
	}
}

void IntList::push_front(int value) {
	IntNode* temp = this->head;

	if (this->head == 0 && this->tail == 0) {
		this->head = new IntNode(value);
		this->head->next = temp;
		this->tail = this->head;
	}
	else if (head == tail && head != 0) {
		this->head = new IntNode(value);
		this->head->next = temp;
	}
	else {
		this->head = new IntNode(value);
		this->head->next = temp;
	}
}

void IntList::pop_front() {
	if (this->head == this->tail && this->head != 0) {
		delete this->head;
		this->head = 0;
		this->tail = 0;
	}
	else if (this->head == 0 && this->tail == 0) {

	}
	else {
		IntNode* temp = this->head->next;
		delete this->head;
		this->head = this->temp;
	}
}

bool IntList::empty() const {
	if (this->head == 0 && this->tail == 0) {
		return true;
	}
	return false;
}
