#include "Human.h"

MySpace::Human::Human()
{
	cout << "constr Human" << endl;
	name = "noName";
	age = 0;
}

MySpace::Human::Human(string name, int age)
{
	cout << "constr Human" << endl;
	if (age < 0) {
		throw exception("illegal age value");
	}
	this->name = name;
	this->age = age;
}

MySpace::Human::~Human()
{
	cout << "destr Human" << endl;
}

void MySpace::Human::showInfo()
{
	cout <<"name: "<< name << ", age: " << age << endl;
}
