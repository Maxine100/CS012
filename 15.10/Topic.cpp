#include "Message.cpp"
#include "Topic.cpp"

Topic::Topic() {
	author = "";
	subject = "";
	body = "";
	id = 0;
}

Topic::Topic(const string& athr, const string& sbjct, const string& body, unsigned id) {
	author = athr;
	subject = sbjct;
	this->body = body;
	this->id = id;
}

bool Topic::isReply() const {
	return false;
}

string Topic::toFormattedString() const {
	string finalString = "<begin_topic>\n";
	finalString = finalString + Message::toFormattedString();
	return finalString;
}
