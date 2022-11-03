#include <iostream>
#include "Chief.h"
using namespace std;
int main()
{
	try {
		MySpace::Worker w1 = MySpace::Worker("Stefan", 20, 800, "security", "inginer", "University", 
			"security department",5);
		cout << endl;
		w1.showInfo();
		cout << endl;
	} catch (exception ex) {
		cout << ex.what() << endl;
	}
	using namespace MySpace;
	try {
		Chief chief = Chief("Jon", 34, 2500, 2, "economist", "University", "Stuff department", 10);
		cout << endl;
		chief.showInfo();
		cout << endl;
	} catch (exception ex) {
		cout << ex.what() << endl;
	}


}

