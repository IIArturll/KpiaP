#include "Department.h"

MySpace::Department::Department(){
	cout << "constr Department" << endl;
	nameOfDeparment = "noName";
}

MySpace::Department::Department(string nameOfDeparment, int workingArea)
{
	cout << "constr Department" << endl;
	if (workingArea <= 0) {
		throw exception("illegal workingArea value");
	}
	this->nameOfDeparment = nameOfDeparment;
	this->workingPlace.setWorkingArea(workingArea);
}

MySpace::Department::~Department()
{
	cout << "destr Department" << endl;
}

void MySpace::Department::setNameOfDepartment(string nameOfDepartment)
{
	this->nameOfDeparment = nameOfDepartment;
}

void MySpace::Department::setWorkingPlace(int workingArea)
{
	if (workingArea <= 0) {
		throw exception("illegal workingArea value");
	}
	this->workingPlace.setWorkingArea(workingArea);
}

void MySpace::Department::showInfo()
{
	
	cout << "nameOfDeparment: " << nameOfDeparment << endl;
	workingPlace.showInfo();
}

MySpace::Department::WorkingPlace::WorkingPlace() {
	cout << "constr WorkingPlace" << endl;
	workingArea = 0;
}
MySpace::Department::WorkingPlace::WorkingPlace(int workingArea)
{
	cout << "constr WorkingPlace" << endl;
	if (workingArea <= 0) {
		throw exception("illegal workingArea value");
	}
	this->workingArea = workingArea;
}

MySpace::Department::WorkingPlace::~WorkingPlace()
{
	cout << "destr Working Place" << endl;
}

void MySpace::Department::WorkingPlace::setWorkingArea(int workingArea)
{
	this->workingArea = workingArea;
}

void MySpace::Department::WorkingPlace::showInfo()
{
	cout << "workingArea: "<<workingArea << endl;
}
