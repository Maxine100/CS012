#include "User.cpp"
#include "Message.cpp"
#include "BBoard.h"

BBoard::BBoard() {
	title = "";
	userList.resize(0);
	messageList.resize(0);
}

BBoard::BBoard(const string& boardTitle) {
	title = boardTitle;
	userList.resize(0);
	messageList.resize(0);
}

bool BBoard::loadUsers(const string& filename) {
	string fileInput;
	string password2;
	ifstream inFS;
	inFS.open(filename.c_str());
	if (!inFS.is_open()) {
		return false;
	}
	
	while (inFS >> fileInput) {
		if (fileInput != "end") {
			inFS >> password2;
			userList.push_back(User(fileInput, password2));
		}
	}
	inFS.close();
	return true;
}

bool BBoard::login() {
	string username;
	string password;
	cout << "Welcome to " << title << endl;
	cout << "Enter your username ('Q' or 'q' to quit): ";
	cin >> username;
	cout << endl;
	while (username != "Q" || username != "q") {
		cout << "Enter your password: ";
		cin >> password;
		cout << endl;
		if (!userExists(username, password)) {
			cout << "Invalid Username or Password!" << endl << endl;
			cout << "Enter your username ('Q' or 'q' to quit): ";
			cin >> username;
			cout << endl;
		}
		else {
			currentUser = User(username, password);
			cout << "Welcome back " << currentUser.getUsername() << "!" << endl;
			return true;
		}
	}
	cout << "Bye!" << endl;
	return false;
}

void BBoard::run() {
	char choice;
	
	if (currentUser.getUsername() == "") {
		return;
	}
	do {
		cout << endl;
		cout << "Menu" << endl;
		cout << "- Display Message ('D' or 'd')" << endl;
		cout << "- Add New Message ('N' or 'n')" << endl;
		cout << "- Quit ('Q' or 'q')" << endl;
		cout << "Choose an action: ";
		cin >> choice;
		cout << endl;
		cin.ignore();

		if (choice == 'd' || choice == 'D') {
			display();
		}
		if (choice == 'n' || choice == 'N') {
			addMessage();
		}
	} while (choice != 'q' && choice != 'Q');
	
	cout << "Bye!" << endl;
}

void BBoard::display() const {
	string dashes = "---------------------------------------------------------";
	if (messageList.empty()) {
		cout << "Nothing to Display." << endl;
		return;
	}
	else {
		for (unsigned i = 0; i < messageList.size(); ++i) {
			cout << dashes << endl;
			cout << "Message #" << i + 1 << ": ";
			messageList.at(i).display();
		}
		cout << dashes << endl;
	}
}

void BBoard::addMessage() {
	string auth, subj, body;
	cout << "Enter Subject: ";
	getline(cin, subj);
	cout << endl;
	cout << "Enter Body: ";
	getline(cin, body);
	cout << endl;
	auth = currentUser.getUsername();

	messageList.push_back(Message(auth, subj, body));
	cout << "message Recorded!" << endl;
}

bool BBoard::userExists(const string& username, const string& password) const {
	for (unsigned int i = 0; i < userList.size(); ++i) {
		if (userList.at(i).check(username, password)) {
			return true;
		}
	}
	return false;
}