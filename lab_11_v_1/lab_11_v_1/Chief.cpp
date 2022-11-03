#include "Chief.h"

MySpace::Chief::Chief()
{
	cout << "constr Chief" << endl;
}

MySpace::Chief::Chief(string name, int age, int salary, int yearOnPost, string specialization,
	string placeOfStudy, string nameOfDeparment, int workingArea):
	Worker(name, age, salary, "Chief", specialization, placeOfStudy, nameOfDeparment, workingArea)
{
	cout << "Constr Chief" << endl;
	if (yearOnPost < 0) {
		throw exception("illegal yearOnPost value");
	}
	this->yearsOnPost = yearOnPost;
}

MySpace::Chief::~Chief()
{
	cout << "destr Chief" << endl;
}

void MySpace::Chief::showInfo()
{
	Worker::showInfo();
	cout << "yearsOnPost= " << yearsOnPost << endl;
}
