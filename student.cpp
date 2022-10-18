#include "student.h"

Student::Student()
{
	this->studentID = "";
	this->studentFirstName = "";
	this->studentLastName = "";
	this->studentEmail = "";
	this->studentAge = 0;
	for (int i = 0; i < daysToCompleteArraySize; i++) this->daysToComplete[i] = 0;
	this->studentDegreeProgram = DegreeProgram::SOFTWARE;
}

Student::Student(string studentID, string studentFirstName, string studentLastName, string studentEmail, int studentAge, int daysToComplete[], DegreeProgram studentDegreeProgram)
{
	this->studentID = studentID;
	this->studentFirstName = studentFirstName;
	this->studentLastName = studentLastName;
	this->studentEmail = studentEmail;
	this->studentAge = studentAge;
	for (int i = 0; i < 3; i++) this->daysToComplete[i] = daysToComplete[i];
	this->studentDegreeProgram = studentDegreeProgram;
}

Student::~Student() {} /*The distructor does nothing in this case*/


//  MUTATORS

void Student::SetStudentId(string studentID) { this->studentID = studentID; }
void Student::SetStudentFirstName(string studentFirstName) { this->studentFirstName = studentFirstName; }
void Student::SetStudentLastName(string studentLastName) { this->studentLastName = studentLastName; }
void Student::SetStudentEmail(string studentEmail) { this->studentEmail = studentEmail; }
void Student::SetStudentAge(int studentAge) { this->studentAge = studentAge; }
void Student::SetDaysToComplete(int daysToComplete[])
{
	for (int i = 0; i < daysToCompleteArraySize; i++)
	{
		this->daysToComplete[i] = daysToComplete[i];
	}
}
void Student::SetDegreeProgram(DegreeProgram studentDegreeProgram) { this->studentDegreeProgram = studentDegreeProgram; }

//  ACCESSORS

string Student::GetStudentId() { return this->studentID; }
string Student::GetStudentFirstName() { return this->studentFirstName; }
string Student::GetStudentLastName() { return this->studentLastName; }
string Student::GetStudentEmail() { return this->studentEmail; }
int Student::GetStudentAge() { return this->studentAge; }
int* Student::GetDaysToComplete() { return this->daysToComplete; }    /*AN ARRAY NAME IS A POINTER*/
DegreeProgram Student::GetDegreeProgram() { return this->studentDegreeProgram; }



void Student::PrintStudentInfo()
{

	cout << this->GetStudentId() << "\t";
	cout << this->GetStudentFirstName() << "\t";
	cout << this->GetStudentLastName() << "\t";
	cout << this->GetStudentAge() << "\t";
	cout << "{" << this->GetDaysToComplete()[0] << ", " << this->GetDaysToComplete()[1] << ", " << this->GetDaysToComplete()[2] << "}" << "\t";
	cout << degreeProgramString[this->GetDegreeProgram()] << "\t" << endl;

}


