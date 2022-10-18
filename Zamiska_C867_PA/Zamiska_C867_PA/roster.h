#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"

class Roster
{
public:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

public:
	void parse(string dataRow);  /*This method parses the data with a deliminator that is a comma*/
	void add(string studentID,	 /*The data is then passed into this method and creates a student, then it places it into the roster array*/
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();
};




#endif
