#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>
#include <iostream>
using namespace std;


class Student
{
public:
	const static int daysToCompleteArraySize{ 3 };
private:
	string studentID;
	string studentFirstName;
	string studentLastName;
	string studentEmail;
	int studentAge;
	int daysToComplete[daysToCompleteArraySize];
	DegreeProgram studentDegreeProgram;



public:
	Student(); /*NO ARG or DEFAULT constructor*/
	Student(string studentID, string studentFirstName, string studentLastName, string studentEmail, int studentAge, int daysToComplete[], DegreeProgram studentDegreeProgram); /*Full constructor for student*/
	~Student(); /*Student class deconstructor*/

	/*Accessor declerations for Student class*/
	string GetStudentId();
	string GetStudentFirstName();
	string GetStudentLastName();
	string GetStudentEmail();
	int GetStudentAge();
	int* GetDaysToComplete();
	virtual DegreeProgram GetDegreeProgram();

	/*Mutator declerations for Student class*/
	void SetStudentId(string studentID);
	void SetStudentFirstName(string studentFirstName);
	void SetStudentLastName(string studentLastName);
	void SetStudentEmail(string studentEmail);
	void SetStudentAge(int studentAge);
	void SetDaysToComplete(int daysToComplete[]);  //REMEMBER: You can pass an array, but can not return one!
	void SetDegreeProgram(DegreeProgram degreeProgram);

	/*Decleration of student print function*/
	void PrintStudentInfo();  //Prints out this data

};


#endif