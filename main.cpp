#include <iostream>
#include <string>
#include "student.h"
#include "roster.h"

using namespace std;

int main()
{
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Zachary,Zamiska,zzamisk@wgu.edu,27,30,30,30,SOFTWARE"
	};


	cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "Student ID: 003194341" << endl;
	cout << "Name: Zachary Zamiska" << endl;
	cout << endl;


	const int numStudents = 5;
	Roster classRoster;  /*Instatiating the class roster using the default constructor*/

	for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);

	classRoster.printAll();

	classRoster.printInvalidEmails();

	for (int i = 0; i < numStudents; i++) { classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentId()); }

	classRoster.printByDegreeProgram(SOFTWARE);

	classRoster.remove("A3");

	classRoster.remove("A3");

	cout << endl;
	system("pause");
}