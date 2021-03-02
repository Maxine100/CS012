#include "User.h"

User::User() {
	this->username = "";
	this->password = "";
}

User::User(const string& uname, const string& pass) {
	this->username = uname;
	this->password = pass;
}

string User::getUsername() const {
	return this->username;
}

bool User::check(const string& uname, const string& pass) const {
	if (uname == "") {
		return false;
	}
	if (this->username == uname && this->password == pass) {
		return true;
	}
	return false;
}

bool User::setPassword(const string& oldpass, const string& newpass) {
	if (this->username == "") {
		return false;
	}
	if (oldpass == this->password) {
		this->password == newpass;
		return true;
	}
	return false;
}