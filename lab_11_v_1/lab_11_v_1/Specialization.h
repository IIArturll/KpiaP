#pragma once
#include <iostream>
#include <string>
using namespace std;
namespace MySpace {

	class Specialization
	{
	private:
		string specialization;
		string placeOfStudy;
	public:
		Specialization();
		Specialization(string specialization, string placeOfStudy);
		~Specialization();
		void setSpecialization(string specialization);
		void setPlaceOfStudy(string placeOfStudy);
		void showInfo();
	};

}
