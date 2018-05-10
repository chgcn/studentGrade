#include "record.h"

fstream fp;
extern Menu &menu;
extern char* dbc;


void display_single_student(string n)
{
	Display *con = new ConcreteDisplay();
	Decorator *dec = new DisplaySingle(con);
	dec->stuNo = n;
	dec->Operation();
	delete con;
	delete dec;
}

void display_all()
{
	system("cls");

	Display *con = new ConcreteDisplay();
	Decorator *dec = new DisplayAll(con);

	dec->Operation();

	delete con;
	delete dec;
	getch();
}

void insert_student_grade()
{
	system("cls");
	Modify *sub = new InsertGrade();
	CheckUserType *p = new CheckUserType(sub);
	
	p->Reuqest();
	
	delete sub;
	delete p;
	getch();
}

void modify_student_grade()
{
	system("cls");

	Modify *sub = new ModifyGrade();
	CheckUserType *p = new CheckUserType(sub);

	p->Reuqest();

	delete sub;
	delete p;

	getch();
}

void delete_student_grade()
{
	system("cls");
	
	Modify *sub = new DeleteGrade();
	CheckUserType *p = new CheckUserType(sub);

	p->Reuqest();

	delete sub;
	delete p;

	getch();
}

void insert_student() {
	system("cls");

	Modify *sub = new InsertStudent();
	CheckUserType *p = new CheckUserType(sub);

	p->Reuqest();

	delete sub;
	delete p;

	getch();
}
void insert_course() {
	system("cls");
	
	Modify *sub = new InsertCourse();
	CheckUserType *p = new CheckUserType(sub);

	p->Reuqest();

	delete sub;
	delete p;

	getch();
}

void result()
{
	int ans;
	string stuNo;
    char ch;
	menu.printResultMenu();
    cin>>ans;
    switch(ans)
    {
    case 1 :
		display_all();
        break;
    case 2 :
    {
		string seemore;
        do
        {
            system("cls");
            cout <<"Enter Student Number: ";
            cin >> stuNo;
            display_single_student(stuNo);
            cout <<"\nDo you want to See More Result (y/n)?";
            cin >> seemore;
        }
        while(seemore =="y" || seemore == "Y");
        break;
    }
    case 3:
        break;
    default:
        cout<<"\a";
    }
}