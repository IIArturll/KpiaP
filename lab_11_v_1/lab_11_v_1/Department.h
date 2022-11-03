#pragma once
#include <iostream>
#include <string>

using namespace std;
namespace MySpace {
	class Department {
	public:
		Department();
		Department(string nameOfDeparment, int workingArea);
		~Department();
		void setNameOfDepartment(string nameOfDepartment);
		void setWorkingPlace(int workingArea);
		void showInfo();
		
		class WorkingPlace{
		private:
			int workingArea;
		public:
			WorkingPlace();
			WorkingPlace(int workingArea);
			~WorkingPlace();
			void setWorkingArea(int workingArea);
			void showInfo();
		};
	private:
		string nameOfDeparment;
		WorkingPlace workingPlace;
	};

}