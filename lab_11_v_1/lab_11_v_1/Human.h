#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace MySpace {

	class Human {
	private:
		string name;
		int age;
	public:
		Human();
		Human(string name, int age);
		~Human();
		void showInfo();
	};
}
