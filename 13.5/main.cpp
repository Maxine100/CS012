#include <iostream>

using namespace std;

#include "IntList.cpp"

int main() {

	{
		cout << "\nlist1 constructor called" << endl;
		IntList list1;
		cout << "pushfront 10" << endl;
		list1.push_front(10);
		cout << "pushfront 20" << endl;
		list1.push_front(20);
		cout << "pushfront 30" << endl;
		list1.push_front(30);
		cout << "list1: " << flush;
		list1.display();
		cout << endl;
		cout << "pop" << endl;
		list1.pop_front();
		cout << "list1: ";
		list1.display();
		cout << endl;
		cout << "pop" << endl;
		list1.pop_front();
		cout << "list1: ";
		list1.display();
		cout << endl;
		cout << "pop" << endl;
		list1.pop_front();
		cout << "list1: ";
		list1.display();
		cout << endl;
		cout << "pushfront 100" << endl;
		list1.push_front(100);
		cout << "pushfront 200" << endl;
		list1.push_front(200);
		cout << "pushfront 300" << endl;
		list1.push_front(300);
		cout << "list1: ";
		list1.display();
		cout << endl;
	}
	cout << "list1 destructor called" << endl;

	return 0;
}
