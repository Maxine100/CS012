#include "User.h"

User::User() {
	username = "";
	password = "";
}

User::User(const string& uname, const string& pass) {
	username = uname;
	password = pass;
}

string User::getUsername() const {
	return username;
}

bool User::check(const string& uname, const string& pass) const {
	if (uname == username && pass == password) {
		if (uname != "") {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

bool User::setPassword(const string& oldpass, const string& newpass) {
	if (username == "") {
		return false;
	}
	if (oldpass == password) {
		password == newpass;
		return true;
	}
	return false;
}