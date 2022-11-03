#include "Specialization.h"

MySpace::Specialization::Specialization() {
	cout << "constr Specialization" << endl;
	specialization = "none";
	placeOfStudy = "none";
}

MySpace::Specialization::Specialization(string specialization, string placeOfStudy)
{
	cout << "constr Specialization" << endl;
	this->specialization = specialization;
	this->placeOfStudy = placeOfStudy;
}

MySpace::Specialization::~Specialization()
{
	cout << "destr Specialization" << endl;
}

void MySpace::Specialization::setSpecialization(string specialization)
{
	this->specialization = specialization;
}

void MySpace::Specialization::setPlaceOfStudy(string placeOfStudy)
{
	this->placeOfStudy = placeOfStudy;
}

void MySpace::Specialization::showInfo()
{
	cout <<"specialization: " << specialization << ", place of study: " << placeOfStudy << endl;
}

