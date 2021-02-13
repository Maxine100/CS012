#ifndef MESSAGE_H
#define MESSAGE_H

class Message {
	private:
		string author;
		string subject;
		string body;
	
	public:
		// Default constructor
		Message();

		// Parameterized constructor
		Message(const string& authr, const string& sbjct, const string& body);

		// Displays message in following format:
		// subject
		// from author: body
		void display() const;
};

#endif
