#ifndef __AUTH_H__
#define __AUTH_H__
#include "student_report_card.h"
#include <iostream>
using namespace std;
extern char* dbc;
static int AuthCallback(void * notused, int argc, char **argv, char **azColName);
int Auth();
int EnteringAndFetching();

class AccountHandle {
public:
    virtual ~AccountHandle() { }

    virtual void HandleRequest() = 0;

    void SetSuccessor(AccountHandle *succ) {
        _succ = succ;
    }

    AccountHandle* GetSuccessor()const {
        return _succ;
    }

	void setCount(int count) { wrongcount = count; }
	void setState(bool state) { passwordstate = state; }
	void setUsername(string s) { username = s; }
	void setPassword(string s) { password = s; }

	int getCount() { return wrongcount; }
	bool getState() { return passwordstate; }
	string getUsername() { return username; }
	string getPassword() { return password; }
	
protected:
    AccountHandle() { _succ = nullptr; }

    AccountHandle(AccountHandle* succ) {
        _succ = succ;
    }
	int wrongcount = 0;
	bool passwordstate = false;
private:
    AccountHandle* _succ;
	string username;
	string password;
};

class CheckPassword :public AccountHandle {
public:
    CheckPassword() { }

    CheckPassword(AccountHandle* succ)
        :AccountHandle(succ) {
    }

    void HandleRequest() {

		if (!EnteringAndFetching()) {
            cout << "Password correct!" << endl;
			passwordstate = true;
        }
        else {
			if(this->GetSuccessor() != 0)
			{
				GetSuccessor()->HandleRequest();
			}
            
        }
    }
};

class WrongPassword :public AccountHandle {
public:
    WrongPassword() { }

    WrongPassword(AccountHandle* succ)
        :AccountHandle(succ) {
    }

    void HandleRequest() {
		wrongcount++;
		cout << "Username/Password "  << wrongcount << " time(s)" << endl;
		cout << "-----------------------------------------------" << endl;
    }
	

};

#endif

