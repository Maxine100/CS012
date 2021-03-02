#include "Message.h"

Message::Message() {
	author = "";
	subject = "";
	body = "";
}

Message::Message(const string& athr, const string& sbjct, const string& body) {
	this->author = athr;
	this->subject = sbjct;
	this->body = body;
}

void Message::display() const {
	cout << this->subject << endl;
	cout << "from " << this->author << ": " << this->body << endl;
}
