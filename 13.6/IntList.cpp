#include "IntList.h"

IntList::IntList() {
	this->head = 0;
	this->tail = 0;
}

IntList::~IntList() {
	while (!empty()) {
		pop_front();
	}
}

void IntList::display() const {
	IntNode* curr = this->head;
	for (curr = this->head; curr != 0; curr = curr->next) {
		if (curr != this->tail) {
			cout << curr->data << " ";
		}
		else {
			cout << curr->data;
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
	else if (this->head == this->tail && this->head != 0) {
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
		this->head = temp;
	}
}

bool IntList::empty() const {
	if (this->head == 0 && this->tail == 0) {
		return true;
	}
	return false;
}

IntList::IntList(const IntList& cpy) {
	this->head = 0;
	this->tail = 0;
	for (IntNode* temp = cpy.head; temp != 0; temp = temp->next) {
		push_back(temp->data);
	}
	return;
}

IntList& IntList::operator=(const IntList &rhs) {
	if (&rhs == this) {
		return *this;
	}
	clear();
	for (IntNode* temp = rhs.head; temp != 0; temp = temp->next) {
		this->push_back(temp->data);
	}
	return *this;
}

void IntList::push_back(int value) {
	if (this->head == 0 && this->tail == 0) {
		this->head = new IntNode(value);
		this->head->next = 0;
		this->tail = this->head;
	}
	else if (this->head == this->tail && this->head != 0) {
		this->tail = new IntNode(value);
		this->head->next = this->tail;
	}
	else {
		IntNode* temp = new IntNode(value);
		this->tail->next = temp;
		this->tail = temp;
	}
}

void IntList::clear() {
	while (!empty()) {
		pop_front();
	}
	this->head = 0;
	this->tail = 0;
}

void IntList::selection_sort() {
	IntNode* curr = this->head;
	IntNode* curr2 = 0;
	int min;
	IntNode* index;

	if (this->head == this->tail && this->head == 0) {

	}
	else if (this->head == this->tail && this->head != 0) {

	}
	else {
		for (curr = this->head; curr != this->tail; curr = curr->next) {
			min = curr->data;
			index = curr;
			for (curr2 = curr->next; curr2 != 0; curr2 = curr2->next) {
				if (curr2->data < min) {
					min = curr2->data;
					index = curr2;
				}
			}
			index->data = curr->data;
			curr->data = min;
		}
	}
}

void IntList::insert_ordered(int value) {
	if (this->head == 0) {
		this->head = new IntNode(value);
		this->tail = this->head;
	}
	else if (this->head == this->tail) {
		IntNode* temp = new IntNode(value);
		if (temp->data > this->head->data) {
			this->head->next = temp;
			this->tail = temp;
		}
		else {
			this->head = temp;
			this->head->next = this->tail;
		}
		return;
	}
	else {
		IntNode* newValue = new IntNode(value);
		if (newValue->data < this->head->data) {
			push_front(value);
			delete newValue;
			return;
		}
		for (IntNode *curr = this->head; curr != this->tail; curr = curr->next) {
			if (newValue->data <= curr->next->data) {
				IntNode* temp = curr->next;
				curr->next = newValue;
				newValue->next = temp;
				return;
			}
		}
		this->tail->next = newValue;
		this->tail = newValue;
	}
}

void IntList::remove_duplicates() {
	if (this->head == 0) {
		return;
	}

	IntNode* curr1 = this->head;
	IntNode* curr2 = curr1->next;
	IntNode* curr3;

	for (curr1 = this->head; curr1 != this->tail && curr1 != 0; curr1 = curr1->next) {
		curr3 = curr1;
		for (curr2 = curr1->next; curr2 != 0; curr2 = curr2->next) {
			if (curr2->data == curr1->data) {
				if (curr2 == this->tail) {
					if (curr2 == this->head->next) {
						this->head->next = 0;
						delete this->tail;
						tail = this->head;
						curr2 = this->head;
					}
					else {
						this->tail = curr3;
						this->tail->next = 0;
						delete curr2;
					}
				}
				else {
					curr3->next = curr2->next;
					delete curr2;
				}
			}
			else {
				curr3 = curr3->next;
			}
		}
	}
}

ostream& operator<<(ostream &out, const IntList &rhs) {
	IntNode* curr = rhs.head;
	if (curr == 0) {

	}
	else {
		while (curr != 0) {
			if (curr->next != 0) {
				out << curr->data << " ";
			}
			if (curr->next == 0) {
				out << curr->data;
			}
			curr = curr->next;
		}
	}
	return out;
}
