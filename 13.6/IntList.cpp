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

IntList::IntList(const IntList& cpy) {
	head = 0;
	tail = 0;
	for (intNode* temp = cpy.head; temp != 0; temp = temp->next) {
		push_back(temp->data);
	}
	return;
}

IntList& IntList::operator=(const IntList &rhs) {
	if (&rhs == this) {
		return *this;
	}
	clear();
	for (intNode* temp = rhs.head;temp != 0; temp = temp->next) {
		this->push_back(temp->data);
	}
	return *this;
}

void IntList::push_back(int value) {
	if (head == 0 && tail == 0) {
		head = new IntNode(value);
		(*head).next = 0;
		tail = head;
	}
	else if (head == tail && head != 0) {
		tail = new IntNode(value);
		(*head).next = tail;
	}
	else {
		IntNode* temp = new IntNode(value);
		(*tail).next = temp;
		tail = temp;
	}
}

void IntList::clear() {
	while (!empty()) {
		pop_front();
	}
	head = 0;
	tail = 0;
}

void IntList::selection_sort() {
	IntNode* curr = head;
	IntNode* curr2 = 0;
	int min;
	IntNode* index;

	if (head == tail && head == 0) {

	}
	else if (head == tail && head != 0) {

	}
	else {
		for (curr = head; curr != tail; curr = curr->next) {
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
	if (head == 0) {
		head = new IntNode(value);
		tail = head;
	}
	else if (head == tail) {
		IntNode* temp = new IntNode(value);
		if (temp->data > head->data) {
			head->next = temp;
			tail = temp;
		}
		else {
			head = temp;
			head->next = tail;
		}
		return;
	}
	else {
		IntNode* newValue = new IntNode(value);
		if (newValue->data < head->data) {
			push_front(value);
			delete newValue;
			return;
		}
		for (IntNode *curr = head; curr != tail; curr = curr->next) {
			if (newValue->data <= curr->next->data) {
				IntNode* temp = curr->next;
				curr->next = newValue;
				newValue->next = temp;
				return;
			}
		}
		tail->next = newValue;
		tail = newValue;
	}
}

void IntList::remove_duplicates() {
	if (head == 0) {
		return;
	}

	IntNode* curr1 = head;
	IntNode* curr2 = curr1->next;
	IntNode* curr3;

	for (curr1 = head; curr1 != tail && curr1 != 0; curr1 = curr1->next) {
		curr3= curr1;
		for (curr2 = curr1->next; curr2 != 0; curr2 = curr2->next) {
			if (curr2->data == curr1->data) {
				if (curr2 == tail) {
					if (curr2 == head->next) {
						head->next = 0;
						delete tail;
						tail = head;
						curr2 = head;
					}
					else {
						tail = curr3;
						tail->next = 0;
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
