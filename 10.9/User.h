#ifndef USER_H
#define USER_H

class User {
	private:
		string username;
		string password;
	
	public:
		// Creates a user with empty name and password.
		User();

		// Create a user with given username and password.
		User(const string& uname, const string& pass);

		// Returns username.
		string getUsername() const;

		// Returns true if the stored username/password matches with the parameters.
		// Otherwise returns false. Note that, even though a User with empty name
		// and password is actually a valid User object (it is the default User),
		// this function must still return false if given an empty uname string.
		bool check(const string& uname, const string& pass) const;

		// Sets a new password. This function should only set hte new password if
		// the current (old) password is passed in. Also, a default User cannot
		// have its password changed. Returns true if password changed, false if not.
		bool setPassword(const string& oldpass, const string& newpass);
};

#endif
