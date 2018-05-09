#include "stdafx.h"
#include "student_report_card.h"

void gotoxy(SHORT x, SHORT y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
char* dbc;
Menu &menu = Menu::Instance();

void entry_menu()
{
    char ch2;
	menu.printEntryMenu();
    ch2=getche();
    switch(ch2)
    {
    case '1':
        system("cls");
        write_student();
        break;
    case '2':
        display_all();
        break;
    case '3':
        int num;
        system("cls");
        cout<<"\n\n\tPlease Enter The roll number ";
        cin>>num;
        display_sp(num);
        break;
    case '4':
        modify_student();
        break;
    case '5':
        delete_student();
        break;
    case '6':
        break;
    default:
        cout<<"\a";
        entry_menu();
    }
}


int main(int argc, char **argv)
{
	
	if (argc == 2)  dbc = argv[1];
	else dbc = "test.db";

	int AuthState = Auth();
	if (AuthState)
	{
		cout << "Exiting...";
		return 0;
	}
	menu.printIntro();
	getch();
	char choice;
    do
    {
		menu.printMainMenu();
		choice =getche();
        switch(choice)
        {
        case '1':
            system("cls");
            result();
            break;
        case '2':
			system("cls");
            entry_menu();
            break;
        case '3':
            exit(0);
        default :
            cout<<"\a";
        }
    }
    while(choice != '3');
    return 0;
}