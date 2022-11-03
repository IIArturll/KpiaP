#include "Worker.h"

MySpace::Worker::Worker()
{
	cout << "constr Worker" << endl;
	salary = 0;
}

MySpace::Worker::Worker(string name, int age, int salary, string post, string specialization, string placeOfStudy, 
	string nameOfDeparment, int workingArea) : Human(name, age)
{
	
	cout << "constr Worker" << endl;
	if (salary < 0) {
		throw exception("illegal salary value");
	}
	this->salary = salary;
	this->specialization.setSpecialization(specialization);
	this->specialization.setPlaceOfStudy(placeOfStudy);
	this->department.setNameOfDepartment(nameOfDeparment);
	this->department.setWorkingPlace(workingArea);
	this->post.setPost(post);
}

MySpace::Worker::~Worker()
{
	cout << "destr Worker" << endl;
}

void MySpace::Worker::showInfo()
{
	Human::showInfo();
	cout << "salary= " << salary << endl;
	post.showInfo();
	specialization.showInfo();
	department.showInfo();
}
