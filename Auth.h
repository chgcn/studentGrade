#ifndef __AUTH_H__
#define __AUTH_H__
#include "student_report_card.h"
#include <iostream>
using namespace std;
extern char* dbc;
static int AuthCallback(void * notused, int argc, char **argv, char **azColName);
int Auth();
int EnteringAndFetching();

class PasswordHandle {
public:
    virtual ~PasswordHandle() { }

    virtual void HandleRequest() = 0;

    void SetSuccessor(PasswordHandle *succ) {
        _succ = succ;
    }

    PasswordHandle* GetSuccessor()const {
        return _succ;
    }
	int getCount() { return wrongcount; }
	bool getState() { return passwordstate; }

	
protected:
    PasswordHandle() { _succ = nullptr; }

    PasswordHandle(PasswordHandle* succ) {
        _succ = succ;
    }
	int wrongcount = 0;
	bool passwordstate;
private:
    PasswordHandle* _succ;
	
};

class CheckPassword :public PasswordHandle {
public:
    CheckPassword() { }

    CheckPassword(PasswordHandle* succ)
        :PasswordHandle(succ) {
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

class WrongPassword :public PasswordHandle {
public:
    WrongPassword() { }

    WrongPassword(PasswordHandle* succ)
        :PasswordHandle(succ) {
    }

    void HandleRequest() {
		wrongcount++;
		cout << "Username/Password "  << wrongcount << " time(s)" << endl;
		cout << "-----------------------------------------------" << endl;
    }
	

};

#endif

