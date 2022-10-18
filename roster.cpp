#include <string>
#include <sstream>
#include "roster.h"
#include "student.h"

using namespace std;

/*Parses the string array into sperate variables to be added as a student object*/
void Roster::parse(string dataRow)
{
	DegreeProgram degreeProgram = SOFTWARE;  /*Default value for degree program*/

	if (dataRow.find("SOFTWARE") != string::npos) { degreeProgram = SOFTWARE; }   /*This determines the degree type from the string recieved*/
	else if (dataRow.find("NETWORK") != string::npos) { degreeProgram = NETWORK; }
	else if (dataRow.find("SECURITY") != string::npos) { degreeProgram = SECURITY; }


	int rhs = dataRow.find(",");  /*This finds the comma, this returns the location of the comma*/
	string ID = dataRow.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = dataRow.find(",", lhs);
	string first = dataRow.substr(lhs, rhs - lhs);  /*First name*/

	lhs = rhs + 1;
	rhs = dataRow.find(",", lhs);
	string last = dataRow.substr(lhs, rhs - lhs);  /*Last name*/

	lhs = rhs + 1;
	rhs = dataRow.find(",", lhs);
	string email = dataRow.substr(lhs, rhs - lhs);  /*Email address*/

	lhs = rhs + 1;
	rhs = dataRow.find(",", lhs);
	int age = stoi(dataRow.substr(lhs, rhs - lhs));  /*Age <----- with convertion to int*/

	lhs = rhs + 1;
	rhs = dataRow.find(",", lhs);
	int classDays1 = stoi(dataRow.substr(lhs, rhs - lhs));  /*First class length <----- with converstion to int*/
	lhs = rhs + 1;
	rhs = dataRow.find(",", lhs);
	int classDays2 = stoi(dataRow.substr(lhs, rhs - lhs));  /*Second class length <----- with converstion to int*/
	lhs = rhs + 1;
	rhs = dataRow.find(",", lhs);
	int classDays3 = stoi(dataRow.substr(lhs, rhs - lhs));  /*Third class length <----- with converstion to int*/


	/*This will call the add function with the values to input values from the string into a student object!!!*/
	add(ID, first, last, email, age, classDays1, classDays2, classDays3, degreeProgram);
}

/*Adds students from the parsed data string given*/
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	/*This puts the three seperate int objects back into an array of 3*/
	int daysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	/*Now to make a new student object-----lastIndex starts with -1*/
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeProgram);
}

/*Removes a student based on ID given*/
void Roster::remove(string studentID)
{
	bool deleteComplete = false;  /*It is better to treat it as if the student is non-existent*/

	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->GetStudentId() == studentID)
		{
			deleteComplete = true;  /*Student found*/
			if (i < numStudents - 1)
			{
				Student* tempVal = classRosterArray[i];  /*Swaps the student you want to delete with that last student listed*/
				classRosterArray[i] = classRosterArray[numStudents - 1];  /*This line along with the next line does the actual switching*/
				classRosterArray[numStudents - 1] = tempVal;
			}

			Roster::lastIndex--;  /*Hides the last book so that it is no longer visable*/
		}
	}

	if (deleteComplete)
	{
		cout << "Removing " << studentID << ":" << endl;
		this->printAll();  /*Displays all of the remaining students*/
	}
	else
	{
		cout << "Removing " << studentID << " again" << endl;
		cout << endl;
		cout << "The student with the ID: " << studentID << " was not found." << endl;  /*If the user you are looking for does not exist*/
	}
}

/*Displays all of the students in the class*/
void Roster::printAll()
{
	for (int i = 0; i <= Roster::lastIndex; i++)  /*Use lastIndex for a more accurite size*/
	{
		classRosterArray[i]->PrintStudentInfo();
	}
	cout << endl;
}

/*Averages the days in the number of days array and prints them out to format*/
void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->GetStudentId() == studentID)
		{
			int daysAve = (classRosterArray[i]->GetDaysToComplete()[0] +
				classRosterArray[i]->GetDaysToComplete()[1] +
				classRosterArray[i]->GetDaysToComplete()[3]) / 3;
			std::cout << "Student ID: " << studentID << ", average days in course is: " << daysAve << endl;
		}

	}
}


/*
* Checks if there is a invald email address out of the whole list of students and prints it out if such exist
* A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
*/
void Roster::printInvalidEmails()
{
	cout << "Displaying invalid emails: " << endl;
	cout << endl;

	bool exist = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string stuID = (classRosterArray[i]->GetStudentEmail());  /*Grabs the student ID with an accesor*/
		if ((stuID.find(' ') != string::npos) || (stuID.find('@') == string::npos) || (stuID.find('.') == string::npos))  /*This tests whether the email is valid*/
		{
			exist = true;
			cout << classRosterArray[i]->GetStudentEmail() << " - is invalid" << endl;  /*Prints invalid emails*/
		}
	}
	if (!exist)
	{
		cout << "All current emails are valid. " << endl;
	}
	cout << endl;
}

/*Prints students by a spacific degree quary*/
void Roster::printByDegreeProgram(DegreeProgram dp)
{
	cout << endl;
	cout << "Showing students in degree program: " << degreeProgramString[dp] << endl;
	cout << endl;

	for (int i = 0; i <= Roster::lastIndex; i++)  /*Use lastIndex for a more accurite size*/
	{
		if (Roster::classRosterArray[i]->GetDegreeProgram() == dp)  /*Making sure it is from the Roster class*/
		{
			classRosterArray[i]->PrintStudentInfo();
		}
	}
	cout << endl;
}

Roster::~Roster()
{
	cout << endl << "DONE";

	for (int i = 0; i < numStudents; i++)
	{
		delete classRosterArray[i];			/*You have to destroy what you create and this is what does that exact thing*/
		classRosterArray[i] = nullptr;
	}
}







