#ifndef __DISPLAY_H__
#define __DISPLAY_H__
#include "student_report_card.h"
#include <iostream>

using namespace std;
void display(string sqlstring);
static int callback(void * notused, int argc, char **argv, char **azColName);

class Display {
public:
    virtual void Operation(string sqlstring) = 0;
    virtual ~Display() { }
};

class ConcreteDisplay :public Display {
public:
    void Operation(string sqlstring) {

		display(sqlstring);
		
    }
};

class Decorator {
public:
    virtual void Operation() = 0;
    virtual void AddBehavior() = 0;
    virtual ~Decorator() { }
	string stuNo;
};

class DisplayAll :public Decorator {
public:
    DisplayAll(Display *com) {
        _com = com;
    }

    void AddBehavior() {
        cout << "Name Course Grade" << endl;
		cout << "-----------------" << endl;
    }

    void Operation() {
        AddBehavior();
		string sqlstring = "SELECT * FROM result_all";
        _com->Operation(sqlstring);
    }
private:
    Display *_com;
};

class DisplaySingle :public Decorator {
public:
	DisplaySingle(Display *com) {
		_com = com;
	}

	void AddBehavior() {
		cout << "Name Course Grade" << endl;
		cout << "-----------------" << endl;
	}

	void Operation() {
		AddBehavior();
		string sqlstring = "SELECT STUDENTS.Sname, COURSES.Cname, SC.GRADE FROM SC, COURSES, STUDENTS \
			WHERE SC.Student_ID = STUDENTS.STUDENT_ID \
			AND SC.CourseID = COURSES.CourseID \
			AND SC.Student_ID = " + stuNo;
		_com->Operation(sqlstring);
	}
private:
	Display *_com;
};
//
//int main() {
//    Display *con = new ConcreteDisplay();
//    Decorator *dec = new DisplayAll(con);
//    dec->Operation();
//
//    delete con;
//    delete dec;
//
//    return 0;
//}
#endif