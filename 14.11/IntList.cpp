#include "IntList.h"

IntList::IntList() {
	this->head = 0;
}

void IntList::push_front(int value) {
	IntNode* temp = this->head;

	if (this->head == 0) {
		this->head = new IntNode(value);
		this->head->next = temp;
	}
	else {
		head = new IntNode(value);
		this->head->next = temp;
	}
}

ostream& operator<<(ostream& out, const IntList& list) {
	IntNode* curr = list.head;

	if (curr == 0) {
		return out;
	}
	return (out << curr);
}

bool IntList::exists(int value) const {
	if (exists(this->head, value)) {
		return true;
	}
	else {
		return false;
	}
}

bool IntList::exists(IntNode* node, int value) const {
	if (node == 0) {
		return false;
	}
	else if (value == node->data) {
		return true;
	}
	else {
		return exists(node->next, value);
	}
}

ostream& operator<<(ostream& out, IntNode* rhs) {
	if (rhs == 0) {
		return out;
	}
	else {
		if (rhs->next != 0) {
			out << rhs->data << " ";
		}
		else {
			out << rhs->data;
		}
		rhs = rhs->next;
		return (out << rhs);
	}
}
