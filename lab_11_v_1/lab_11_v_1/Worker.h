#pragma once
#include "Human.h"
#include "Department.h"
#include "Specialization.h"
#include "Post.h"
namespace MySpace {
	class Worker : public Human
	{
	private:
		int salary;
		Post post;
		Specialization specialization;
		Department department;
	public:
		Worker();
		Worker(string name, int age, int salary, string post, string specialization, string placeOfStudy, 
			string nameOfDeparment, int workingArea);
		~Worker();
		void showInfo();

	};
}
