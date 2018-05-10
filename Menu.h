#include <iostream>
using namespace std;

class Menu {
public:
    static Menu& Instance() {
        static Menu instance;
        return instance;
    }
	void printIntro()
	{
		system("cls");
		cout << "\n\n\n\t******************";
		printf("\n\n\tStudent Grade Report");
		cout << "\n\n\t******************\n";
		cout << "\n\n\tMADE BY : Chen Hongguang\n";
		cout << "\n\n\tDept. of Software Engineering\n";
		cout << "\n\n\tChengdu University of Information Technology\n";
		
	}
	void printMainMenu()
	{
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t01. RESULT MENU";
		cout << "\n\n\t02. ENTRY/EDIT MENU";
		cout << "\n\n\t03. EXIT";
		cout << "\n\n\tPlease Select Your Option (1-3) ";
	}
	void printEntryMenu()
	{
		cout << "\n\n\n\tENTRY MENU";
		cout << "\n\n\t1.INSERT STUDENT RECORD";
		cout << "\n\n\t2.MODIFY STUDENT RECORD";
		cout << "\n\n\t3.DELETE STUDENT RECORD";
		cout << "\n\n\t4.INSERT STUDENT";
		cout << "\n\n\t5.INSERT COURSE";
		cout << "\n\n\t6.BACK TO MAIN MENU";
		cout << "\n\n\tPlease Enter Your Choice (1-6) ";
	}

	void printResultMenu()
	{
		system("cls");
		cout << "\n\n\n\tRESULT MENU";
		cout << "\n\n\t1. Print all Result\n\n\t2. Student Report Card\n\n\t3. Back to Main Menu";
		cout << "\n\n\tEnter Choice (1/2)? ";
	}
private:
    Menu() {
	}
    Menu(const Menu &another) {}
};


//int main() {
//    Menu &Menu1 = Menu::Instance();
//    Menu &Menu2 = Menu::Instance();
//    
//    cout << &Menu1 << endl;
//    cout << &Menu2 << endl;
//    
//    return 0;
//}
