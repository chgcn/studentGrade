#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "student_report_card.h"
using namespace std;

class student
{
    int rollno;
    string name;
    int p_marks,c_marks,m_marks,e_marks,cs_marks;
    float per;
    char grade;
    int std;
    void calculate()
    {
        per=(p_marks+c_marks+m_marks+e_marks+cs_marks)/5.0;
        if(per>=60)
            grade='A';
        else if(per>=50 && per<60)
            grade='B';
        else if(per>=33 && per<50)
            grade='C';
        else
            grade='F';
    }
public:
    void getdata()
    {
        cout<<"\nEnter The roll number of student ";
        cin>>rollno;
        cout<<"\n\nEnter The Name of student ";
        cin>>name;
        cout<<"\nEnter The marks in physics out of 100 : ";
        cin>>p_marks;
        cout<<"\nEnter The marks in chemistry out of 100 : ";
        cin>>c_marks;
        cout<<"\nEnter The marks in maths out of 100 : ";
        cin>>m_marks;
        cout<<"\nEnter The marks in english out of 100 : ";
        cin>>e_marks;
        cout<<"\nEnter The marks in computer science out of 100 : ";
        cin>>cs_marks;
        calculate();
    }

    void showdata()
    {
        cout<<"\nRoll number of student : "<<rollno;
        cout<<"\nName of student : "<<name;
        cout<<"\nMarks in Physics : "<<p_marks;
        cout<<"\nMarks in Chemistry : "<<c_marks;
        cout<<"\nMarks in Maths : "<<m_marks;
        cout<<"\nMarks in English : "<<e_marks;
        cout<<"\nMarks in Computer Science :"<<cs_marks;
        cout<<"\nPercentage of student is  :"<<setprecision(2)<<per;
        cout<<"\nGrade of student is :"<<grade;
    }
    void show_tabular()
    {
        cout<<rollno<<setw(12)<<name<<setw(10)<<p_marks<<setw(3)<<c_marks<<setw(3)<<m_marks<<setw(3)<<e_marks<<setw(3)<<cs_marks<<setw(6)<<setprecision(3)<<per<<"   "<<grade<<endl;
    }

    int  retrollno()
    {
        return rollno;
    }

};    

#endif