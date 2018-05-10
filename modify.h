#ifndef __MODIFY_H__
#define __MODIFY_H__

#include "student_report_card.h"
#include <iostream>
int checkUserPrivilege();
int modify(string sqlstring);
using namespace std;

class Modify {
public:
    virtual void Request() = 0;
    virtual ~Modify() { }
};

class InsertGrade :public Modify {
public:
    void Request() {

		string Student_ID, CourseID, Grade;
		cout << "Inserting Student Grade...\n" ;
		cout << "Input Student_ID: ";
		cin >> Student_ID;
		cout << "Input CourseID: ";
		cin >> CourseID;
		cout << "Input Grade: ";
		cin >> Grade;
		string sqlstring = "INSERT INTO SC \
		VALUES('" + Student_ID + "', '" + CourseID + "', '" + Grade + "');";
		if (!modify(sqlstring))
		{
			cout << "Records Inserted!" << endl;
		}
    }
};

class ModifyGrade :public Modify {
public:
	void Request() {

		string Student_ID, CourseID, Grade;
		cout << "Modifying Student Grade...\n";
		cout << "Input Student_ID: ";
		cin >> Student_ID;
		cout << "Input CourseID: ";
		cin >> CourseID;
		cout << "Input Grade: ";
		cin >> Grade;
		string sqlstring = "UPDATE SC SET Grade = " + Grade + " WHERE Student_ID = " + Student_ID + " AND CourseID = " + CourseID;
		if (!modify(sqlstring))
		{
			cout << "Records Modified!" << endl;
		}
	}
};

class DeleteGrade :public Modify {
public:
	void Request() {

		string Student_ID, CourseID;
		cout << "Deleting Student Grade...\n";
		cout << "Input Student_ID: ";
		cin >> Student_ID;
		cout << "Input CourseID: ";
		cin >> CourseID;
		string sqlstring = "DELETE FROM SC WHERE Student_ID = " + Student_ID + " AND CourseID = " + CourseID;
		if (!modify(sqlstring))
		{
			cout << "Records deleted!" << endl;
		}
	}
};

class InsertStudent :public Modify {
public:
	void Request() {

		string Student_ID, Sname, Ssex, Sbirth, Nationality, ClassID;
		cout << "Inserting Student...\n";
		cout << "Input (Student_ID Sname Ssex Sbirth Nationality ClassID):";
		cin >> Student_ID >> Sname >> Ssex >> Sbirth >> Nationality >> ClassID;
		string sqlstring = "INSERT INTO STUDENTS \
		VALUES(" + Student_ID + ", '" + Sname + "', '" + Ssex + "', '" + Sbirth + "', '" + Nationality + "', " + ClassID + ");";
		cout << sqlstring << endl;
		if (!modify(sqlstring))
		{
			cout << "Student Inserted!" << endl;
		}
	}
};

class InsertCourse :public Modify {
public:
	void Request() {

		string CourseID, Cname, Credits;
		cout << "Inserting Course...\n";
		cout << "Input (CourseID Cname Credits):";
		cin >> CourseID >> Cname >> Credits;
		string sqlstring = "INSERT INTO COURSES \
		VALUES(" + CourseID + ", '" + Cname + "', '" + Credits + "')";
		cout << sqlstring << endl;
		if (!modify(sqlstring))
		{
			cout << "Course Inserted!" << endl;
		}
	}
};


class CheckUserType {
public:
	CheckUserType(Modify* Modify) {
        _sub = Modify;
    }

    void Reuqest() {
		
		if (!checkUserPrivilege())
		{
			_sub->Request();
		}
    }

private:
    Modify *_sub;
};
//判断是管理员还是学生，不然不能删改
//int main() {
//    Modify *sub = new InsertGrade();
//    CheckUserType *p = new CheckUserType(sub);
//    p->Reuqest();
//
//    delete sub;
//    delete p;
//
//    return 0;
//}
#endif