#ifndef INTLIT_H
#define INTLIST_H

struct IntNode {
	int data;
	IntNode* next;
	IntNode(int data) : data(data), next(0) {}
};

class IntList {
	private:
		IntNode* head;

	public:
		// Initializes empty list.
		IntList();

		// Inserts data value to front of list.
		void push_front(int);

		// Outputs to single line all int values stored in list, each separated by a space. Function doesn't output newline or space at end.
		friend ostream& operator<<(ostream&, const IntList&);

		// Returns true if integer passed in is contained within IntList, otherwise returns false.
		bool exists(int) const;

	private:
		// Helper function that returns true if the integer passed in is contained within the IntNodes starting from the IntNode whose address is passed in, otherwise returns false
		bool exists(IntNode*, int) const;
};

// Helper function that passes in the address of a IntNode within an IntList and outputs all of integers within the IntList starting from this IntNode.
ostream& operator<<(ostream&, IntNode*);

#endif
