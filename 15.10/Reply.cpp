#include "Reply.h"

Reply() {
	author = "";
	subject = "";
	body = "";
	id = 0;
}

Reply::Reply(const string& athr, const string& sbjct, const string& body, unsigned id) {
	author = athr;
	subject = sbjct;
	this->body = body;
	this->id = id;
}

bool Reply::isReply() const {
	return true;
}

string Reply::toFormattedString() const {
	string finalString = "<begin_reply>\n";
	finalString = finalString + Message::toFormattedString();
	return finalString;
}
